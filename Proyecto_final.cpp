///*
//Proyecto Final de Computación Gráfica e Interacción Humano Computadora
//
//Hernandez Solis Brandon
//Reyes Arroyo Pablo Antonio
//
//*/
//para cargar imagen
#define STB_IMAGE_IMPLEMENTATION
#define MINIAUDIO_IMPLEMENTATION
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
#include <miniaudio.h>

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
int posxPersonaje = -45, poszPersonaje = 45;
float suma;
bool v1 = false, v2 = false, v3 = true;
float despl_solx = 0.0f, despl_soly = 0.0f, despl_solz = -1.0f;
bool dia;
unsigned int val;

// Control del tablero //
int estado;
bool Animacion;
int pasosx;
int pasosz;

//Tiempo
float tiempoAcumulado;
float tIni;
float tFin;

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

//////////////////////////////////////
//		Declaracion de Texturas		//
//////////////////////////////////////

Texture TableroTexture;

Texture TableroDia;
Texture TableroNoche;

Texture DiaCasilla_00;
Texture NocheCasilla_00;
Texture SelecCasilla_00;
Texture DiaCasilla_01;
Texture NocheCasilla_01;
Texture SelecCasilla_01;
Texture DiaCasilla_02;
Texture NocheCasilla_02;
Texture SelecCasilla_02;
Texture DiaCasilla_03;
Texture NocheCasilla_03;
Texture SelecCasilla_03;
Texture DiaCasilla_04;
Texture NocheCasilla_04;
Texture SelecCasilla_04;
Texture DiaCasilla_05;
Texture NocheCasilla_05;
Texture SelecCasilla_05;
Texture DiaCasilla_06;
Texture NocheCasilla_06;
Texture SelecCasilla_06;
Texture DiaCasilla_07;
Texture NocheCasilla_07;
Texture SelecCasilla_07;
Texture DiaCasilla_08;
Texture NocheCasilla_08;
Texture SelecCasilla_08;
Texture DiaCasilla_09;
Texture NocheCasilla_09;
Texture SelecCasilla_09;
//////////////////////////////////////
Texture DiaCasilla_10;
Texture NocheCasilla_10;
Texture SelecCasilla_10;
Texture DiaCasilla_11;
Texture NocheCasilla_11;
Texture SelecCasilla_11;
Texture DiaCasilla_12;
Texture NocheCasilla_12;
Texture SelecCasilla_12;
Texture DiaCasilla_13;
Texture NocheCasilla_13;
Texture SelecCasilla_13;
Texture DiaCasilla_14;
Texture NocheCasilla_14;
Texture SelecCasilla_14;
Texture DiaCasilla_15;
Texture NocheCasilla_15;
Texture SelecCasilla_15;
Texture DiaCasilla_16;
Texture NocheCasilla_16;
Texture SelecCasilla_16;
Texture DiaCasilla_17;
Texture NocheCasilla_17;
Texture SelecCasilla_17;
Texture DiaCasilla_18;
Texture NocheCasilla_18;
Texture SelecCasilla_18;
Texture DiaCasilla_19;
Texture NocheCasilla_19;
Texture SelecCasilla_19;
//////////////////////////////////////
Texture DiaCasilla_20;
Texture NocheCasilla_20;
Texture SelecCasilla_20;
Texture DiaCasilla_21;
Texture NocheCasilla_21;
Texture SelecCasilla_21;
Texture DiaCasilla_22;
Texture NocheCasilla_22;
Texture SelecCasilla_22;
Texture DiaCasilla_23;
Texture NocheCasilla_23;
Texture SelecCasilla_23;
Texture DiaCasilla_24;
Texture NocheCasilla_24;
Texture SelecCasilla_24;
Texture DiaCasilla_25;
Texture NocheCasilla_25;
Texture SelecCasilla_25;
Texture DiaCasilla_26;
Texture NocheCasilla_26;
Texture SelecCasilla_26;
Texture DiaCasilla_27;
Texture NocheCasilla_27;
Texture SelecCasilla_27;
Texture DiaCasilla_28;
Texture NocheCasilla_28;
Texture SelecCasilla_28;
Texture DiaCasilla_29;
Texture NocheCasilla_29;
Texture SelecCasilla_29;
//////////////////////////////////////
Texture DiaCasilla_30;
Texture NocheCasilla_30;
Texture SelecCasilla_30;
Texture DiaCasilla_31;
Texture NocheCasilla_31;
Texture SelecCasilla_31;
Texture DiaCasilla_32;
Texture NocheCasilla_32;
Texture SelecCasilla_32;
Texture DiaCasilla_33;
Texture NocheCasilla_33;
Texture SelecCasilla_33;
Texture DiaCasilla_34;
Texture NocheCasilla_34;
Texture SelecCasilla_34;
Texture DiaCasilla_35;
Texture NocheCasilla_35;
Texture SelecCasilla_35;
Texture DiaCasilla_36;
Texture NocheCasilla_36;
Texture SelecCasilla_36;
Texture DiaCasilla_37;
Texture NocheCasilla_37;
Texture SelecCasilla_37;
Texture DiaCasilla_38;
Texture NocheCasilla_38;
Texture SelecCasilla_38;
Texture DiaCasilla_39;
Texture NocheCasilla_39;
Texture SelecCasilla_39;

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

	unsigned int casillaIndices[] = {
	0, 2, 1,
	1, 2, 3
	};

	GLfloat casillaVertices[] = {
		-6.5f, 0.0f, -4.2f,		0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		6.5f, 0.0f, -4.2f,		0.0f, 1.0f,		0.0f, -1.0f, 0.0f,
		-6.5f, 0.0f, 4.2f,		1.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		6.5f, 0.0f, 4.2f,		1.0f, 1.0f,		0.0f, -1.0f, 0.0f
	};

	unsigned int esquinaIndices[] = {
	0, 2, 1,
	1, 2, 3
	};

	GLfloat esquinaVertices[] = {
		-6.5f, 0.0f, -6.5f,		0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		6.5f, 0.0f, -6.5f,		0.0f, 1.0f,		0.0f, -1.0f, 0.0f,
		-6.5f, 0.0f, 6.5f,		1.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		6.5f, 0.0f, 6.5f,		1.0f, 1.0f,		0.0f, -1.0f, 0.0f
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

	Mesh* obj6 = new Mesh();
	obj6->CreateMesh(casillaVertices, casillaIndices, 32, 6);
	meshList.push_back(obj6);

	Mesh* obj7 = new Mesh();
	obj7->CreateMesh(esquinaVertices, esquinaIndices, 32, 6);
	meshList.push_back(obj7);

	calcAverageNormals(indices, 12, vertices, 32, 8, 5);

	calcAverageNormals(vegetacionIndices, 12, vegetacionVertices, 64, 8, 5);

}


void CreateShaders()
{
	Shader* shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}

// Variables antes del main: TiempoInicio = TiempoTranscurrido, TiempoFin = TiempoTranscurrido + 8 seg
// Animacion Avanzada
float MovimientoAvanzado(float tIni, float tiempoAcumulado) {
	// Parametros de tiempo
	float tiempoTranscurrido = tiempoAcumulado - tIni;

	// Parametros de ajuste
	float maxValue = 10.0f; 		// Altura Maxima
	float velSubida = 5.0f;		// Velocidad de cambio
	float velBajada = -5.0f;
	float centroSubida = 1.0f;	// Centrado de la curva = #/2
	float centroBajada = 6.0f;

	float movimiento = 0.0f;

	// Control de tiempo
	if (tiempoTranscurrido < 3.5f) {
		//Subir
		movimiento = maxValue * (1.0f / (1.0f + exp(-velSubida * (tiempoTranscurrido - (centroSubida)))));
		//printf("SMovimiento: %f ", movimiento);
	}
	else if (tiempoTranscurrido >= 3.5f && tiempoTranscurrido < 9) {
		//Bajar
		movimiento = maxValue * (1.0f / (1.0f + exp(-velBajada * (tiempoTranscurrido - (centroBajada)))));
		//printf("BMovimiento: %f ", movimiento);
	}

	// Retornar el valor calculado que oscila entre 0 y 10
	return movimiento;
}

float RotacionAvanzada(float tIni, float tiempoAcumulado) {
	// Parametros de tiempo
	float tiempoTranscurrido = tiempoAcumulado - tIni;

	//printf("tAnimando: %f, ", tiempoTranscurrido);

	// Parametros de ajuste
	float maxValue = 3.6f; 		// Altura Maxima
	float velSubida = 5.0f;		// Velocidad de cambio
	float velBajada = -5.0f;
	float centroSubida = 1.0f;	// Centrado de la curva = #/2
	float centroBajada = 6.0f;

	float rotacion = 0.0f;

	// Control de tiempo
	if (tiempoTranscurrido < 3.5f) {
		//Subir
		rotacion = maxValue * (1.0f / (1.0f + exp(-velSubida * (tiempoTranscurrido - (centroSubida)))));
	}
	else if (tiempoTranscurrido >= 3.5f && tiempoTranscurrido < 9) {
		//Bajar
		rotacion = maxValue * (1.0f / (1.0f + exp(-velBajada * (tiempoTranscurrido - (centroBajada)))));
	}

	rotacion *= 100;

	// Retornar el valor calculado que oscila entre 0 y 10
	return rotacion * toRadians;
}

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
	ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
	if (pDecoder == NULL) {
		return;
	}

	/* Reading PCM frames will loop based on what we specified when called ma_data_source_set_looping(). */
	ma_data_source_read_pcm_frames(pDecoder, pOutput, frameCount, NULL);

	(void)pInput;
}

// Función para calcular la distancia entre dos puntos en 3D
float calculateDistance(float x1, float y1, float z1, float x2, float y2, float z2) {
	return std::sqrt((x2 - x1) * (x2 - x1) +
		(y2 - y1) * (y2 - y1) +
		(z2 - z1) * (z2 - z1));
}


int main()
{
	mainWindow = Window(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	CreateObjects();
	CreateShaders();

	camera = Camera(glm::vec3(-50.0f, 60.0f, 70.0f), glm::vec3(0.0f, 1.0f, 0.0f),- 50.0f, -46.0f, 0.3f, 0.5f);

	////generar el soundtrack 
	
	// Inicializar el motor de audio miniaudio
	// Configurar el motor de audio con soporte 3D
	ma_engine_config engineConfig = ma_engine_config_init();
	engineConfig.listenerCount = 1; // Habilitar un oyente
	ma_engine engine;
	if (ma_engine_init(&engineConfig, &engine) != MA_SUCCESS) {
		std::cerr << "Error al inicializar miniaudio" << std::endl;
		return -1;
	}

	// Cargar el soundtrack (audio continuo)
	ma_sound soundtrack;
	if (ma_sound_init_from_file(&engine, "HALO.mp3", MA_SOUND_FLAG_STREAM, nullptr, nullptr, &soundtrack) != MA_SUCCESS) {
		std::cerr << "Error al cargar el soundtrack" << std::endl;
		ma_engine_uninit(&engine);
		return -1;
	}
	ma_sound_set_looping(&soundtrack, MA_TRUE); // Loop infinito del soundtrack
	ma_sound_start(&soundtrack);


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
	TableroNoche = Texture("Textures/TableroNoche.tga");
	TableroNoche.LoadTextureA();
	Letrero = Texture("Textures/letrero.tga");
	Letrero.LoadTextureA();
	Dado4 = Texture("Textures/dado4.png");
	Dado4.LoadTextureA();

	//////////////////////////////////////
	//		Declaracion de Texturas		//
	//////////////////////////////////////

	//			Referencia				//

	TableroTexture = Texture("Textures/Tablero.tga");
	TableroTexture.LoadTextureA();

	//				Centro				//

	TableroDia = Texture("Textures/Tablero/Imagen/Dia.png");
	TableroDia.LoadTextureA();
	TableroNoche = Texture("Textures/Tablero/Imagen/Noche.png");
	TableroNoche.LoadTextureA();

	//			Edificios				//
	DiaCasilla_00 = Texture("Textures/Tablero/Casilla00/Dia.png");
	DiaCasilla_00.LoadTextureA();
	NocheCasilla_00 = Texture("Textures/Tablero/Casilla00/Noche.png");
	NocheCasilla_00.LoadTextureA();
	SelecCasilla_00 = Texture("Textures/Tablero/Casilla00/Seleccionado.png");
	SelecCasilla_00.LoadTextureA();

	DiaCasilla_01 = Texture("Textures/Tablero/Casilla01/Dia.png");
	DiaCasilla_01.LoadTextureA();
	NocheCasilla_01 = Texture("Textures/Tablero/Casilla01/Noche.png");
	NocheCasilla_01.LoadTextureA();
	SelecCasilla_01 = Texture("Textures/Tablero/Casilla01/Seleccionado.png");
	SelecCasilla_01.LoadTextureA();

	DiaCasilla_02 = Texture("Textures/Tablero/Casilla02/Dia.png");
	DiaCasilla_02.LoadTextureA();
	NocheCasilla_02 = Texture("Textures/Tablero/Casilla02/Noche.png");
	NocheCasilla_02.LoadTextureA();
	SelecCasilla_02 = Texture("Textures/Tablero/Casilla02/Seleccionado.png");
	SelecCasilla_02.LoadTextureA();

	DiaCasilla_03 = Texture("Textures/Tablero/Casilla03/Dia.png");
	DiaCasilla_03.LoadTextureA();
	NocheCasilla_03 = Texture("Textures/Tablero/Casilla03/Noche.png");
	NocheCasilla_03.LoadTextureA();
	SelecCasilla_03 = Texture("Textures/Tablero/Casilla03/Seleccionado.png");
	SelecCasilla_03.LoadTextureA();

	DiaCasilla_04 = Texture("Textures/Tablero/Casilla04/Dia.png");
	DiaCasilla_04.LoadTextureA();
	NocheCasilla_04 = Texture("Textures/Tablero/Casilla04/Noche.png");
	NocheCasilla_04.LoadTextureA();
	SelecCasilla_04 = Texture("Textures/Tablero/Casilla04/Seleccionado.png");
	SelecCasilla_04.LoadTextureA();

	DiaCasilla_05 = Texture("Textures/Tablero/Casilla05/Dia.png");
	DiaCasilla_05.LoadTextureA();
	NocheCasilla_05 = Texture("Textures/Tablero/Casilla05/Noche.png");
	NocheCasilla_05.LoadTextureA();
	SelecCasilla_05 = Texture("Textures/Tablero/Casilla05/Seleccionado.png");
	SelecCasilla_05.LoadTextureA();

	DiaCasilla_06 = Texture("Textures/Tablero/Casilla06/Dia.png");
	DiaCasilla_06.LoadTextureA();
	NocheCasilla_06 = Texture("Textures/Tablero/Casilla06/Noche.png");
	NocheCasilla_06.LoadTextureA();
	SelecCasilla_06 = Texture("Textures/Tablero/Casilla06/Seleccionado.png");
	SelecCasilla_06.LoadTextureA();

	DiaCasilla_07 = Texture("Textures/Tablero/Casilla07/Dia.png");
	DiaCasilla_07.LoadTextureA();
	NocheCasilla_07 = Texture("Textures/Tablero/Casilla07/Noche.png");
	NocheCasilla_07.LoadTextureA();
	SelecCasilla_07 = Texture("Textures/Tablero/Casilla07/Seleccionado.png");
	SelecCasilla_07.LoadTextureA();

	DiaCasilla_08 = Texture("Textures/Tablero/Casilla08/Dia.png");
	DiaCasilla_08.LoadTextureA();
	NocheCasilla_08 = Texture("Textures/Tablero/Casilla08/Noche.png");
	NocheCasilla_08.LoadTextureA();
	SelecCasilla_08 = Texture("Textures/Tablero/Casilla08/Seleccionado.png");
	SelecCasilla_08.LoadTextureA();

	DiaCasilla_09 = Texture("Textures/Tablero/Casilla09/Dia.png");
	DiaCasilla_09.LoadTextureA();
	NocheCasilla_09 = Texture("Textures/Tablero/Casilla09/Noche.png");
	NocheCasilla_09.LoadTextureA();
	SelecCasilla_09 = Texture("Textures/Tablero/Casilla09/Seleccionado.png");
	SelecCasilla_09.LoadTextureA();

	DiaCasilla_10 = Texture("Textures/Tablero/Casilla10/Dia.png");
	DiaCasilla_10.LoadTextureA();
	NocheCasilla_10 = Texture("Textures/Tablero/Casilla10/Noche.png");
	NocheCasilla_10.LoadTextureA();
	SelecCasilla_10 = Texture("Textures/Tablero/Casilla10/Seleccionado.png");
	SelecCasilla_10.LoadTextureA();

	//			Flora					//

	DiaCasilla_11 = Texture("Textures/Tablero/Casilla11/Dia.png");
	DiaCasilla_11.LoadTextureA();
	NocheCasilla_11 = Texture("Textures/Tablero/Casilla11/Noche.png");
	NocheCasilla_11.LoadTextureA();
	SelecCasilla_11 = Texture("Textures/Tablero/Casilla11/Seleccionado.png");
	SelecCasilla_11.LoadTextureA();

	DiaCasilla_12 = Texture("Textures/Tablero/Casilla12/Dia.png");
	DiaCasilla_12.LoadTextureA();
	NocheCasilla_12 = Texture("Textures/Tablero/Casilla12/Noche.png");
	NocheCasilla_12.LoadTextureA();
	SelecCasilla_12 = Texture("Textures/Tablero/Casilla12/Seleccionado.png");
	SelecCasilla_12.LoadTextureA();

	DiaCasilla_13 = Texture("Textures/Tablero/Casilla13/Dia.png");
	DiaCasilla_13.LoadTextureA();
	NocheCasilla_13 = Texture("Textures/Tablero/Casilla13/Noche.png");
	NocheCasilla_13.LoadTextureA();
	SelecCasilla_13 = Texture("Textures/Tablero/Casilla13/Seleccionado.png");
	SelecCasilla_13.LoadTextureA();

	DiaCasilla_14 = Texture("Textures/Tablero/Casilla14/Dia.png");
	DiaCasilla_14.LoadTextureA();
	NocheCasilla_14 = Texture("Textures/Tablero/Casilla14/Noche.png");
	NocheCasilla_14.LoadTextureA();
	SelecCasilla_14 = Texture("Textures/Tablero/Casilla14/Seleccionado.png");
	SelecCasilla_14.LoadTextureA();

	DiaCasilla_15 = Texture("Textures/Tablero/Casilla15/Dia.png");
	DiaCasilla_15.LoadTextureA();
	NocheCasilla_15 = Texture("Textures/Tablero/Casilla15/Noche.png");
	NocheCasilla_15.LoadTextureA();
	SelecCasilla_15 = Texture("Textures/Tablero/Casilla15/Seleccionado.png");
	SelecCasilla_15.LoadTextureA();

	DiaCasilla_16 = Texture("Textures/Tablero/Casilla16/Dia.png");
	DiaCasilla_16.LoadTextureA();
	NocheCasilla_16 = Texture("Textures/Tablero/Casilla16/Noche.png");
	NocheCasilla_16.LoadTextureA();
	SelecCasilla_16 = Texture("Textures/Tablero/Casilla16/Seleccionado.png");
	SelecCasilla_16.LoadTextureA();

	DiaCasilla_17 = Texture("Textures/Tablero/Casilla17/Dia.png");
	DiaCasilla_17.LoadTextureA();
	NocheCasilla_17 = Texture("Textures/Tablero/Casilla17/Noche.png");
	NocheCasilla_17.LoadTextureA();
	SelecCasilla_17 = Texture("Textures/Tablero/Casilla17/Seleccionado.png");
	SelecCasilla_17.LoadTextureA();

	DiaCasilla_18 = Texture("Textures/Tablero/Casilla18/Dia.png");
	DiaCasilla_18.LoadTextureA();
	NocheCasilla_18 = Texture("Textures/Tablero/Casilla18/Noche.png");
	NocheCasilla_18.LoadTextureA();
	SelecCasilla_18 = Texture("Textures/Tablero/Casilla18/Seleccionado.png");
	SelecCasilla_18.LoadTextureA();

	DiaCasilla_19 = Texture("Textures/Tablero/Casilla19/Dia.png");
	DiaCasilla_19.LoadTextureA();
	NocheCasilla_19 = Texture("Textures/Tablero/Casilla19/Noche.png");
	NocheCasilla_19.LoadTextureA();
	SelecCasilla_19 = Texture("Textures/Tablero/Casilla19/Seleccionado.png");
	SelecCasilla_19.LoadTextureA();

	DiaCasilla_20 = Texture("Textures/Tablero/Casilla20/Dia.png");
	DiaCasilla_20.LoadTextureA();
	NocheCasilla_20 = Texture("Textures/Tablero/Casilla20/Noche.png");
	NocheCasilla_20.LoadTextureA();
	SelecCasilla_20 = Texture("Textures/Tablero/Casilla20/Seleccionado.png");
	SelecCasilla_20.LoadTextureA();

	//			Fauna					//

	DiaCasilla_21 = Texture("Textures/Tablero/Casilla21/Dia.png");
	DiaCasilla_21.LoadTextureA();
	NocheCasilla_21 = Texture("Textures/Tablero/Casilla21/Noche.png");
	NocheCasilla_21.LoadTextureA();
	SelecCasilla_21 = Texture("Textures/Tablero/Casilla21/Seleccionado.png");
	SelecCasilla_21.LoadTextureA();

	DiaCasilla_22 = Texture("Textures/Tablero/Casilla22/Dia.png");
	DiaCasilla_22.LoadTextureA();
	NocheCasilla_22 = Texture("Textures/Tablero/Casilla22/Noche.png");
	NocheCasilla_22.LoadTextureA();
	SelecCasilla_22 = Texture("Textures/Tablero/Casilla22/Seleccionado.png");
	SelecCasilla_22.LoadTextureA();

	DiaCasilla_23 = Texture("Textures/Tablero/Casilla23/Dia.png");
	DiaCasilla_23.LoadTextureA();
	NocheCasilla_23 = Texture("Textures/Tablero/Casilla23/Noche.png");
	NocheCasilla_23.LoadTextureA();
	SelecCasilla_23 = Texture("Textures/Tablero/Casilla23/Seleccionado.png");
	SelecCasilla_23.LoadTextureA();

	DiaCasilla_24 = Texture("Textures/Tablero/Casilla24/Dia.png");
	DiaCasilla_24.LoadTextureA();
	NocheCasilla_24 = Texture("Textures/Tablero/Casilla24/Noche.png");
	NocheCasilla_24.LoadTextureA();
	SelecCasilla_24 = Texture("Textures/Tablero/Casilla24/Seleccionado.png");
	SelecCasilla_24.LoadTextureA();

	DiaCasilla_25 = Texture("Textures/Tablero/Casilla25/Dia.png");
	DiaCasilla_25.LoadTextureA();
	NocheCasilla_25 = Texture("Textures/Tablero/Casilla25/Noche.png");
	NocheCasilla_25.LoadTextureA();
	SelecCasilla_25 = Texture("Textures/Tablero/Casilla25/Seleccionado.png");
	SelecCasilla_25.LoadTextureA();

	DiaCasilla_26 = Texture("Textures/Tablero/Casilla26/Dia.png");
	DiaCasilla_26.LoadTextureA();
	NocheCasilla_26 = Texture("Textures/Tablero/Casilla26/Noche.png");
	NocheCasilla_26.LoadTextureA();
	SelecCasilla_26 = Texture("Textures/Tablero/Casilla26/Seleccionado.png");
	SelecCasilla_26.LoadTextureA();

	DiaCasilla_27 = Texture("Textures/Tablero/Casilla27/Dia.png");
	DiaCasilla_27.LoadTextureA();
	NocheCasilla_27 = Texture("Textures/Tablero/Casilla27/Noche.png");
	NocheCasilla_27.LoadTextureA();
	SelecCasilla_27 = Texture("Textures/Tablero/Casilla27/Seleccionado.png");
	SelecCasilla_27.LoadTextureA();

	DiaCasilla_28 = Texture("Textures/Tablero/Casilla28/Dia.png");
	DiaCasilla_28.LoadTextureA();
	NocheCasilla_28 = Texture("Textures/Tablero/Casilla28/Noche.png");
	NocheCasilla_28.LoadTextureA();
	SelecCasilla_28 = Texture("Textures/Tablero/Casilla28/Seleccionado.png");
	SelecCasilla_28.LoadTextureA();

	DiaCasilla_29 = Texture("Textures/Tablero/Casilla29/Dia.png");
	DiaCasilla_29.LoadTextureA();
	NocheCasilla_29 = Texture("Textures/Tablero/Casilla29/Noche.png");
	NocheCasilla_29.LoadTextureA();
	SelecCasilla_29 = Texture("Textures/Tablero/Casilla29/Seleccionado.png");
	SelecCasilla_29.LoadTextureA();

	DiaCasilla_30 = Texture("Textures/Tablero/Casilla30/Dia.png");
	DiaCasilla_30.LoadTextureA();
	NocheCasilla_30 = Texture("Textures/Tablero/Casilla30/Noche.png");
	NocheCasilla_30.LoadTextureA();
	SelecCasilla_30 = Texture("Textures/Tablero/Casilla30/Seleccionado.png");
	SelecCasilla_30.LoadTextureA();

	//			Personajes				//

	DiaCasilla_31 = Texture("Textures/Tablero/Casilla31/Dia.png");
	DiaCasilla_31.LoadTextureA();
	NocheCasilla_31 = Texture("Textures/Tablero/Casilla31/Noche.png");
	NocheCasilla_31.LoadTextureA();
	SelecCasilla_31 = Texture("Textures/Tablero/Casilla31/Seleccionado.png");
	SelecCasilla_31.LoadTextureA();

	DiaCasilla_32 = Texture("Textures/Tablero/Casilla32/Dia.png");
	DiaCasilla_32.LoadTextureA();
	NocheCasilla_32 = Texture("Textures/Tablero/Casilla32/Noche.png");
	NocheCasilla_32.LoadTextureA();
	SelecCasilla_32 = Texture("Textures/Tablero/Casilla32/Seleccionado.png");
	SelecCasilla_32.LoadTextureA();

	DiaCasilla_33 = Texture("Textures/Tablero/Casilla33/Dia.png");
	DiaCasilla_33.LoadTextureA();
	NocheCasilla_33 = Texture("Textures/Tablero/Casilla33/Noche.png");
	NocheCasilla_33.LoadTextureA();
	SelecCasilla_33 = Texture("Textures/Tablero/Casilla33/Seleccionado.png");
	SelecCasilla_33.LoadTextureA();

	DiaCasilla_34 = Texture("Textures/Tablero/Casilla34/Dia.png");
	DiaCasilla_34.LoadTextureA();
	NocheCasilla_34 = Texture("Textures/Tablero/Casilla34/Noche.png");
	NocheCasilla_34.LoadTextureA();
	SelecCasilla_34 = Texture("Textures/Tablero/Casilla34/Seleccionado.png");
	SelecCasilla_34.LoadTextureA();

	DiaCasilla_35 = Texture("Textures/Tablero/Casilla35/Dia.png");
	DiaCasilla_35.LoadTextureA();
	NocheCasilla_35 = Texture("Textures/Tablero/Casilla35/Noche.png");
	NocheCasilla_35.LoadTextureA();
	SelecCasilla_35 = Texture("Textures/Tablero/Casilla35/Seleccionado.png");
	SelecCasilla_35.LoadTextureA();

	DiaCasilla_36 = Texture("Textures/Tablero/Casilla36/Dia.png");
	DiaCasilla_36.LoadTextureA();
	NocheCasilla_36 = Texture("Textures/Tablero/Casilla36/Noche.png");
	NocheCasilla_36.LoadTextureA();
	SelecCasilla_36 = Texture("Textures/Tablero/Casilla36/Seleccionado.png");
	SelecCasilla_36.LoadTextureA();

	DiaCasilla_37 = Texture("Textures/Tablero/Casilla37/Dia.png");
	DiaCasilla_37.LoadTextureA();
	NocheCasilla_37 = Texture("Textures/Tablero/Casilla37/Noche.png");
	NocheCasilla_37.LoadTextureA();
	SelecCasilla_37 = Texture("Textures/Tablero/Casilla37/Seleccionado.png");
	SelecCasilla_37.LoadTextureA();

	DiaCasilla_38 = Texture("Textures/Tablero/Casilla38/Dia.png");
	DiaCasilla_38.LoadTextureA();
	NocheCasilla_38 = Texture("Textures/Tablero/Casilla38/Noche.png");
	NocheCasilla_38.LoadTextureA();
	SelecCasilla_38 = Texture("Textures/Tablero/Casilla38/Seleccionado.png");
	SelecCasilla_38.LoadTextureA();

	DiaCasilla_39 = Texture("Textures/Tablero/Casilla39/Dia.png");
	DiaCasilla_39.LoadTextureA();
	NocheCasilla_39 = Texture("Textures/Tablero/Casilla39/Noche.png");
	NocheCasilla_39.LoadTextureA();
	SelecCasilla_39 = Texture("Textures/Tablero/Casilla39/Seleccionado.png");
	SelecCasilla_39.LoadTextureA();

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
	Apartamento.LoadModel("Models/Ciudad/edif.obj");
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

	unsigned int spotLightCount = 0;

	////luz nocturna fija
	spotLights[0] = SpotLight(1.0f, 1.0f, 1.0f,
		2.0f, 2.0f,
		50.0f, 10.0f, 50.0f,
		0.0f, -5.0f, 0.0f,
		0.70f, 0.20f, 0.30f,
		25.0f);
	spotLightCount++;

	

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
	pasosx = -45;
	pasosz = 45;

	// Tablero
	estado = 0;

	movX = -45.0f;
	movZ = 45.0f;
	offsetMovHel = 0.5f;

	rotY = 0.0f;
	offsetRotHel = 0.5f;

	estado2 = 0;
	rotObjetivo = 0;
	avance = 0;

	Personaje = true;

	// Animacion personaje casilla
	float movCasY = 0.0f;
	float offsetMovCasY = 0.5f;

	float rotCasY = 0.0f;
	float offsetRotCasY = 0.5f;

	// Control de Tiempo
	tIni = 0.0f;
	tFin = 0.0f;
	tiempoAcumulado = 0.0f;
	Animacion = false;


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
		//CAMBIO DE CAMARAS//
		if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_Z)) {
			if (estado < 10) {
				camera = Camera(glm::vec3(movX, 7.0f, movZ + 15), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f + rotY, 0.0f, 0.3f, 0.5f);
			}
			else if (estado < 20) {
				camera = Camera(glm::vec3(movX - 15, 7.0f, movZ), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f - rotY, 0.0f, 0.3f, 0.5f);
			}
			else if (estado < 30) {
				camera = Camera(glm::vec3(movX, 7.0f, movZ - 15), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f + rotY, 0.0f, 0.3f, 0.5f);
			}
			else if (estado < 40) {
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
			camera = Camera(glm::vec3(-50.0f, 60.0f, 70.0f), glm::vec3(0.0f, 1.0f, 0.0f), -50.0f, -46.0f, 0.3f, 0.5f);
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
			else if (despl_solz >= -0.000477 && despl_solz < 0.7) {
				despl_soly += 0.00002;
			}
			else if (despl_solz > 0.7 || despl_solz > -0.7) {
				despl_soly = 0;
			}
		}
		else if (despl_solz > -1.1) {
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

		//Tiempo durante la ejecucion
		tiempoAcumulado = glfwGetTime();;

		if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_T) && alternar && finaliza == true && avanza==false) {
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
			avanza = true;

			//////////////////////////////////////
			//		Control del Tablero			//
			//////////////////////////////////////

			estado += (c + c_2);

			// Animacion

			Animacion = true;

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


		//información al shader de fuentes de iluminación
		shaderList[0].SetDirectionalLight(&mainLight);
		shaderList[0].SetPointLights(pointLights, pointLightCount);
		if (dia) {
			val = 0;
		}
		else {
			val = spotLightCount;
			spotLights[0].SetPos(glm::vec3(movX, 10, movZ));
		}
		shaderList[0].SetSpotLights(spotLights, val);

		// Guardo la posición del personaje
		glm::vec3 PosicionPersonaje;


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

		if (estado == 39) {

			//Inicializa Animacion
			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-33.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), 35.0f));
			model = glm::rotate(model, RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			//Renderizado
			Cortana.RenderModel();
		}

		if (estado == 38) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-25.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), 35.0f));
			model = glm::rotate(model, RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Inquizidor.RenderModel();
		}

		if (estado == 37) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-16.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), 35.0f));
			model = glm::rotate(model, RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Noble6.RenderModel();
		}

		if (estado == 36) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-7.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), 35.0f));
			model = glm::rotate(model, RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			SetoKaiba.RenderModel();
		}

		if (estado == 35) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-0.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), 35.0f));
			model = glm::rotate(model, RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Bakura.RenderModel();
		}

		if (estado == 34) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(8.5f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), 35.0f));
			model = glm::rotate(model, RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			YugiMoto.RenderModel();
		}

		if (estado == 33) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(17.0f, -7.3f + MovimientoAvanzado(tIni, tiempoAcumulado), 35.0f));
			model = glm::rotate(model, RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			DoctorOctopus.RenderModel();
		}

		if (estado == 32) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(25.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), 35.0f));
			model = glm::rotate(model, RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			DuendeVerde.RenderModel();
		}

		if (estado == 31) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(33.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), 35.0f));
			model = glm::rotate(model, RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			DoctorStrange.RenderModel();
		}

		//				Fauna				//

		if (estado == 30) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(35.0f, -9.0f + MovimientoAvanzado(tIni, tiempoAcumulado), 35.0f));
			model = glm::rotate(model, 45 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Guta.RenderModel();
		}

		if (estado == 29) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(35.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), 33.0f));
			model = glm::rotate(model, 90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Yanmee.RenderModel();
		}

		if (estado == 28) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(35.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), 25.0f));
			model = glm::rotate(model, RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Moa.RenderModel();
		}

		if (estado == 27) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(33.0f, -9.0f + MovimientoAvanzado(tIni, tiempoAcumulado), 17.0f));
			model = glm::rotate(model, 90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Rana.RenderModel();
		}

		if (estado == 26) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(33.0f, -8.0f + MovimientoAvanzado(tIni, tiempoAcumulado), 8.0f));
			model = glm::rotate(model, 90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Perro.RenderModel();
		}

		if (estado == 25) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(33.0f, -6.9f + MovimientoAvanzado(tIni, tiempoAcumulado), 0.0f));
			model = glm::rotate(model, 90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Pinguino.RenderModel();
		}

		if (estado == 24) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(33.0f, -8.1f + MovimientoAvanzado(tIni, tiempoAcumulado), -7.0f));
			model = glm::rotate(model, 90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Gato.RenderModel();
		}

		if (estado == 23) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(35.0f, -11.0f + MovimientoAvanzado(tIni, tiempoAcumulado), -16.0f));
			model = glm::rotate(model, 90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Lagarto.RenderModel();
		}

		if (estado == 22) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(35.0f, -7.9f + MovimientoAvanzado(tIni, tiempoAcumulado), -24.0f));
			model = glm::rotate(model, 90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Paloma.RenderModel();
		}

		if (estado == 21) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(35.0f, -10.0f + MovimientoAvanzado(tIni, tiempoAcumulado), -33.0f));
			model = glm::rotate(model, 90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Arana.RenderModel();
		}

		//				Flora				//

		if (estado == 20) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(35.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), -35.0f));
			model = glm::rotate(model, 45 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Seta.RenderModel();
		}

		if (estado == 11) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-33.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), -35.0f));
			model = glm::rotate(model, 180 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			RobleRojo.RenderModel();
		}

		if (estado == 12) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-25.0f, -8.4f + MovimientoAvanzado(tIni, tiempoAcumulado), -35.0f));
			model = glm::rotate(model, 180 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Cerezo.RenderModel();
		}

		if (estado == 13) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-16.0f, -8.4f + MovimientoAvanzado(tIni, tiempoAcumulado), -35.0f));
			model = glm::rotate(model, 180 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Rododendro.RenderModel();
		}

		if (estado == 14) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-8.0f, -10.9f + MovimientoAvanzado(tIni, tiempoAcumulado), -32.0f));
			model = glm::rotate(model, 180 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			JardinRosas.RenderModel();
		}

		if (estado == 15) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-0.0f, -10.4f + MovimientoAvanzado(tIni, tiempoAcumulado), -32.0f));
			model = glm::rotate(model, 180 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Bosque.RenderModel();
		}

		if (estado == 16) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(8.5f, -7.3f + MovimientoAvanzado(tIni, tiempoAcumulado), -33.0f));
			model = glm::rotate(model, 180 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Islas.RenderModel();
		}

		if (estado == 17) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(17.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), -35.0f));
			model = glm::rotate(model, 180 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			KibaTorcido.RenderModel();
		}

		if (estado == 18) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(25.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), -35.0f));
			model = glm::rotate(model, 180 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			RobleReach.RenderModel();
		}

		if (estado == 19) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(33.0f, -8.5f + MovimientoAvanzado(tIni, tiempoAcumulado), -35.0f));
			model = glm::rotate(model, 180 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Xenoflora.RenderModel();
		}

		//			Edificios				//

		if (estado == 1) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-35.0f, -10.8f + MovimientoAvanzado(tIni, tiempoAcumulado), 33.0f));
			model = glm::rotate(model, -90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Puente.RenderModel();
		}

		if (estado == 2) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-35.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), 25.0f));
			model = glm::rotate(model, -90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Estatua.RenderModel();
		}

		if (estado == 3) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-31.0f, -7.9f + MovimientoAvanzado(tIni, tiempoAcumulado), 17.0f));
			model = glm::rotate(model, -90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Universidad.RenderModel();
		}

		if (estado == 4) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-33.0f, -8.0f + MovimientoAvanzado(tIni, tiempoAcumulado), 8.0f));
			model = glm::rotate(model, -90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Cafeteria.RenderModel();
		}

		if (estado == 5) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-32.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), 0.5f));
			model = glm::rotate(model, -90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Corporation.RenderModel();
		}

		if (estado == 6) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-32.0f, -9.1f + MovimientoAvanzado(tIni, tiempoAcumulado), -8.5f));
			model = glm::rotate(model, -90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Kingdom.RenderModel();
		}

		if (estado == 7) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-35.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), -16.0f));
			model = glm::rotate(model, -90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Instituto.RenderModel();
		}

		if (estado == 8) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-33.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), -25.0f));
			model = glm::rotate(model, -90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			GranCaridad.RenderModel();
		}

		if (estado == 9) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-33.0f, -11.05f + MovimientoAvanzado(tIni, tiempoAcumulado), -33.0f));
			model = glm::rotate(model, -90 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Arca.RenderModel();
		}


		if (estado == 10) {

			if (Animacion) {
				Animacion = false;
				tIni = tiempoAcumulado;
			}

			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(-35.0f, -6.8f + MovimientoAvanzado(tIni, tiempoAcumulado), -35.0f));
			model = glm::rotate(model, -45 * toRadians + RotacionAvanzada(tIni, tiempoAcumulado), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

			Anillo.RenderModel();
		}

		//////////////////////////////////////

		//			Ciudad				//

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(60.0f, 10.0f, 60.0f));
		model = glm::rotate(model, -45 * toRadians, glm::vec3(0.0f, 2.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Canon.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(10.0f, -2.0f, 66.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 15.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-60.0f, -2.0f, 66.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 15.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.0f, -2.0f, 86.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 18.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-40.0f, -2.0f, 86.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 18.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-50.0f, 45.0f, 0.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Crucero.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(40.0f, -2.0f, -66.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(40.0f, -2.0f, -86.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -2.0f, -66.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-40.0f, -2.0f, -86.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-40.0f, -2.0f, -66.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-76.0f, 25.0f, -40.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(25.0f, 25.0f, 25.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Edificio.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(66.0f, 45.0f, -40.0f));
		model = glm::scale(model, glm::vec3(40.0f, 45.0f, 40.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		EmpireState.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(86.0f, -2.0f, -30.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(66.0f, -2.0f, 10.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(86.0f, -2.0f, 60.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 40.0f, 70.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		EstacionEspacial.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(70.0f, 45.0f, 0.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Scarag.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-60.0f, 15.0f, 40.0f));
		model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, -1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		StarFighter.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-86.0f, -2.0f, 10.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(15.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-66.0f, -2.0f, 5.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(15.0f, 20.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Apartamento.RenderModel();

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

		if (finaliza) {
			if (estado >= 0 && estado < 10) {
				if (movX > -45.0f) {
					movX -= 0.2;
				}
				else {
					rotY = -180.0f;
					movX = -45.0f;
					if (estado == 0) {
						pasosz = 45.0f;
					}
					else if (estado == 1) {
						pasosz = 33.0f;
					}
					else if (estado == 2) {
						pasosz = 25.0f;
					}
					else if (estado == 3) {
						pasosz = 17.0f;
					}
					else if (estado == 4) {
						pasosz = 8.0f;
					}
					else if (estado == 5) {
						pasosz = 0;
					}
					else if (estado == 6) {
						pasosz = -8.0f;
					}
					else if (estado == 7) {
						pasosz = -17.0f;
					}
					else if (estado == 8) {
						pasosz = -25.0f;
					}
					else if (estado == 9) {
						pasosz = -33.0f;
					}
					if ((movZ - 0.2) > pasosz) {
						movZ -= 0.2;
					}
					else {
						avanza = false;
					}
				}
			}
			if (estado >= 10 && estado < 20) {
				if (movZ > -45.0f) {
					movZ -= 0.2;
				}
				else {
					rotY = -270.0f;
					movZ = -45.0f;
					if (estado == 10) {
						pasosx = -45.0f;
					}
					else if (estado == 11) {
						pasosx = -33.0f;
					}
					else if (estado == 12) {
						pasosx = -25.0f;
					}
					else if (estado == 13) {
						pasosx = -17.0f;
					}
					else if (estado == 14) {
						pasosx = -8.0f;
					}
					else if (estado == 15) {
						pasosx = 0.0f;
					}
					else if (estado == 16) {
						pasosx = 8.0f;
					}
					else if (estado == 17) {
						pasosx = 17.0f;
					}
					else if (estado == 18) {
						pasosx = 25.0f;
					}
					else if (estado == 19) {
						pasosx = 33.0f;
					}
					if ((movX + 0.2) < pasosx) {
						movX += 0.2;
					}
					else {
						avanza = false;
					}
				}
			}
			if (estado >= 20 && estado < 30) {
				if (movX < 45.0f) {
					movX += 0.2;
				}
				else {
					rotY = 0.0f;
					movX = 45.0f;
					if (estado == 20) {
						pasosz = -45.0f;
					}
					else if (estado == 21) {
						pasosz = -33.0f;
					}
					else if (estado == 22) {
						pasosz = -25.0f;
					}
					else if (estado == 23) {
						pasosz = -17.0f;
					}
					else if (estado == 24) {
						pasosz = -8.0f;
					}
					else if (estado == 25) {
						pasosz = 0.0f;
					}
					else if (estado == 26) {
						pasosz = 8.0f;
					}
					else if (estado == 27) {
						pasosz = 17.0f;
					}
					else if (estado == 28) {
						pasosz = 25.0f;
					}
					else if (estado == 29) {
						pasosz = 33.0f;
					}
					if ((movZ + 0.2) < pasosz) {
						movZ += 0.2;
					}
					else {
						avanza = false;
					}
				}
			}
			if (estado >= 30 && estado < 40) {
				if (movZ < 45.0f) {
					movZ += 0.2;
				}
				else {
					rotY = -90.0f;
					movZ = 45.0f;
					if (estado == 30) {
						pasosx = 45.0f;
					}
					if (estado == 31) {
						pasosx = 33.0f;
					}
					if (estado == 32) {
						pasosx = 25.0f;
					}
					if (estado == 33) {
						pasosx = 17.0f;
					}
					if (estado == 34) {
						pasosx = 8.0f;
					}
					if (estado == 35) {
						pasosx = 0.0f;
					}
					if (estado == 36) {
						pasosx = -8.0f;
					}
					if (estado == 37) {
						pasosx = -17.0f;
					}
					if (estado == 38) {
						pasosx = -25.0f;
					}
					if (estado == 39) {
						pasosx = -33.0f;
					}
					if ((movX - 0.2) > pasosx) {
						movX -= 0.2;
					}
					else {
						avanza = false;
					}
				}
			}
		}

		//////////////////////////////////////
		//		Renderizado de Texturas		//
		//////////////////////////////////////

		//				Imagen				//

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -1.9f, 0.0f));
		model = glm::scale(model, glm::vec3(3.8f, 1.0f, 3.8f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));

		if (dia) {
			TableroDia.UseTexture();
		}
		else {
			TableroNoche.UseTexture();
		}

		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[3]->RenderMesh();

		//			Edificios				//

		//Inicializa la textura
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-43.5f, -1.8f, 44.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));

		if (estado == 0) {
			//Textura de casilla seleccionada
			SelecCasilla_00.UseTexture();
		}
		else {
			//Dia o noche
			if (dia) {
				DiaCasilla_00.UseTexture();
			}
			else {
				NocheCasilla_00.UseTexture();
			}
		}
		//Renderiza Textura
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[7]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-43.5f, -1.8f, 33.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 1) {
			SelecCasilla_01.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_01.UseTexture();
			}
			else {
				NocheCasilla_01.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-43.5f, -1.8f, 25.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 2) {
			SelecCasilla_02.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_02.UseTexture();
			}
			else {
				NocheCasilla_02.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-43.5f, -1.8f, 16.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 3) {
			SelecCasilla_03.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_03.UseTexture();
			}
			else {
				NocheCasilla_03.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-43.5f, -1.8f, 8.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 4) {
			SelecCasilla_04.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_04.UseTexture();
			}
			else {
				NocheCasilla_04.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-43.5f, -1.8f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 5) {
			SelecCasilla_05.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_05.UseTexture();
			}
			else {
				NocheCasilla_05.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-43.5f, -1.8f, -8.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 6) {
			SelecCasilla_06.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_06.UseTexture();
			}
			else {
				NocheCasilla_06.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-43.5f, -1.8f, -16.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 7) {
			SelecCasilla_07.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_07.UseTexture();
			}
			else {
				NocheCasilla_07.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-43.5f, -1.8f, -24.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 8) {
			SelecCasilla_08.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_08.UseTexture();
			}
			else {
				NocheCasilla_08.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-43.5f, -1.8f, -33.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 9) {
			SelecCasilla_09.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_09.UseTexture();
			}
			else {
				NocheCasilla_09.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-43.5f, -1.8f, -43.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 10) {
			SelecCasilla_10.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_10.UseTexture();
			}
			else {
				NocheCasilla_10.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[7]->RenderMesh();

		//				Flora				//

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-33.0f, -1.8f, -43.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 11) {
			SelecCasilla_11.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_11.UseTexture();
			}
			else {
				NocheCasilla_11.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-24.5f, -1.8f, -43.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 12) {
			SelecCasilla_12.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_12.UseTexture();
			}
			else {
				NocheCasilla_12.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-16.2f, -1.8f, -43.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 13) {
			SelecCasilla_13.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_13.UseTexture();
			}
			else {
				NocheCasilla_13.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-8.0f, -1.8f, -43.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 14) {
			SelecCasilla_14.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_14.UseTexture();
			}
			else {
				NocheCasilla_14.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.0f, -1.8f, -43.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 15) {
			SelecCasilla_15.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_15.UseTexture();
			}
			else {
				NocheCasilla_15.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(8.0f, -1.8f, -43.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 16) {
			SelecCasilla_16.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_16.UseTexture();
			}
			else {
				NocheCasilla_16.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(16.0f, -1.8f, -43.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 17) {
			SelecCasilla_17.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_17.UseTexture();
			}
			else {
				NocheCasilla_17.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(24.5f, -1.8f, -43.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 18) {
			SelecCasilla_18.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_18.UseTexture();
			}
			else {
				NocheCasilla_18.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, -1.8f, -43.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 19) {
			SelecCasilla_19.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_19.UseTexture();
			}
			else {
				NocheCasilla_19.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(43.5f, -1.8f, -43.5f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 20) {
			SelecCasilla_20.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_20.UseTexture();
			}
			else {
				NocheCasilla_20.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[7]->RenderMesh();

		//				Fauna				//

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(43.5f, -1.8f, -33.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 21) {
			SelecCasilla_21.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_21.UseTexture();
			}
			else {
				NocheCasilla_21.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(43.5f, -1.8f, -24.5f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 22) {
			SelecCasilla_22.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_22.UseTexture();
			}
			else {
				NocheCasilla_22.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(43.5f, -1.8f, -16.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 23) {
			SelecCasilla_23.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_23.UseTexture();
			}
			else {
				NocheCasilla_23.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(43.5f, -1.8f, -8.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 24) {
			SelecCasilla_24.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_24.UseTexture();
			}
			else {
				NocheCasilla_24.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(43.5f, -1.8f, 0.5f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 25) {
			SelecCasilla_25.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_25.UseTexture();
			}
			else {
				NocheCasilla_25.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(43.5f, -1.8f, 8.5f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 26) {
			SelecCasilla_26.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_26.UseTexture();
			}
			else {
				NocheCasilla_26.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(43.5f, -1.8f, 16.5f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 27) {
			SelecCasilla_27.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_27.UseTexture();
			}
			else {
				NocheCasilla_27.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(43.5f, -1.8f, 25.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 28) {
			SelecCasilla_28.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_28.UseTexture();
			}
			else {
				NocheCasilla_28.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(43.5f, -1.8f, 33.5f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 29) {
			SelecCasilla_29.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_29.UseTexture();
			}
			else {
				NocheCasilla_29.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(43.5f, -1.8f, 44.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 30) {
			SelecCasilla_30.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_30.UseTexture();
			}
			else {
				NocheCasilla_30.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[7]->RenderMesh();

		//				Personajes			//

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(33.0f, -1.8f, 44.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 31) {
			SelecCasilla_31.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_31.UseTexture();
			}
			else {
				NocheCasilla_31.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(24.5f, -1.8f, 44.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 32) {
			SelecCasilla_32.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_32.UseTexture();
			}
			else {
				NocheCasilla_32.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(16.0f, -1.8f, 44.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 33) {
			SelecCasilla_33.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_33.UseTexture();
			}
			else {
				NocheCasilla_33.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(8.0f, -1.8f, 44.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 34) {
			SelecCasilla_34.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_34.UseTexture();
			}
			else {
				NocheCasilla_34.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.0f, -1.8f, 44.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 35) {
			SelecCasilla_35.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_35.UseTexture();
			}
			else {
				NocheCasilla_35.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-8.0f, -1.8f, 44.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 36) {
			SelecCasilla_36.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_36.UseTexture();
			}
			else {
				NocheCasilla_36.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-16.2f, -1.8f, 44.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 37) {
			SelecCasilla_37.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_37.UseTexture();
			}
			else {
				NocheCasilla_37.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-24.5f, -1.8f, 44.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 38) {
			SelecCasilla_38.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_38.UseTexture();
			}
			else {
				NocheCasilla_38.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-33.0f, -1.8f, 44.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (estado == 39) {
			SelecCasilla_39.UseTexture();
		}
		else {
			if (dia) {
				DiaCasilla_39.UseTexture();
			}
			else {
				NocheCasilla_39.UseTexture();
			}
		}
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[6]->RenderMesh();

		// Fin

		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	// Liberar recursos
	/*ma_device_uninit(&device);
	ma_decoder_uninit(&decoder);*/
	ma_sound_uninit(&soundtrack);
	ma_engine_uninit(&engine);

	return 0;
}
