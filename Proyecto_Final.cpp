/*
Proyecto final
*/
//para cargar imagen
#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <math.h>

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

// Tablero
Texture TableroTexture;

//////////////////////////////////////
//		Declaracion de Modelos		//
//////////////////////////////////////

Model dado8;

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

//////////////////////////////////////
//////////////////////////////////////

// Lampara
Model Lampara;

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



int main()
{
	mainWindow = Window(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	CreateObjects();
	CreateShaders();

	camera = Camera(glm::vec3(-50.0f, 60.0f, 70.0f), glm::vec3(0.0f, 1.0f, 0.0f),- 60.0f, -40.0f, 0.3f, 0.5f);

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
	Letrero = Texture("Textures/letrero.tga");
	Letrero.LoadTextureA();
	Dado4 = Texture("Textures/dado4.png");
	Dado4.LoadTextureA();


	//////////////////////////////////////
	//		Declaracion de Modelos		//
	//////////////////////////////////////

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
		0.3f, 0.3f,
		//Direccion de la luz
		0.0f, -1.0f, 0.0f);
	//contador de luces puntuales
	unsigned int pointLightCount = 0;
	//Declaración de primer luz puntual
	pointLights[0] = PointLight(1.0f, 0.0f, 0.0f,
		0.4f, 1.0f,
		-6.0f, 1.5f, 1.5f,
		0.3f, 0.2f, 0.1f);
	pointLightCount++;

	//Declaración de luz de mi lampara	
	pointLights[1] = PointLight(1.0f, 1.0f, 1.0f,	// Color blanco
		1.0f, 3.0f,					// Intensidad alta para que se note
		40.0f, 10.0f, 0.0f,			// Posicion centrada en la lampara
		0.1f, 0.1f, 0.02f);			// Atenuacion
	pointLightCount++;

	unsigned int spotLightCount = 0;
	//linterna
	spotLights[0] = SpotLight(1.0f, 1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		//Tamaño cono
		//Tama�o cono
		20.0f);
	spotLightCount++;

	//luz fija
	spotLights[1] = SpotLight(0.0f, 0.0f, 0.0f,
		1.0f, 2.0f,
		5.0f, 10.0f, 0.0f,
		0.0f, -5.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		15.0f);
	spotLightCount++;

	//luz Faro
	spotLights[2] = SpotLight(0.0f, 0.0f, 0.0f, //Color Azul
		1.0f, 2.0f,
		15.0f, 2.0f, 0.0f,		//Posicion inicial
		-5.0f, 0.0f, 0.0f,		//Direccion en -X
		1.0f, 0.0f, 0.0f,
		25.0f);
	spotLightCount++;

	//luz Helicoptero
	spotLights[3] = SpotLight(0.0f, 0.0f, 0.0f, //Color Amarillo
		1.0f, 2.0f,
		15.0f, 2.0f, 0.0f,		//Posicion inicial
		-2.0f, -5.0f, 0.0f,		//Direccion Ligeramente hacia adelante para parecer realista
		1.0f, 0.0f, 0.0f,
		25.0f);
	spotLightCount++;

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


	////Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{

		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;

		if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_T) && alternar) {
			salto = 3.5;
			srand((unsigned)time(NULL));
			c = (rand() % 5) + 1;
			srand((unsigned)time(NULL));
			c_2 = (rand() % 3) + 1;
			movDado8 = 10;
			rotDado8 = 0;
			rotDado_4 = 0;
			lastRot4 = 0;
			pasosEnTablero += (c + c_2);
			printf("avanza: %d\n", pasosEnTablero);
			alternar = false;
		}
		if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_T) == GLFW_RELEASE) {
			alternar = true;
		}

		//logica de dado
		if (salto > 0) {
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

		//Recibir eventos del usuario
		glfwPollEvents();
		camera.keyControl(mainWindow.getsKeys(), deltaTime);
		camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

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

		TableroTexture.UseTexture();
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
		model = glm::translate(model, glm::vec3(-33.0f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Cortana.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-25.0f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Inquizidor.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-16.0f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Noble6.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-7.0f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		SetoKaiba.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.0f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bakura.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(8.5f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		YugiMoto.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(17.0f, 2.7f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		DoctorOctopus.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.0f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		DuendeVerde.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, 3.2f, 35.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		DoctorStrange.RenderModel();

		//				Fauna				//

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, 1.0f, 35.0f));
		model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Guta.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, 3.2f, 33.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Yanmee.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, 3.2f, 25.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Moa.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, 1.0f, 17.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Rana.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, 2.0f, 8.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Perro.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, 3.1f, 0.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pinguino.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, 1.9f, -7.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Gato.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, -1.0f, -16.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lagarto.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, 2.1f, -24.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Paloma.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, 0.0f, -33.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Arana.RenderModel();

		//				Flora				//

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, 3.2f, -35.0f));
		model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Seta.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-33.0f, 3.2f, -35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		RobleRojo.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-25.0f, 1.6f, -35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Cerezo.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-16.0f, 1.6f, -35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Rododendro.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-8.0f, -0.9f, -32.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		JardinRosas.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.0f, -0.4f, -32.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bosque.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(8.5f, 2.7f, -33.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Islas.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(17.0f, 3.2f, -35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		KibaTorcido.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.0f, 3.2f, -35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		RobleReach.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, 1.5f, -35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Xenoflora.RenderModel();

		//			Edificios				//

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-35.0f, 3.2f, -35.0f));
		model = glm::rotate(model, -45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Anillo.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-35.0f, -0.8f, 33.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Puente.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-35.0f, 3.2f, 25.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Estatua.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-31.0f, 2.1f, 17.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Universidad.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-33.0f, 2.0f, 8.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Cafeteria.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-32.0f, 3.2f, 0.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Corporation.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-32.0f, 0.9f, -8.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Kingdom.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-35.0f, 3.2f, -16.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Instituto.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-33.0f, 3.2f, -25.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		GranCaridad.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-33.0f, -1.05f, -33.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Arca.RenderModel();

		//////////////////////////////////////
		//////////////////////////////////////


		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}
