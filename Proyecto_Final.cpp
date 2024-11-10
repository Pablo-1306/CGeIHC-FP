///*
//Proyecto Final de Computación Gráfica e Interacción Humano Computadora
//
//Hernandez Solis Brandon
//Reyes Arroyo Pablo Antonio
//
//*/
//para cargar imagen
#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <math.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
//para probar el importer
//#include<assimp/Importer.hpp>

#include "Window.h"
#include "Mesh.h"
#include "Shader_light.h"
#include "Camera.h"
#include "Texture.h"
#include "Sphere.h"
#include "Model.h"
#include "Skybox.h"

//para iluminación
#include "CommonValues.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Material.h"
const float toRadians = 3.14159265f / 180.0f;

// Para Keyframes
#include <iomanip>
#include <regex>
/////////////////

bool alternar;
int rot = 0;
float rotDado_8;
float rotDado8;
float rotDado_8Offset;
bool baja;
int c;
int c_2;
float salto;
float movDado8;
float movOffsetLet;
float rotDado4;
float rotDado_4;
float lastRot;
float lastRot4;
int pasosEnTablero;
float posXDado8 = -20.0, posYDado8 = 10.0, posZDado8 = 20.0;
bool finaliza;
bool avanza;
int posxPersonaje = -45, poszPersonaje = 45 ;
float suma;
bool v1 = false, v2 = false, v3 = true;
float despl_solx = 0.0f, despl_soly = 0.0f, despl_solz = -1.0f;
bool dia;

// Control del tablero //
int estado;


Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;

Camera camera;

Texture brickTexture;
Texture dirtTexture;
Texture plainTexture;
Texture pisoTexture;
Texture AgaveTexture;
Texture Dado4;
Texture Letrero;

Model Helicopero;
float movX;
float movZ;
float offsetMovHel;

float rotY;
float offsetRotHel;

int estado2;
float avance;
float rotObjetivo;

bool Personaje;

// Tablero
Texture TableroTexture;
Texture TableroNoche;

//////////////////////////////////////
//		Declaracion de Modelos		//
//////////////////////////////////////

Model dado8;
Model Jefe;
Model Spiderman;

//			Personajes				//

Model Cortana;
Model Inquizidor;
Model Noble6;
Model SetoKaiba;
Model Bakura;
Model YugiMoto;
Model DoctorOctopus;
Model DuendeVerde;
Model DoctorStrange;

//				Fauna				//

Model Guta;
Model Yanmee;
Model Moa;
Model Rana;
Model Perro;
Model Pinguino;
Model Gato;
Model Paloma;
Model Lagarto;
Model Arana;

//				Flora				//

Model Seta;
Model Xenoflora;
Model RobleReach;
Model KibaTorcido;
Model Islas;
Model Bosque;
Model JardinRosas;
Model Rododendro;
Model Cerezo;
Model RobleRojo;

//			Edificios				//

Model Anillo;
Model Arca;
Model GranCaridad;
Model Instituto;
Model Kingdom;
Model Corporation;
Model Cafeteria;
Model Estatua;
Model Puente;
Model Universidad;

//				Ciudad				//

Model Canon;
Model EmpireState;
Model Crucero;
Model Apartamento;
Model Edificio;
Model Scarag;
Model EstacionEspacial;
Model StarFighter;

//////////////////////////////////////
//////////////////////////////////////

Model Banshee;

//variables para keyframes
float reproduciranimacion, habilitaranimacion, guardoFrame, reinicioFrame, ciclo, ciclo2, contador = 0;

// Ruta del archivo para guardar los frames
const char* framesFilePath = "frames.txt";

//función para teclado de keyframes 
void inputKeyframes(bool* keys);

//////////////////////////////////////
//////////////////////////////////////

Skybox skybox;

//materiales
Material Material_brillante;
Material Material_opaco;

//Sphere cabeza = Sphere(0.5, 20, 20);
GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;
static double limitFPS = 1.0 / 60.0;

// luz direccional
DirectionalLight mainLight;
//para declarar varias luces de tipo pointlight
PointLight pointLights[MAX_POINT_LIGHTS];
SpotLight spotLights[MAX_SPOT_LIGHTS];

// Vertex Shader
static const char* vShader = "shaders/shader_light.vert";

// Fragment Shader
static const char* fShader = "shaders/shader_light.frag";


//función de calculo de normales por promedio de vértices 
void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
	unsigned int vLength, unsigned int normalOffset)
{
	for (size_t i = 0; i < indiceCount; i += 3)
	{
		unsigned int in0 = indices[i] * vLength;
		unsigned int in1 = indices[i + 1] * vLength;
		unsigned int in2 = indices[i + 2] * vLength;
		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
		glm::vec3 normal = glm::cross(v1, v2);
		normal = glm::normalize(normal);

		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
		vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
		vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
		vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
	}

	for (size_t i = 0; i < verticeCount / vLength; i++)
	{
		unsigned int nOffset = i * vLength + normalOffset;
		glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
		vec = glm::normalize(vec);
		vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
	}
}


void CreateObjects()
{
	unsigned int indices[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};

	GLfloat vertices[] = {
		//	x      y      z			u	  v			nx	  ny    nz
			-1.0f, -1.0f, -0.6f,	0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, -1.0f, 1.0f,		0.5f, 0.0f,		0.0f, 0.0f, 0.0f,
			1.0f, -1.0f, -0.6f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		0.0f, 0.0f, 0.0f
	};

	unsigned int floorIndices[] = {
		0, 2, 1,
		1, 2, 3
	};

	GLfloat floorVertices[] = {
		-10.0f, 0.0f, -10.0f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, -10.0f,	10.0f, 0.0f,	0.0f, -1.0f, 0.0f,
		-10.0f, 0.0f, 10.0f,	0.0f, 10.0f,	0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, 10.0f,		10.0f, 10.0f,	0.0f, -1.0f, 0.0f
	};

	unsigned int tableroIndices[] = {
	0, 2, 1,
	1, 2, 3
	};

	GLfloat tableroVertices[] = {
		-10.0f, 0.0f, -10.0f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, -10.0f,	0.0f, 1.0f,		0.0f, -1.0f, 0.0f,
		-10.0f, 0.0f, 10.0f,	1.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, 10.0f,		1.0f, 1.0f,		0.0f, -1.0f, 0.0f
	};

	unsigned int vegetacionIndices[] = {
	   0, 1, 2,
	   0, 2, 3,
	   4,5,6,
	   4,6,7
	};

	GLfloat vegetacionVertices[] = {
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,

		0.0f, -0.5f, -0.5f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, -0.5f, 0.5f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.5f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, -0.5f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,
	};

	unsigned int dado4Indices[] = {
	   0, 1, 2,
	   3, 4, 5,
	   6, 7, 8,
	   9, 10, 11
	};

	GLfloat dado4Vertices[] = {
		0.0f, 1.0f, 0.0f,		0.486f, 0.86f,		0.0f, -1.0f, 0.0f,
		0.5f, 0.0f, 0.5f,		0.698f, 0.465f,		-1.0f, 0.0f, -1.0f,
		-0.5f, 0.0f, 0.5f,		0.276f, 0.465f,		1.0f, 0.0f, -1.0f,
		//
		0.0f, 1.0f, 0.0f,		0.486f, 0.86f,		0.0f, -1.0f, 0.0f,
		-0.5f, 0.0f, 0.5f,		0.276f, 0.465f,		1.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -0.5f,		0.065f, 0.86f,			0.0f, 0.0f, 1.0f,
		//
		0.0f, 1.0f, 0.0f,		0.486f, 0.86f,		0.0f, -1.0f, 0.0f,
		0.0f, 0.0f, -0.5f,		0.905f, 0.86f,			0.0f, 0.0f, 1.0f,
		0.5f, 0.0f, 0.5f,		0.698f, 0.465f,		-1.0f, 0.0f, -1.0f,
		//
		0.0f, 0.0f, -0.5f,		0.4855f, 0.07f,			0.0f, 0.0f, 1.0f,
		0.5f, 0.0f, 0.5f,		0.698f, 0.465f,		-1.0f, 0.0f, -1.0f,
		-0.5f, 0.0f, 0.5f,		0.276f, 0.465f,			0.0f, 0.0f, 1.0f,
	};

	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj1);

	Mesh* obj2 = new Mesh();
	obj2->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj2);

	Mesh* obj3 = new Mesh();
	obj3->CreateMesh(floorVertices, floorIndices, 32, 6);
	meshList.push_back(obj3);

	Mesh* obj4 = new Mesh();
	obj4->CreateMesh(tableroVertices, tableroIndices, 32, 6);
	meshList.push_back(obj4);

	Mesh* obj5 = new Mesh();
	obj5->CreateMesh(vegetacionVertices, vegetacionIndices, 64, 12);
	meshList.push_back(obj5);

	Mesh* dado4 = new Mesh();
	dado4->CreateMesh(dado4Vertices, dado4Indices, 96, 12);
	meshList.push_back(dado4);

	calcAverageNormals(indices, 12, vertices, 32, 8, 5);

	calcAverageNormals(vegetacionIndices, 12, vegetacionVertices, 64, 8, 5);

}


void CreateShaders()
{
	Shader* shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}

///////////////////////////////KEYFRAMES/////////////////////


bool animacion = false;


//NEW// Keyframes
float posXavion = 0.0, posYavion = 20.0, posZavion = 0.0;
float movAvion_x = 0.0f, movAvion_y = 0.0f, movAvion_z = 0.0f;
float giroAvion = 0;

#define MAX_FRAMES 100
int i_max_steps = 90;
int i_curr_steps = 0;	//Se modifca en funcion de los frames que tenemos. La secuencia se crea inicializando en 0
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float movAvion_x;			//Variable para PosicionX
	float movAvion_y;			//Variable para PosicionY
	float movAvion_z;			//Variable para PosicionZ
	float movAvion_xInc;		//Variable para IncrementoX
	float movAvion_yInc;		//Variable para IncrementoY
	float movAvion_zInc;		//Variable para IncrementoZ
	float giroAvion;			//Giro para el helicoptero sobre Y
	float giroAvionInc;			//Giro para el helicoptero sobre Y
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos de cantidad de frames. La secuencia se crea inicializando en 0
bool play = false;
int playIndex = 0;

// Función para guardar los frames en el archivo
void saveFramesToFile() {
	std::ofstream outFile(framesFilePath);
	if (outFile.is_open()) {
		for (int i = 0; i < FrameIndex; ++i) {
			outFile << std::fixed << std::setprecision(1);  // Asegura un decimal para floats
			outFile << "KeyFrame[" << i << "].movAvion_x = " << KeyFrame[i].movAvion_x << "f;\n";
			outFile << "KeyFrame[" << i << "].movAvion_y = " << KeyFrame[i].movAvion_y << "f;\n";
			outFile << "KeyFrame[" << i << "].movAvion_z = " << KeyFrame[i].movAvion_z << "f;\n";
			outFile << "KeyFrame[" << i << "].giroAvion = " << KeyFrame[i].giroAvion << ";\n\n";
		}
		outFile.close();
	}
}


// Cargar frames desde archivo
void loadFramesFromFile() {
	std::ifstream inFile(framesFilePath);
	if (inFile.is_open()) {
		std::string line;
		// Reinicia el índice de frames para cargar desde el archivo
		FrameIndex = 0;

		//Expresion regular para la lectura
		std::regex regexPattern(R"(KeyFrame\[\d+\]\.(\w+) = (-?\d+\.?\d*)f?;)");

		while (std::getline(inFile, line)) {
			std::smatch match;
			if (std::regex_search(line, match, regexPattern)) {
				std::string variable = match[1];
				float value = std::stof(match[2]);

				if (variable == "movAvion_x") {
					KeyFrame[FrameIndex].movAvion_x = value;
				}
				else if (variable == "movAvion_y") {
					KeyFrame[FrameIndex].movAvion_y = value;
				}
				else if (variable == "movAvion_z") {
					KeyFrame[FrameIndex].movAvion_z = value;
				}
				else if (variable == "giroAvion") {
					KeyFrame[FrameIndex].giroAvion = value;
					// Incremente FrameIndex para leer el siguiente
					FrameIndex++;
				}
			}
			if (FrameIndex >= MAX_FRAMES) break;  // Evitar desbordamiento de frames
		}
		inFile.close();
		printf("Frames cargados exitosamente desde el archivo.");
	}
	else {
		printf("Error al abrir el archivo para lectura.");
	}
}

void saveFrame(void) //tecla L
{

	printf("frameindex %d\n", FrameIndex);

	//Esto es lo que hay que guardar en un archivo /////////////////////////

	KeyFrame[FrameIndex].movAvion_x = movAvion_x;
	KeyFrame[FrameIndex].movAvion_y = movAvion_y;
	KeyFrame[FrameIndex].movAvion_z = movAvion_z;
	KeyFrame[FrameIndex].giroAvion = giroAvion;

	FrameIndex++;

	// Guardar los frames actualizados en el archivo
	saveFramesToFile();
	printf("\nFrame guardado. Total de frames: %d\n", FrameIndex);

}

void resetElements(void) //Tecla 0
{

	movAvion_x = KeyFrame[0].movAvion_x;
	movAvion_y = KeyFrame[0].movAvion_y;
	movAvion_z = KeyFrame[0].movAvion_z;
	giroAvion = KeyFrame[0].giroAvion;
}

void interpolation(void)
{
	KeyFrame[playIndex].movAvion_xInc = (KeyFrame[playIndex + 1].movAvion_x - KeyFrame[playIndex].movAvion_x) / i_max_steps;
	KeyFrame[playIndex].movAvion_yInc = (KeyFrame[playIndex + 1].movAvion_y - KeyFrame[playIndex].movAvion_y) / i_max_steps;
	KeyFrame[playIndex].movAvion_zInc = (KeyFrame[playIndex + 1].movAvion_z - KeyFrame[playIndex].movAvion_z) / i_max_steps;
	KeyFrame[playIndex].giroAvionInc = (KeyFrame[playIndex + 1].giroAvion - KeyFrame[playIndex].giroAvion) / i_max_steps;

}


void animate(void)
{
	//Movimiento del objeto con barra espaciadora
	if (play)
	{
		if (i_curr_steps >= i_max_steps) //fin de animación entre frames?
		{
			playIndex++;
			printf("playindex : %d\n", playIndex);
			if (playIndex > FrameIndex - 2)	//Fin de toda la animación con último frame?
			{
				printf("Frame index= %d\n", FrameIndex);
				printf("termino la animacion\n");
				playIndex = 0;
				play = false;
			}
			else //Interpolación del próximo cuadro
			{

				i_curr_steps = 0; //Resetea contador
				//Interpolar
				interpolation();
			}
		}
		else
		{
			//Dibujar Animación
			movAvion_x += KeyFrame[playIndex].movAvion_xInc;
			movAvion_y += KeyFrame[playIndex].movAvion_yInc;
			movAvion_z += KeyFrame[playIndex].movAvion_zInc;
			giroAvion += KeyFrame[playIndex].giroAvionInc;
			i_curr_steps++;
		}

	}
}

///////////////* FIN KEYFRAMES*////////////////////////////


int main()
{
	mainWindow = Window(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	CreateObjects();
	CreateShaders();

	camera = Camera(glm::vec3(-50.0f, 60.0f, 70.0f), glm::vec3(0.0f, 1.0f, 0.0f),- 60.0f, -50.0f, 0.3f, 0.5f);

	// Cargar frames desde archivo
	loadFramesFromFile();

	brickTexture = Texture("Textures/brick.png");
	brickTexture.LoadTextureA();
	dirtTexture = Texture("Textures/dirt.png");
	dirtTexture.LoadTextureA();
	plainTexture = Texture("Textures/plain.png");
	plainTexture.LoadTextureA();
	pisoTexture = Texture("Textures/piso.tga");
	pisoTexture.LoadTextureA();
	TableroTexture = Texture("Textures/Tablero.tga");
	TableroTexture.LoadTextureA();
	TableroNoche= Texture("Textures/TableroNoche.tga");
	TableroNoche.LoadTextureA();
	Letrero = Texture("Textures/letrero.tga");
	Letrero.LoadTextureA();
	Dado4 = Texture("Textures/dado4.png");
	Dado4.LoadTextureA();


	Helicopero = Model();
	Helicopero.LoadModel("Models/MRX22 Recon Flyer.obj");


	//////////////////////////////////////
	//		Declaracion de Modelos		//
	//////////////////////////////////////

	Jefe = Model();
	Jefe.LoadModel("Models/Jefe.obj");

	Spiderman = Model();
	Spiderman.LoadModel("Models/Spiderman.obj");

	//			Personajes				//

	Cortana = Model();
	Cortana.LoadModel("Models/Personajes/Cortana.obj");
	Inquizidor = Model();
	Inquizidor.LoadModel("Models/Personajes/Inquizidor.obj");
	Noble6 = Model();
	Noble6.LoadModel("Models/Personajes/Noble6.obj");
	SetoKaiba = Model();
	SetoKaiba.LoadModel("Models/Personajes/SetoKaiba.obj");
	Bakura = Model();
	Bakura.LoadModel("Models/Personajes/Bakura.obj");
	YugiMoto = Model();
	YugiMoto.LoadModel("Models/Personajes/YugiMoto.obj");
	DoctorOctopus = Model();
	DoctorOctopus.LoadModel("Models/Personajes/DoctorOctopus.obj");
	DuendeVerde = Model();
	DuendeVerde.LoadModel("Models/Personajes/DuendeVerde.obj");
	DoctorStrange = Model();
	DoctorStrange.LoadModel("Models/Personajes/DoctorStrange.obj");

	//				Fauna				//

	Guta = Model();
	Guta.LoadModel("Models/Fauna/Guta.obj");
	Yanmee = Model();
	Yanmee.LoadModel("Models/Fauna/Yanmee.obj");
	Moa = Model();
	Moa.LoadModel("Models/Fauna/Moa.obj");
	Rana = Model();
	Rana.LoadModel("Models/Fauna/Rana.obj");
	Perro = Model();
	Perro.LoadModel("Models/Fauna/Perro.obj");
	Pinguino = Model();
	Pinguino.LoadModel("Models/Fauna/Pinguino.obj");
	Gato = Model();
	Gato.LoadModel("Models/Fauna/Gato.obj");
	Paloma = Model();
	Paloma.LoadModel("Models/Fauna/Paloma.obj");
	Lagarto = Model();
	Lagarto.LoadModel("Models/Fauna/Lagarto.obj");
	Arana = Model();
	Arana.LoadModel("Models/Fauna/Arana.obj");

	//				Flora				//

	Seta = Model();
	Seta.LoadModel("Models/Flora/Seta.obj");
	Xenoflora = Model();
	Xenoflora.LoadModel("Models/Flora/Xenoflora.obj");
	RobleReach = Model();
	RobleReach.LoadModel("Models/Flora/RobleReach.obj");
	KibaTorcido = Model();
	KibaTorcido.LoadModel("Models/Flora/KibaArbol.obj");
	Islas = Model();
	Islas.LoadModel("Models/Flora/Isla.obj");
	Bosque = Model();
	Bosque.LoadModel("Models/Flora/Bosque.obj");
	JardinRosas = Model();
	JardinRosas.LoadModel("Models/Flora/JardinRosas.obj");
	Rododendro = Model();
	Rododendro.LoadModel("Models/Flora/Rododendro.obj");
	Cerezo = Model();
	Cerezo.LoadModel("Models/Flora/Cerezo.obj");
	RobleRojo = Model();
	RobleRojo.LoadModel("Models/Flora/RobleRojo.obj");

	//			Edificios				//

	Anillo = Model();
	Anillo.LoadModel("Models/Edificios/Anillo.obj");
	Arca = Model();
	Arca.LoadModel("Models/Edificios/Arca.obj");
	GranCaridad = Model();
	GranCaridad.LoadModel("Models/Edificios/GranCaridad.obj");
	Instituto = Model();
	Instituto.LoadModel("Models/Edificios/InstitutoDuelos.obj");
	Corporation = Model();
	Corporation.LoadModel("Models/Edificios/Corporation.obj");
	Kingdom = Model();
	Kingdom.LoadModel("Models/Edificios/Kingdom.obj");
	Cafeteria = Model();
	Cafeteria.LoadModel("Models/Edificios/Cafe.obj");
	Puente = Model();
	Puente.LoadModel("Models/Edificios/Puente.obj");
	Universidad = Model();
	Universidad.LoadModel("Models/Edificios/Universidad.obj");
	Estatua = Model();
	Estatua.LoadModel("Models/Edificios/Estatua.obj");

	//               Ciudad				//

	Canon = Model();
	Canon.LoadModel("Models/Ciudad/CanonPlasma.obj");
	Crucero = Model();
	Crucero.LoadModel("Models/Ciudad/Crucero.obj");
	Apartamento = Model();
	Apartamento.LoadModel("Models/Ciudad/Edificio.obj");
	Edificio = Model();
	Edificio.LoadModel("Models/Ciudad/EdificioLetrero.obj");
	EmpireState = Model();
	EmpireState.LoadModel("Models/Ciudad/EmpireState.obj");
	EstacionEspacial = Model();
	EstacionEspacial.LoadModel("Models/Ciudad/EstacionEspacial.obj");
	Scarag = Model();
	Scarag.LoadModel("Models/Ciudad/Scarag.obj");
	StarFighter = Model();
	StarFighter.LoadModel("Models/Ciudad/NaveTriangular.obj");

	//               DADO                //

	dado8 = Model();
	dado8.LoadModel("Models/dado_8.obj");

	//////////////////////////////////////
	//////////////////////////////////////


	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake-night_rt.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake-night_lf.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake-night_dn.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake-night_up.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake-night_bk.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake-night_ft.tga");

	skybox = Skybox(skyboxFaces);

	Material_brillante = Material(4.0f, 256);
	Material_opaco = Material(0.3f, 4);


	//luz direccional, sólo 1 y siempre debe de existir
	mainLight = DirectionalLight(1.0f, 1.0f, 1.0f,
		//Intensidad
		0.5f, 0.5f,
		//Direccion de la luz
		0.0f, 0.0f, -1.0f);

	//contador de luces puntuales
	unsigned int pointLightCount = 0;
	//Declaración de primer luz puntual
	//pointLights[0] = PointLight(1.0f, 0.0f, 0.0f,
	//	0.4f, 1.0f,
	//	-6.0f, 1.5f, 1.5f,
	//	0.3f, 0.2f, 0.1f);
	//pointLightCount++;

	////Declaración de luz de mi lampara	
	//pointLights[1] = PointLight(1.0f, 1.0f, 1.0f,	// Color blanco
	//	1.0f, 3.0f,					// Intensidad alta para que se note
	//	40.0f, 10.0f, 0.0f,			// Posicion centrada en la lampara
	//	0.1f, 0.1f, 0.02f);			// Atenuacion
	//pointLightCount++;

	unsigned int spotLightCount = 0;
	////linterna
	//spotLights[0] = SpotLight(1.0f, 1.0f, 1.0f,
	//	0.0f, 1.0f,
	//	0.0f, 0.0f, 0.0f,
	//	0.0f, -1.0f, 0.0f,
	//	1.0f, 0.0f, 0.0f,
	//	//Tama�o cono
	//	20.0f);
	//spotLightCount++;

	////luz fija
	//spotLights[1] = SpotLight(0.0f, 0.0f, 0.0f,
	//	1.0f, 2.0f,
	//	5.0f, 10.0f, 0.0f,
	//	0.0f, -5.0f, 0.0f,
	//	1.0f, 0.0f, 0.0f,
	//	15.0f);
	//spotLightCount++;

	////luz Faro
	//spotLights[2] = SpotLight(0.0f, 0.0f, 0.0f, //Color Azul
	//	1.0f, 2.0f,
	//	15.0f, 2.0f, 0.0f,		//Posicion inicial
	//	-5.0f, 0.0f, 0.0f,		//Direccion en -X
	//	1.0f, 0.0f, 0.0f,
	//	25.0f);
	//spotLightCount++;

	////luz Helicoptero
	//spotLights[3] = SpotLight(1.0f, 1.0f, 0.0f, //Color Amarillo
	//	1.0f, 2.0f,
	//	15.0f, 2.0f, 0.0f,		//Posicion inicial
	//	-2.0f, -5.0f, 0.0f,		//Direccion Ligeramente hacia adelante para parecer realista
	//	1.0f, 0.0f, 0.0f,
	//	25.0f);
	//spotLightCount++;

	//se crean mas luces puntuales y spotlight 

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0, uniformSpecularIntensity = 0, uniformShininess = 0;
	GLuint uniformColor = 0;
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 1000.0f);

	rotDado_8 = 2.5f;
	rotDado8 = 0.0f;
	rotDado4 = 0.0f;
	baja = true;
	srand((unsigned)time(NULL));
	c = 0;
	c_2 = 0;
	salto = 0.0f;
	movDado8 = 10;
	glm::vec3 posDado8 = glm::vec3(2.0f, 0.0f, 0.0f);
	movOffsetLet = 0.9f;
	rotDado_4 = 0.0f;
	lastRot = 0.0f;
	lastRot4 = 0.0f;
	pasosEnTablero = 0;
	avanza = false;
	finaliza = true;
	suma = 0;
	v1 = false;
	v2 = v1;
	v3 = true;
	dia = true;

	// Tablero
	estado = 0;

	movX = 0.0f;
	movZ = 0.0f;
	offsetMovHel = 0.5f;

	rotY = 0.0f;
	offsetRotHel = 0.5f;

	estado2 = 0;
	rotObjetivo = 0;
	avance = 0;

	Personaje = true;

	//Cargar modelo de la nave Banshee
	Banshee = Model();
	Banshee.LoadModel("Models/Banshee.obj");

	// Informacion para la terminal sobre KeyFrames 

	printf("\nCamara Personaje: Z\nCamara Aerea: X\nCamara Monopoli: C");

	printf("\nTeclas para uso de Keyframes:\n1.-Presionar barra espaciadora para reproducir animacion.\n2.-Presionar 0 para volver a habilitar reproduccion de la animacion\n");
	printf("3.-Presiona L para guardar frame\n4.-Presiona P para habilitar guardar nuevo frame\n5.-Presiona 1 para mover en X -\n6.-Presiona 2 para habilitar mover en X -\n");
	printf("7.-Presiona 3 para mover en X +\n8.-Presiona 4 para habilitar mover en X +\n9.-Presiona 5 para mover en Y -\n10.-Presiona 6 para habilitar mover en Y -\n");
	printf("11.-Presiona 7 para mover en Y +\n12.-Presiona 8 para habilitar mover en Y +\n13.-Presiona 9 para rotar en Y \n14.-Presiona Q para habilitar rotar en Y\n");
	printf("15.-Presiona E para mover en Z -\n16.-Presiona R para habilitar mover en Z -\n17.-Presiona T para mover en Z +\n18.-Presiona Y para habilitar mover en Z +\n\n");

	// Posicion de la nave 
	glm::vec3 posBanshee = glm::vec3(0.0f, 0.0f, 0.0f);


	////Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		//luz direccional, sólo 1 y siempre debe de existir
		mainLight = DirectionalLight(1.0f, 1.0f, 1.0f,
			//Intensidad
			0.5f, 0.5f,
			//Direccion de la luz
			despl_solx, despl_soly, despl_solz);

		glfwPollEvents();

		//-------Para Keyframes
		inputKeyframes(mainWindow.getsKeys());
		animate();

		//////////////////////////////////////


		//CAMBIO DE CAMARAS//
		if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_Z)) {
			if (estado < 10) {
				camera = Camera(glm::vec3(movX, 7.0f, movZ + 15), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f+rotY, 0.0f, 0.3f, 0.5f);
			}else if (estado < 20) {
				camera = Camera(glm::vec3(movX - 15, 7.0f, movZ), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f - rotY, 0.0f, 0.3f, 0.5f);
			}else if (estado < 30) {
				camera = Camera(glm::vec3(movX, 7.0f, movZ - 15), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f + rotY, 0.0f, 0.3f, 0.5f);
			}else if (estado < 40) {
				camera = Camera(glm::vec3(movX + 15, 7.0f, movZ), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f - rotY, 0.0f, 0.3f, 0.5f);
			}
			v1 = true;
			v2 = false;
			v3 = v2;
		}
		if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_X)) {
			camera = Camera(glm::vec3(0.0f, 100.0f, 00.0f), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f, -90.0f, 0.3f, 0.5f);
			v2 = true;
			v1 = false;
			v3 = v1;
		}
		if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_C)) {
			camera = Camera(glm::vec3(-50.0f, 60.0f, 70.0f), glm::vec3(0.0f, 1.0f, 0.0f), -60.0f, -45.0f, 0.3f, 0.5f);
			v3 = true;
			v1 = false;
			v2 = v1;
		}

		if (v1) {
			//Recibir eventos del usuario
			camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());
		}
		else if (v2) {
			//Recibir eventos del usuario
			camera.keyControl(mainWindow.getsKeys(), deltaTime);
		}

		if (despl_solz < 1 && dia) {
			despl_solz += 0.0003;
			if (despl_solz > -0.7 && despl_solz < 0 && despl_soly > -1) {
				despl_soly -= 0.00002;
			}
			else if(despl_solz >= -0.000477 && despl_solz < 0.7) {
				despl_soly += 0.00002;
			}
			else if(despl_solz > 0.7 || despl_solz > -0.7){
				despl_soly = 0;
			}
		}
		else if(despl_solz > -1.1){
			dia = false;
			despl_solz -= 0.0003;
		}
		else {
			dia = true;
		}


		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;

		if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_T) && alternar && finaliza == true) {
			salto = 3.5;
			srand((unsigned)time(NULL));
			c = (rand() % 5) + 1;
			srand((unsigned)time(NULL));
			c_2 = (rand() % 3) + 1;
			movDado8 = 10;
			rotDado8 = 0;
			rotDado_4 = 0;
			lastRot4 = 0;
			pasosEnTablero = (c + c_2);
			printf("Avanza: %d\n", pasosEnTablero);
			alternar = false;

			//////////////////////////////////////
			//		Control del Tablero			//
			//////////////////////////////////////

			estado += (c + c_2);

			// Verifica si ha alcanzado o superado las 40 casillas
			if (estado >= 40) {
				estado = estado % 40;  // Reinicia el contador al rango 0-39
				Personaje = !Personaje;  // Alterna el booleano solo cuando se completa un ciclo
			}

			printf("Casilla: %d\n", estado);

		}
		if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_T) == GLFW_RELEASE) {
			alternar = true;
		}

		//logica de dado
		if (salto > 0) {
			finaliza = false;
			if (baja) {
				if (movDado8 > 0.0f) {
					movDado8 -= movOffsetLet * deltaTime;
				}
				else {
					rotDado_8 += rotDado_8Offset * deltaTime;
					rotDado_4 += rotDado_8Offset * deltaTime;
					salto -= 0.5;
					baja = false;
				}
			}
			else {
				if (movDado8 <= (salto * 2)) {
					movDado8 += movOffsetLet * deltaTime;
				}
				else {
					baja = true;
					salto -= 0.5;
					rotDado_8 += rotDado_8Offset * deltaTime;
					rotDado_4 += rotDado_8Offset * deltaTime;
				}
			}
		}
		else {
			finaliza = true;
			avanza = true;
			if (c == 1 || c == 2 || c == 5 || c == 6) {
				rotDado_8 = 2.5f;
				rotDado8 = 50;
				lastRot = 0;		//cara 2
				if (c == 6) {
					lastRot = 90;
				}
				if (c == 5) {
					lastRot = -90;
				}
				if (c == 1) {
					lastRot = 180;
				}

			}
			else if (c == 3 || c == 4 || c == 7 || c == 8) {
				rotDado_8 = 4.5f;
				rotDado8 = 126;
				lastRot = 0;			//cara 8
				if (c == 4) {
					lastRot = 90;
				}
				if (c == 3) {
					lastRot = -90;
				}
				if (c == 7) {
					lastRot = 180;
				}
			}

			if (c_2 % 2 == 0) {
				if (c_2 == 2) {
					rotDado_4 = 260;
					lastRot4 = -25;
				}
				else if (c_2 == 4) {
					rotDado_4 = 105;
					lastRot4 = 27;
				}
			}
			else {
				if (c_2 == 1) {
					rotDado_4 = 0;
					lastRot4 = 0;
				}
				else {
					rotDado_4 = 115;
					lastRot4 = -90;
				}
			}
		}


		//////////////////////////////////////
		//////////////////////////////////////


		// Clear the window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		skybox.DrawSkybox(camera.calculateViewMatrix(), projection);
		shaderList[0].UseShader();
		uniformModel = shaderList[0].GetModelLocation();
		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();
		uniformEyePosition = shaderList[0].GetEyePositionLocation();
		uniformColor = shaderList[0].getColorLocation();

		//información en el shader de intensidad especular y brillo
		uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
		uniformShininess = shaderList[0].GetShininessLocation();

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z);

		// luz ligada a la cámara de tipo flash
		//sirve para que en tiempo de ejecución (dentro del while) se cambien propiedades de la luz
		glm::vec3 lowerLight = camera.getCameraPosition();
		lowerLight.y -= 0.3f;
		spotLights[0].SetFlash(lowerLight, camera.getCameraDirection());

		//información al shader de fuentes de iluminación
		shaderList[0].SetDirectionalLight(&mainLight);
		shaderList[0].SetPointLights(pointLights, pointLightCount);
		shaderList[0].SetSpotLights(spotLights, spotLightCount);

		// Guardo la posición del personaje
		glm::vec3 PosicionPersonaje;

		//// Luz que sigue al personaje
		//pointLights[1].SetPos(Personaje);  // Actualiza la posición de la luz

		glm::mat4 model(1.0);
		glm::mat4 modelaux(1.0);
		glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);


		/////// PISO ////////

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -1.0f, 0.0f));

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -2.0f, 0.0f));
		model = glm::scale(model, glm::vec3(10.0f, 1.0f, 10.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));

		pisoTexture.UseTexture();
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);

		meshList[2]->RenderMesh();

		///// Tablero ///////

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -1.8f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (dia) {
			TableroTexture.UseTexture();
		}
		else {
			TableroNoche.UseTexture();
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);

		meshList[3]->RenderMesh();


		//Instancia del dado de 8 caras 
		model = glm::mat4(1.0);
		posDado8 = glm::vec3(posXDado8 - salto, movDado8, posZDado8);
		model = glm::translate(model, posDado8);
		model = glm::scale(model, glm::vec3(4.5f, 4.5f, 4.5f));

		model = glm::rotate(model, -90 * rotDado_8 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, float(-rotDado8 * toRadians), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, lastRot * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		dado8.RenderModel();

		//Instancia del dado de 4 caras
		model = glm::mat4(1.0);
		posDado8 = glm::vec3(posXDado8 + 5 + salto, movDado8, posZDado8 - 15);
		model = glm::translate(model, posDado8);
		model = glm::scale(model, glm::vec3(4.5f, 4.5f, 4.5f));

		model = glm::rotate(model, -90 * rotDado_8 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, float(rotDado_4 * toRadians), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, lastRot4 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Dado4.UseTexture();
		meshList[5]->RenderMesh();

		//////////////////////////////////////
		//		Renderizado de Modelos		//
		//////////////////////////////////////

		//			Personajes				//

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-33.0f, 5.0f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 39) {
			Cortana.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-25.0f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 38) {
			Inquizidor.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-16.0f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 37) {
			Noble6.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-7.0f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 36) {
			SetoKaiba.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.0f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 35) {
			Bakura.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(8.5f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 34) {
			YugiMoto.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(17.0f, 2.7f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 33) {
			DoctorOctopus.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.0f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 32) {
			DuendeVerde.RenderModel();
		}	

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 31) {
			DoctorStrange.RenderModel();
		}

		//				Fauna				//

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, 1.0f, 35.0f));
		model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 30) {
			Guta.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, 3.2f, 33.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 29) {
			Yanmee.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, 3.2f, 25.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 28) {
			Moa.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, 1.0f, 17.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 27) {
			Rana.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, 2.0f, 8.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 26) {
			Perro.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, 3.1f, 0.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 25) {
			Pinguino.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, 1.9f, -7.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 24) {
			Gato.RenderModel();
		}


		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, -1.0f, -16.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 23) {
			Lagarto.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, 2.1f, -24.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 22) {
			Paloma.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, 0.0f, -33.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 21) {
			Arana.RenderModel();
		}

		//				Flora				//

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, 3.2f, -35.0f));
		model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 20) {
			Seta.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-33.0f, 3.2f, -35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 11) {
			RobleRojo.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-25.0f, 1.6f, -35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 12) {
			Cerezo.RenderModel();
		}
		
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-16.0f, 1.6f, -35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 13) {
			Rododendro.RenderModel();
		}
		
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-8.0f, -0.9f, -32.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 14) {
			JardinRosas.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.0f, -0.4f, -32.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 15) {
			Bosque.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(8.5f, 2.7f, -33.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 16) {
			Islas.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(17.0f, 3.2f, -35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 17) {
			KibaTorcido.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.0f, 3.2f, -35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 18) {
			RobleReach.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, 1.5f, -35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 19) {
			Xenoflora.RenderModel();
		}

		//			Edificios				//

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-35.0f, 3.2f, -35.0f));
		model = glm::rotate(model, -45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 10) {
			Anillo.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-35.0f, -0.8f, 33.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 1) {
			Puente.RenderModel();
		}
		
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-35.0f, 3.2f, 25.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 2) {
			Estatua.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-31.0f, 2.1f, 17.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 3){
			Universidad.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-33.0f, 2.0f, 8.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 4) {
			Cafeteria.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-32.0f, 3.2f, 0.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 5) {
			Corporation.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-32.0f, 0.9f, -8.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 6) {
			Kingdom.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-35.0f, 3.2f, -16.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 7) {
			Instituto.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-33.0f, 3.2f, -25.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 8) {
			GranCaridad.RenderModel();
		}

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-33.0f, -1.05f, -33.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (estado == 9) {
			Arca.RenderModel();
		}

		//////////////////////////////////////

		//			Ciudad				//

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(70.0f, 25.0f, 70.0f));
		model = glm::rotate(model, -45 * toRadians, glm::vec3(0.0f, 2.0f, 0.0f));
		model = glm::scale(model, glm::vec3(40.0f, 40.0f, 40.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Canon.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-50.0f, 40.0f, 0.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(40.0f, 40.0f, 40.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Crucero.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 29.0f, -70.0f));
		model = glm::scale(model, glm::vec3(30.0f, 30.0f, 30.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-70.0f, 29.0f, -70.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(30.0f, 30.0f, 30.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Edificio.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(70.0f, 49.0f, -70.0f));
		model = glm::scale(model, glm::vec3(50.0f, 50.0f, 50.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		EmpireState.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 30.0f, 70.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(30.0f, 30.0f, 30.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		EstacionEspacial.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(70.0f, 17.0f, 0.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(40.0f, 40.0f, 40.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Scarag.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-60.0f, 25.0f, 60.0f));
		model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, -1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(30.0f, 30.0f, 30.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		StarFighter.RenderModel();

		//////////////////////////////////////
		//////////////////////////////////////

		//	Modelos

		// Halo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 3.2f, 0.0f));
		model = glm::translate(model, glm::vec3(movX, 0.0f, movZ));
		model = glm::rotate(model, rotY * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (Personaje) {
			PosicionPersonaje = glm::vec3(model[3]) + glm::vec3(0.0f, 10.0f, 0.0f);
			Jefe.RenderModel();
		}
		
		// Spiderman
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 3.2f, 0.0f));
		model = glm::translate(model, glm::vec3(movX, 0.0f, movZ));
		model = glm::rotate(model, rotY * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		if (!Personaje) {
			PosicionPersonaje = glm::vec3(model[3]) + glm::vec3(0.0f, 10.0f, 0.0f);
			Spiderman.RenderModel();
		}

		//////////////////////////////////////
		//		Control del Tablero			//
		//////////////////////////////////////

		if (estado >= 0 && estado < 10) {
			rotY = -180.0f;
			if (estado == 0) {
				movX = -45.0f;
				movZ = 45.0f;
			}
			if (estado == 1) {
				movX = -45.0f;
				movZ = 33.0f;
			}
			if (estado == 2) {
				movX = -45.0f;
				movZ = 25.0f;
			}
			if (estado == 3) {
				movX = -45.0f;
				movZ = 17.0f;
			}
			if (estado == 4) {
				movX = -45.0f;
				movZ = 8.0f;
			}
			if (estado == 5) {
				movX = -45.0f;
				movZ = 0;
			}
			if (estado == 6) {
				movX = -45.0f;
				movZ = -8.0f;
			}
			if (estado == 7) {
				movX = -45.0f;
				movZ = -17.0f;
			}
			if (estado == 8) {
				movX = -45.0f;
				movZ = -25.0f;
			}
			if (estado == 9) {
				movX = -45.0f;
				movZ = -33.0f;
			}
		}
		if (estado >= 10 && estado < 20) {
			rotY = -270.0f;
			if (estado == 10) {
				movX = -45.0f;
				movZ = -45.0f;
			}
			if (estado == 11) {
				movX = -33.0f;
				movZ = -45.0f;
			}
			if (estado == 12) {
				movX = -25.0f;
				movZ = -45.0f;
			}
			if (estado == 13) {
				movX = -17.0f;
				movZ = -45.0f;
			}
			if (estado == 14) {
				movX = -8.0f;
				movZ = -45.0f;
			}
			if (estado == 15) {
				movX = 0.0f;
				movZ = -45.0f;
			}
			if (estado == 16) {
				movX = 8.0f;
				movZ = -45.0f;
			}
			if (estado == 17) {
				movX = 17.0f;
				movZ = -45.0f;
			}
			if (estado == 18) {
				movX = 25.0f;
				movZ = -45.0f;
			}
			if (estado == 19) {
				movX = 33.0f;
				movZ = -45.0f;
			}
		}
		if (estado >= 20 && estado < 30) {
			rotY = 0.0f;
			if (estado == 20) {
				movX = 45.0f;
				movZ = -45.0f;
			}
			if (estado == 21) {
				movX = 45.0f;
				movZ = -33.0f;
			}
			if (estado == 22) {
				movX = 45.0f;
				movZ = -25.0f;
			}
			if (estado == 23) {
				movX = 45.0f;
				movZ = -17.0f;
			}
			if (estado == 24) {
				movX = 45.0f;
				movZ = -8.0f;
			}
			if (estado == 25) {
				movX = 45.0f;
				movZ = 0.0f;
			}
			if (estado == 26) {
				movX = 45.0f;
				movZ = 8.0f;
			}
			if (estado == 27) {
				movX = 45.0f;
				movZ = 17.0f;
			}
			if (estado == 28) {
				movX = 45.0f;
				movZ = 25.0f;
			}
			if (estado == 29) {
				movX = 45.0f;
				movZ = 33.0f;
			}
		}
		if (estado >= 30 && estado < 40) {
			rotY = -90.0f;
			if (estado == 30) {
				movX = 45.0f;
				movZ = 45.0f;
			}
			if (estado == 31) {
				movX = 33.0f;
				movZ = 45.0f;
			}
			if (estado == 32) {
				movX = 25.0f;
				movZ = 45.0f;
			}
			if (estado == 33) {
				movX = 17.0f;
				movZ = 45.0f;
			}
			if (estado == 34) {
				movX = 8.0f;
				movZ = 45.0f;
			}
			if (estado == 35) {
				movX = 0.0f;
				movZ = 45.0f;
			}
			if (estado == 36) {
				movX = -8.0f;
				movZ = 45.0f;
			}
			if (estado == 37) {
				movX = -17.0f;
				movZ = 45.0f;
			}
			if (estado == 38) {
				movX = -25.0f;
				movZ = 45.0f;
			}
			if (estado == 39) {
				movX = -33.0f;
				movZ = 45.0f;
			}
		}

		// Modelo para keyFrames

		model = glm::mat4(1.0);
		posBanshee = glm::vec3(posXavion + movAvion_x, posYavion + movAvion_y, posZavion + movAvion_z);
		model = glm::translate(model, posBanshee);
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		model = glm::rotate(model, giroAvion * toRadians, glm::vec3(0.0f, -1.0f, 0.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
		//color = glm::vec3(0.0f, 1.0f, 0.0f);
		//glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Banshee.RenderModel();


		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}

void inputKeyframes(bool* keys)
{
	if (keys[GLFW_KEY_SPACE])
	{
		if (reproduciranimacion < 1)
		{
			if (play == false && (FrameIndex > 1))
			{
				resetElements();
				//First Interpolation				
				interpolation();
				play = true;
				playIndex = 0;
				i_curr_steps = 0;
				reproduciranimacion++;
				printf("\n presiona 0 para habilitar reproducir de nuevo la animación'\n");
				habilitaranimacion = 0;

			}
			else
			{
				play = false;

			}
		}
	}
	if (keys[GLFW_KEY_0])
	{
		if (habilitaranimacion < 1 && reproduciranimacion>0)
		{
			printf("Ya puedes reproducir de nuevo la animación con la tecla de barra espaciadora'\n");
			reproduciranimacion = 0;
			habilitaranimacion++;

		}
	}

	if (keys[GLFW_KEY_L])
	{
		if (guardoFrame < 1)
		{
			saveFrame();
			printf("movAvion_x es: %f\n", movAvion_x);
			printf("movAvion_y es: %f\n", movAvion_y);
			printf("movAvion_z es: %f\n", movAvion_z);
			printf("rotAvion es: %f\n", giroAvion);
			printf("presiona P para habilitar guardar otro frame'\n");
			guardoFrame++;
			reinicioFrame = 0;
		}
	}
	if (keys[GLFW_KEY_P])
	{
		if (reinicioFrame < 1)
		{
			guardoFrame = 0;
			printf("Ya puedes guardar otro frame presionando la tecla L'\n");
			reinicioFrame++;
		}
	}

	// X -

	if (keys[GLFW_KEY_1])
	{
		if (ciclo < 1)
		{
			//printf("movAvion_x es: %f\n", movAvion_x);
			movAvion_x -= 5.0f;
			printf("\n movAvion_x es: %f\n", movAvion_x);
			ciclo++;
			ciclo2 = 0;
			printf("\n Presiona la tecla 2 para poder habilitar la variable\n");
		}

	}
	if (keys[GLFW_KEY_2])
	{
		if (ciclo2 < 1)
		{
			ciclo = 0;
			ciclo2++;		//Correccion para que solo entre una vez al ciclo
			printf("\n Ya puedes modificar tu variable presionando la tecla 1\n");
		}
	}

	// X +

	if (keys[GLFW_KEY_3])
	{
		if (ciclo < 1)
		{
			//printf("movAvion_x es: %f\n", movAvion_x);
			movAvion_x += 5.0f;
			printf("\n movAvion_x es: %f\n", movAvion_x);
			ciclo++;
			ciclo2 = 0;
			printf("\n Presiona la tecla 4 para poder habilitar la variable\n");
		}

	}
	if (keys[GLFW_KEY_4])
	{
		if (ciclo2 < 1)
		{
			ciclo = 0;
			ciclo2++;		//Correccion para que solo entre una vez al ciclo
			printf("\n Ya puedes modificar tu variable presionando la tecla 3\n");
		}
	}

	// Y -

	if (keys[GLFW_KEY_5])
	{
		if (ciclo < 1)
		{
			movAvion_y -= 5.0f;
			printf("\n movAvion_y es: %f\n", movAvion_y);
			ciclo++;
			ciclo2 = 0;
			printf("\n Presiona la tecla 6 para poder habilitar la variable\n");
		}

	}
	if (keys[GLFW_KEY_6])
	{
		if (ciclo2 < 1)
		{
			ciclo = 0;
			ciclo2++;		//Correccion para que solo entre una vez al ciclo
			printf("\n Ya puedes modificar tu variable presionando la tecla 5\n");
		}
	}

	// Y +

	if (keys[GLFW_KEY_7])
	{
		if (ciclo < 1)
		{
			movAvion_y += 5.0f;
			printf("\n movAvion_y es: %f\n", movAvion_y);
			ciclo++;
			ciclo2 = 0;
			printf("\n Presiona la tecla 6 para poder habilitar la variable\n");
		}

	}
	if (keys[GLFW_KEY_8])
	{
		if (ciclo2 < 1)
		{
			ciclo = 0;
			ciclo2++;		//Correccion para que solo entre una vez al ciclo
			printf("\n Ya puedes modificar tu variable presionando la tecla 7\n");
		}
	}

	//Rotacion

	if (keys[GLFW_KEY_9])
	{
		if (ciclo < 1)
		{
			//printf("movAvion_x es: %f\n", movAvion_x);
			giroAvion += 15.0f;
			printf("\n rotAvion es: %f\n", giroAvion);
			ciclo++;
			ciclo2 = 0;
			printf("\n Presiona la tecla Q para poder habilitar la variable\n");
		}

	}
	if (keys[GLFW_KEY_Q])
	{
		if (ciclo2 < 1)
		{
			ciclo = 0;
			ciclo2++;		//Correccion para que solo entre una vez al ciclo
			printf("\n Ya puedes modificar tu variable presionando la tecla 9\n");
		}
	}

	// Z -

	if (keys[GLFW_KEY_E])
	{
		if (ciclo < 1)
		{
			movAvion_z -= 5.0f;
			printf("\n movAvion_z es: %f\n", movAvion_z);
			ciclo++;
			ciclo2 = 0;
			printf("\n Presiona la tecla R para poder habilitar la variable\n");
		}

	}
	if (keys[GLFW_KEY_R])
	{
		if (ciclo2 < 1)
		{
			ciclo = 0;
			ciclo2++;		//Correccion para que solo entre una vez al ciclo
			printf("\n Ya puedes modificar tu variable presionando la tecla E\n");
		}
	}

	// Z +

	if (keys[GLFW_KEY_T])
	{
		if (ciclo < 1)
		{
			movAvion_z += 5.0f;
			printf("\n movAvion_z es: %f\n", movAvion_z);
			ciclo++;
			ciclo2 = 0;
			printf("\n Presiona la tecla Y para poder habilitar la variable\n");
		}

	}
	if (keys[GLFW_KEY_Y])
	{
		if (ciclo2 < 1)
		{
			ciclo = 0;
			ciclo2++;		//Correccion para que solo entre una vez al ciclo
			printf("\n Ya puedes modificar tu variable presionando la tecla T\n");
		}
	}

}