///*
//Proyecto Final de Computación Gráfica e Interacción Humano Computadora
//
//Hernandez Solis Brandon
//Reyes Arroyo Pablo Antonio
//
//*/
////para cargar imagen
//#define STB_IMAGE_IMPLEMENTATION
//
//#include <stdio.h>
//#include <string.h>
//#include <cmath>
//#include <vector>
//#include <math.h>
//
//#include <glew.h>
//#include <glfw3.h>
//
//#include <glm.hpp>
//#include <gtc\matrix_transform.hpp>
//#include <gtc\type_ptr.hpp>
////para probar el importer
////#include<assimp/Importer.hpp>
//
//#include "Window.h"
//#include "Mesh.h"
//#include "Shader_light.h"
//#include "Camera.h"
//#include "Texture.h"
//#include "Sphere.h"
//#include"Model.h"
//#include "Skybox.h"
//
////para iluminación
//#include "CommonValues.h"
//#include "DirectionalLight.h"
//#include "PointLight.h"
//#include "SpotLight.h"
//#include "Material.h"
//const float toRadians = 3.14159265f / 180.0f;
//
////variables para animación
//float movCoche;
//float movOffset;
//float rotllanta;
//float rotllantaOffset;
//bool avanza;
//bool switch_number;
//bool alternar;
//float toffsetflechau = 0.0f;
//float toffsetflechav = 0.0f;
//float toffsetnumerou = 0.0f;
//float toffsetnumerov = 0.0f;
//float toffsetletrerou = 0.0f;
//float toffsetletrerov = 0.0f;
//float toffsetnumerocambiau = 0.0;
//float angulovaria = 0.0f;
//float movDragon;
//float movDOffset;
//float posy_d = 0.0f;
//bool down = true;
//float a_ala = 0;
//float a_ala2 = 0;
//int rot = 0;
//float rotDado_8;
//float rotDado8;
//float rotDado_8Offset;
//bool baja;
//int c;
//int c_2;
//float salto;
//float movDado8;
//float movOffsetLet;
//float rotDado4;
//float rotDado_4;
//float lastRot;
//float lastRot4;
//int pasosEnTablero;
//
//float val = 0.0f;
//
//float val_l;
//float val_c;
//float val_o;
//
////variables para keyframes
//float reproduciranimacion, habilitaranimacion, guardoFrame, reinicioFrame, ciclo, ciclo2, contador = 0;
//
//Window mainWindow;
//std::vector<Mesh*> meshList;
//std::vector<Shader> shaderList;
//
//Camera camera;
//
//Texture brickTexture;
//Texture dirtTexture;
//Texture plainTexture;
//Texture pisoTexture;
//Texture AgaveTexture;
//Texture FlechaTexture;
//Texture NumerosTexture;
//Texture Numero1Texture;
//Texture Numero2Texture;
//Texture Letrero;
//Texture tablero;
//Texture Dado4;
//
//
//Model Kitt_M;
//Model Llanta_M;
//Model Dragon_M;
//Model Tiamat_M;
//Skybox skybox;
//Model arco;
//Model letrero;
//
//Model Body_D;
//Model Ala_izq;
//Model Ala_der;
//Model dh1;
//Model dh2;
//Model dh3;
//Model dh4;
//Model dh5;
//Model dado8;
//
////materiales
//Material Material_brillante;
//Material Material_opaco;
//
//
////Sphere cabeza = Sphere(0.5, 20, 20);
//GLfloat deltaTime = 0.0f;
//GLfloat lastTime = 0.0f;
//static double limitFPS = 1.0 / 60.0;
//
//// luz direccional
//DirectionalLight mainLight;
////para declarar varias luces de tipo pointlight
//PointLight pointLights[MAX_POINT_LIGHTS];
//SpotLight spotLights[MAX_SPOT_LIGHTS];
//
//// Vertex Shader
//static const char* vShader = "shaders/shader_light.vert";
//
//// Fragment Shader
//static const char* fShader = "shaders/shader_light.frag";
//
//
//
////cálculo del promedio de las normales para sombreado de Phong
//void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
//	unsigned int vLength, unsigned int normalOffset)
//{
//	for (size_t i = 0; i < indiceCount; i += 3)
//	{
//		unsigned int in0 = indices[i] * vLength;
//		unsigned int in1 = indices[i + 1] * vLength;
//		unsigned int in2 = indices[i + 2] * vLength;
//		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
//		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
//		glm::vec3 normal = glm::cross(v1, v2);
//		normal = glm::normalize(normal);
//
//		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
//		vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
//		vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
//		vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
//	}
//
//	for (size_t i = 0; i < verticeCount / vLength; i++)
//	{
//		unsigned int nOffset = i * vLength + normalOffset;
//		glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
//		vec = glm::normalize(vec);
//		vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
//	}
//}
//
//
//void CreateObjects()
//{
//	unsigned int indices[] = {
//		0, 3, 1,
//		1, 3, 2,
//		2, 3, 0,
//		0, 1, 2
//	};
//
//	GLfloat vertices[] = {
//		//	x      y      z			u	  v			nx	  ny    nz
//			-1.0f, -1.0f, -0.6f,	0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
//			0.0f, -1.0f, 1.0f,		0.5f, 0.0f,		0.0f, 0.0f, 0.0f,
//			1.0f, -1.0f, -0.6f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
//			0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		0.0f, 0.0f, 0.0f
//	};
//
//	unsigned int floorIndices[] = {
//		0, 2, 1,
//		1, 2, 3
//	};
//
//	GLfloat floorVertices[] = {
//		-10.0f, 0.0f, -10.0f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
//		10.0f, 0.0f, -10.0f,	10.0f, 0.0f,	0.0f, -1.0f, 0.0f,
//		-10.0f, 0.0f, 10.0f,	0.0f, 10.0f,	0.0f, -1.0f, 0.0f,
//		10.0f, 0.0f, 10.0f,		10.0f, 10.0f,	0.0f, -1.0f, 0.0f
//	};
//	unsigned int vegetacionIndices[] = {
//	   0, 1, 2,
//	   0, 2, 3,
//	   4,5,6,
//	   4,6,7
//	};
//
//	GLfloat vegetacionVertices[] = {
//		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
//		0.5f, -0.5f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
//		0.5f, 0.5f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
//		-0.5f, 0.5f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,
//
//		0.0f, -0.5f, -0.5f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
//		0.0f, -0.5f, 0.5f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
//		0.0f, 0.5f, 0.5f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
//		0.0f, 0.5f, -0.5f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,
//
//
//	};
//
//
//	unsigned int flechaIndices[] = {
//	   0, 1, 2,
//	   0, 2, 3,
//	};
//
//	GLfloat flechaVertices[] = {
//		-0.5f, 0.0f, 0.5f,		0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
//		0.5f, 0.0f, 0.5f,		1.0f, 0.0f,		0.0f, -1.0f, 0.0f,
//		0.5f, 0.0f, -0.5f,		1.0f, 1.0f,		0.0f, -1.0f, 0.0f,
//		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f,		0.0f, -1.0f, 0.0f,
//
//	};
//
//	unsigned int scoreIndices[] = {
//	   0, 1, 2,
//	   0, 2, 3,
//	};
//
//	GLfloat scoreVertices[] = {
//		-0.5f, 0.0f, 0.5f,		0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
//		0.5f, 0.0f, 0.5f,		1.0f, 0.0f,		0.0f, -1.0f, 0.0f,
//		0.5f, 0.0f, -0.5f,		1.0f, 1.0f,		0.0f, -1.0f, 0.0f,
//		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f,		0.0f, -1.0f, 0.0f,
//
//	};
//
//	unsigned int numeroIndices[] = {
//	   0, 1, 2,
//	   0, 2, 3,
//	};
//
//	GLfloat numeroVertices[] = {
//		-0.5f, 0.0f, 0.5f,		0.0f, 0.67f,		0.0f, -1.0f, 0.0f,
//		0.5f, 0.0f, 0.5f,		0.25f, 0.67f,		0.0f, -1.0f, 0.0f,
//		0.5f, 0.0f, -0.5f,		0.25f, 1.0f,		0.0f, -1.0f, 0.0f,
//		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f,		0.0f, -1.0f, 0.0f,
//
//	};
//
//	unsigned int dado4Indices[] = {
//	   0, 1, 2,
//	   3, 4, 5,
//	   6, 7, 8,
//	   9, 10, 11
//	};
//
//	GLfloat dado4Vertices[] = {
//		0.0f, 1.0f, 0.0f,		0.486f, 0.86f,		0.0f, -1.0f, 0.0f,
//		0.5f, 0.0f, 0.5f,		0.698f, 0.465f,		-1.0f, 0.0f, -1.0f,
//		-0.5f, 0.0f, 0.5f,		0.276f, 0.465f,		1.0f, 0.0f, -1.0f,
//		//
//		0.0f, 1.0f, 0.0f,		0.486f, 0.86f,		0.0f, -1.0f, 0.0f,
//		-0.5f, 0.0f, 0.5f,		0.276f, 0.465f,		1.0f, 0.0f, -1.0f,
//		0.0f, 0.0f, -0.5f,		0.065f, 0.86f,			0.0f, 0.0f, 1.0f,
//		//
//		0.0f, 1.0f, 0.0f,		0.486f, 0.86f,		0.0f, -1.0f, 0.0f,
//		0.0f, 0.0f, -0.5f,		0.905f, 0.86f,			0.0f, 0.0f, 1.0f,
//		0.5f, 0.0f, 0.5f,		0.698f, 0.465f,		-1.0f, 0.0f, -1.0f,
//		//
//		0.0f, 0.0f, -0.5f,		0.4855f, 0.07f,			0.0f, 0.0f, 1.0f,
//		0.5f, 0.0f, 0.5f,		0.698f, 0.465f,		-1.0f, 0.0f, -1.0f,
//		-0.5f, 0.0f, 0.5f,		0.276f, 0.465f,			0.0f, 0.0f, 1.0f,
//	};
//
//	Mesh* obj1 = new Mesh();
//	obj1->CreateMesh(vertices, indices, 32, 12);
//	meshList.push_back(obj1);
//
//	Mesh* obj2 = new Mesh();
//	obj2->CreateMesh(vertices, indices, 32, 12);
//	meshList.push_back(obj2);
//
//	Mesh* obj3 = new Mesh();
//	obj3->CreateMesh(floorVertices, floorIndices, 32, 6);
//	meshList.push_back(obj3);
//
//
//	Mesh* obj4 = new Mesh();
//	obj4->CreateMesh(vegetacionVertices, vegetacionIndices, 64, 12);
//	meshList.push_back(obj4);
//
//	Mesh* obj5 = new Mesh();
//	obj5->CreateMesh(flechaVertices, flechaIndices, 32, 6);
//	meshList.push_back(obj5);
//
//	Mesh* obj6 = new Mesh();
//	obj6->CreateMesh(scoreVertices, scoreIndices, 32, 6);
//	meshList.push_back(obj6);
//
//	Mesh* obj7 = new Mesh();
//	obj7->CreateMesh(numeroVertices, numeroIndices, 32, 6);
//	meshList.push_back(obj7);
//
//	Mesh* obj8 = new Mesh();
//	obj8->CreateMesh(flechaVertices, flechaIndices, 32, 6);
//	meshList.push_back(obj8);
//
//	Mesh* dado4 = new Mesh();
//	dado4->CreateMesh(dado4Vertices, dado4Indices, 96, 12);
//	meshList.push_back(dado4);
//
//}
//
//
//
//
//void crearTablero() {
//	unsigned int floorIndices[] = {
//		0, 2, 1,
//		1, 2, 3
//	};
//
//	GLfloat floorVertices[] = {
//		-10.0f, 0.0f, -10.0f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
//		10.0f, 0.0f, -10.0f,	1.0f, 0.0f,	0.0f, -1.0f, 0.0f,
//		-10.0f, 0.0f, 10.0f,	0.0f, 1.0f,	0.0f, -1.0f, 0.0f,
//		10.0f, 0.0f, 10.0f,		1.0f, 1.0f,	0.0f, -1.0f, 0.0f
//	};
//
//	Mesh* obj3 = new Mesh();
//	obj3->CreateMesh(floorVertices, floorIndices, 32, 6);
//	meshList.push_back(obj3);
//
//}
//
//
//void CreateShaders()
//{
//	Shader* shader1 = new Shader();
//	shader1->CreateFromFiles(vShader, fShader);
//	shaderList.push_back(*shader1);
//}
//
//
/////////////////////////////////KEYFRAMES/////////////////////
//
//
//bool animacion = false;
//
//
//
////NEW// Keyframes
//float posXDado8 = 20.0, posYDado8 = 10.0, posZDado8 = 20.0;
//float movDado8_x = 0.0f, movDado8_y = 0.0f;
//float giroDado8 = 0;
//
//#define MAX_FRAMES 100
//int i_max_steps = 90;
//int i_curr_steps = 4;
//typedef struct _frame
//{
//	//Variables para GUARDAR Key Frames
//	float movDado8_x;		//Variable para PosicionX
//	float movDado8_y;		//Variable para PosicionY
//	float movDado8_xInc;		//Variable para IncrementoX
//	float movDado8_yInc;		//Variable para IncrementoY
//	float giroDado8;
//	float giroDado8Inc;
//}FRAME;
//
//FRAME KeyFrame[MAX_FRAMES];
//int FrameIndex = 4;			//introducir datos
//bool play = false;
//int playIndex = 0;
//
//void resetElements(void) //Tecla 0
//{
//	movDado8_x = KeyFrame[0].movDado8_x;
//	movDado8_y = KeyFrame[0].movDado8_y;
//	giroDado8 = KeyFrame[0].giroDado8;
//}
//
//void interpolation(void)
//{
//	KeyFrame[playIndex].movDado8_xInc = (KeyFrame[playIndex + 1].movDado8_x - KeyFrame[playIndex].movDado8_x) / i_max_steps;
//	KeyFrame[playIndex].movDado8_yInc = (KeyFrame[playIndex + 1].movDado8_y - KeyFrame[playIndex].movDado8_y) / i_max_steps;
//	KeyFrame[playIndex].giroDado8Inc = (KeyFrame[playIndex + 1].giroDado8 - KeyFrame[playIndex].giroDado8) / i_max_steps;
//}
//
//
//void animate(void)
//{
//	//Movimiento del objeto con barra espaciadora
//	if (play)
//	{
//		if (i_curr_steps >= i_max_steps) //fin de animación entre frames?
//		{
//			playIndex++;
//			printf("playindex : %d\n", playIndex);
//			if (playIndex > FrameIndex - 2)	//Fin de toda la animación con último frame?
//			{
//				printf("Frame index= %d\n", FrameIndex);
//				printf("termino la animacion\n");
//				playIndex = 0;
//				play = false;
//			}
//			else //Interpolación del próximo cuadro
//			{
//
//				i_curr_steps = 0; //Resetea contador
//				//Interpolar
//				interpolation();
//			}
//		}
//		else
//		{
//			//Dibujar Animación
//			movDado8_x += KeyFrame[playIndex].movDado8_xInc;
//			movDado8_y += KeyFrame[playIndex].movDado8_yInc;
//			giroDado8 += KeyFrame[playIndex].giroDado8Inc;
//			i_curr_steps++;
//		}
//	}
//}
//
/////////////////* FIN KEYFRAMES*////////////////////////////
//
//
//
//int main()
//{
//	mainWindow = Window(1366, 768); // 1280, 1024 or 1024, 768
//	mainWindow.Initialise();
//
//	CreateObjects();
//	CreateShaders();
//	crearTablero();
//
//	camera = Camera(glm::vec3(60.0f, 30.0f, 70.0f), glm::vec3(0.0f, 1.0f, 0.0f), -130.0f, -30.0f, 0.5f, 0.5f);
//
//	brickTexture = Texture("Textures/brick.png");
//	brickTexture.LoadTextureA();
//	dirtTexture = Texture("Textures/dirt.png");
//	dirtTexture.LoadTextureA();
//	plainTexture = Texture("Textures/plain.png");
//	plainTexture.LoadTextureA();
//	pisoTexture = Texture("Textures/piso.tga");
//	pisoTexture.LoadTextureA();
//	AgaveTexture = Texture("Textures/Agave.tga");
//	AgaveTexture.LoadTextureA();
//	FlechaTexture = Texture("Textures/flechas.tga");
//	FlechaTexture.LoadTextureA();
//	NumerosTexture = Texture("Textures/numerosbase.tga");
//	NumerosTexture.LoadTextureA();
//	Numero1Texture = Texture("Textures/numero1.tga");
//	Numero1Texture.LoadTextureA();
//	Numero2Texture = Texture("Textures/numero2.tga");
//	Numero2Texture.LoadTextureA();
//	Letrero = Texture("Textures/letrero.tga");
//	Letrero.LoadTextureA();
//	tablero = Texture("Textures/monopoly.png");
//	tablero.LoadTextureA();
//	Dado4 = Texture("Textures/dado4.png");
//	Dado4.LoadTextureA();
//
//
//	Kitt_M = Model();
//	Kitt_M.LoadModel("Models/kitt_optimizado.obj");
//	Llanta_M = Model();
//	Llanta_M.LoadModel("Models/llanta_optimizada.obj");
//
//	arco = Model();
//	arco.LoadModel("Models/arco.obj");
//	letrero = Model();
//	letrero.LoadModel("Models/letrero.obj");
//
//	dado8 = Model();
//	dado8.LoadModel("Models/dado_8.obj");
//
//
//
//	std::vector<std::string> skyboxFaces;
//	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_rt.tga");
//	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_lf.tga");
//	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_dn.tga");
//	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_up.tga");
//	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_bk.tga");
//	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_ft.tga");
//
//	skybox = Skybox(skyboxFaces);
//
//	Material_brillante = Material(4.0f, 256);
//	Material_opaco = Material(0.3f, 4);
//
//
//	//luz direccional, sólo 1 y siempre debe de existir
//	mainLight = DirectionalLight(1.0f, 1.0f, 1.0f,
//		0.3f, 0.3f,
//		0.0f, 0.0f, -1.0f);
//	//contador de luces puntuales
//	unsigned int pointLightCount = 0;
//	//Declaración de primer luz puntual
//	pointLights[0] = PointLight(1.0f, 0.0f, 0.0f,
//		0.0f, 1.0f,
//		0.0f, 2.5f, 1.5f,
//		0.3f, 0.2f, 0.1f);
//	pointLightCount++;
//
//	unsigned int spotLightCount = 0;
//	//linterna
//	spotLights[0] = SpotLight(1.0f, 1.0f, 1.0f,
//		0.0f, 2.0f,
//		0.0f, 0.0f, 0.0f,
//		0.0f, -1.0f, 0.0f,
//		1.0f, 0.0f, 0.0f,
//		5.0f);
//	spotLightCount++;
//
//	//luz fija
//	spotLights[1] = SpotLight(0.0f, 0.0f, 1.0f,
//		1.0f, 2.0f,
//		5.0f, 10.0f, 0.0f,
//		0.0f, -5.0f, 0.0f,
//		1.0f, 0.0f, 0.0f,
//		15.0f);
//	spotLightCount++;
//
//
//
//	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0,
//		uniformSpecularIntensity = 0, uniformShininess = 0, uniformTextureOffset = 0;
//	GLuint uniformColor = 0;
//	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 1000.0f);
//
//	movCoche = 0.0f;
//	movOffset = 0.0011f;
//	rotllanta = 0.0f;
//	rotllantaOffset = 10.0f;
//	switch_number = true;
//	movDragon = 0.0f;
//	movDOffset = 0.01f;
//	posy_d = 0.0f;
//	down = true;
//	a_ala = -90.0f;
//	a_ala2 = 90.0f;
//	avanza = true;
//	rot = 0;
//	rotDado_8 = 2.5f;
//	rotDado8 = 0.0f;
//	rotDado4 = 0.0f;
//	rotDado_8Offset = 15.0f;
//	avanza = true;
//	baja = true;
//	srand((unsigned)time(NULL));
//	c = 0;
//	c_2 = 0;
//	salto = 0.0f;
//	movDado8 = 10;
//	glm::vec3 posDado8 = glm::vec3(2.0f, 0.0f, 0.0f);
//	movOffsetLet = 0.9f;
//	rotDado_4 = 0.0f;
//	lastRot = 0.0f;
//	lastRot4 = 0.0f;
//	pasosEnTablero = 0;
//
//	////---------PARA TENER KEYFRAMES GUARDADOS NO VOLATILES QUE SIEMPRE SE UTILIZARAN SE DECLARAN AQUÍ
//
//	//KeyFrame[0].movDado8_x = 0.0f;
//	//KeyFrame[0].movDado8_y = 10.0f;
//	//KeyFrame[0].giroDado8 = 0;
//
//
//	//KeyFrame[1].movDado8_x = -1.0f;
//	//KeyFrame[1].movDado8_y = 5.0f;
//	//KeyFrame[1].giroDado8 = 0;
//
//
//	//KeyFrame[2].movDado8_x = -2.0f;
//	//KeyFrame[2].movDado8_y = 0.0f;
//	//KeyFrame[2].giroDado8 = 0;
//
//
//	//KeyFrame[3].movDado8_x = -3.0f;
//	//KeyFrame[3].movDado8_y = -2.0f;
//	//KeyFrame[3].giroDado8 = 0;
//
//
//	////Loop mientras no se cierra la ventana
//	while (!mainWindow.getShouldClose())
//	{
//		GLfloat now = glfwGetTime();
//		deltaTime = now - lastTime;
//		deltaTime += (now - lastTime) / limitFPS;
//		lastTime = now;
//
//		//activar tirar dados
//		/*if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_T)) {
//			salto = 3.5;
//			srand((unsigned)time(NULL));
//			c = (rand() % 5) + 1;
//			srand((unsigned)time(NULL));
//			c_2 = (rand() % 3) + 1;
//			movDado8 = 10;
//			rotDado8 = 0;
//			rotDado_4 = 0;
//			lastRot4 = 0;
//			pasosEnTablero += (c + c_2);
//			printf("avanza: %d\n", pasosEnTablero);
//		}*/
//
//		if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_T) && alternar) {
//			salto = 3.5;
//			srand((unsigned)time(NULL));
//			c = (rand() % 5) + 1;
//			srand((unsigned)time(NULL));
//			c_2 = (rand() % 3) + 1;
//			movDado8 = 10;
//			rotDado8 = 0;
//			rotDado_4 = 0;
//			lastRot4 = 0;
//			pasosEnTablero += (c + c_2);
//			printf("avanza: %d\n", pasosEnTablero);
//			alternar = false;
//		}
//		if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_T) == GLFW_RELEASE) {
//			alternar = true;
//		}
//
//		//logica de dado
//		if (salto > 0) {
//			if (baja) {
//				if (movDado8 > 0.0f) {
//					movDado8 -= movOffsetLet * deltaTime;
//				}
//				else {
//					rotDado_8 += rotDado_8Offset * deltaTime;
//					rotDado_4 += rotDado_8Offset * deltaTime;
//					salto -= 0.5;
//					baja = false;
//				}
//			}
//			else {
//				if (movDado8 <= (salto * 2)) {
//					movDado8 += movOffsetLet * deltaTime;
//				}
//				else {
//					baja = true;
//					salto -= 0.5;
//					rotDado_8 += rotDado_8Offset * deltaTime;
//					rotDado_4 += rotDado_8Offset * deltaTime;
//				}
//			}
//		}
//		else {
//			if (c ==1 ||c == 2 || c==5 || c== 6) {
//					rotDado_8 = 2.5f;
//					rotDado8 = 50;
//					lastRot = 0;		//cara 2
//					if (c == 6) {
//						lastRot = 90;
//					}
//					if (c == 5) {
//						lastRot = -90;
//					}
//					if (c == 1) {
//						lastRot = 180;
//					}
//
//			}else if (c == 3 || c==4 || c==7 ||c ==8) {
//				rotDado_8 = 4.5f;
//				rotDado8 = 126;
//				lastRot = 0;			//cara 8
//				if (c == 4) {
//					lastRot = 90;
//				}
//				if (c == 3) {
//					lastRot = -90;
//				}
//				if (c == 7) {
//					lastRot = 180;
//				}
//			}
//
//			if (c_2 % 2 == 0) {
//				if (c_2 == 2) {
//					rotDado_4 = 260;
//					lastRot4 = -25;
//				}
//				else if (c_2 == 4) {
//					rotDado_4 = 105;
//					lastRot4 = 27;
//				}
//			}
//			else {
//				if (c_2 == 1) {
//					rotDado_4 = 0;
//					lastRot4 = 0;
//				}
//				else {
//					rotDado_4 = 115;
//					lastRot4 = -90;//cara 8
//				}
//			}
//
//		}
//
//		//angulovaria += 0.5f * deltaTime;
//		//posy_d = 10.0f + sin(glm::radians(angulovaria));
//
//		//if (movCoche < 30.0f)
//		//{
//		//	movCoche -= movOffset * deltaTime;
//		//	//printf("avanza%f \n ",movCoche);
//		//	rotllanta += rotllantaOffset * deltaTime;
//		//}
//
//		////despl dragon
//		//if (avanza) {
//		//	if (movDragon > -4)
//		//	{
//		//		movDragon -= movDOffset * deltaTime;
//		//	}
//		//	else {
//		//		avanza = false;
//		//		rot = 180;
//		//	}
//		//}
//		//else {
//		//	if (movDragon < 4) {
//		//		movDragon += movDOffset * deltaTime;
//		//	}
//		//	else {
//		//		avanza = true;
//		//		rot = 0;
//		//	}
//		//}
//
//		////mov alas
//		//if (posy_d < 9.000001 && down == true) {
//		//	down = false;
//		//}
//		//else if (posy_d > 10.9000001 && down == false) {
//		//	down = true;
//		//}
//		//if (down && a_ala < 0) {
//		//	a_ala += 0.0075;
//		//	a_ala2 -= 0.0075;
//		//}
//		//else if (!down && a_ala > -90) {
//		//	a_ala -= 0.0075;
//		//	a_ala2 += 0.0075;
//		//}
//
//
//		//Recibir eventos del usuario
//		glfwPollEvents();
//		camera.keyControl(mainWindow.getsKeys(), deltaTime);
//		camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());
//
//		// Clear the window
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		skybox.DrawSkybox(camera.calculateViewMatrix(), projection);
//		shaderList[0].UseShader();
//		uniformModel = shaderList[0].GetModelLocation();
//		uniformProjection = shaderList[0].GetProjectionLocation();
//		uniformView = shaderList[0].GetViewLocation();
//		uniformEyePosition = shaderList[0].GetEyePositionLocation();
//		uniformColor = shaderList[0].getColorLocation();
//		uniformTextureOffset = shaderList[0].getOffsetLocation();
//
//		//información en el shader de intensidad especular y brillo
//		uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
//		uniformShininess = shaderList[0].GetShininessLocation();
//
//		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
//		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
//		glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z);
//
//		// luz ligada a la cámara de tipo flash
//		glm::vec3 lowerLight = camera.getCameraPosition();
//		lowerLight.y -= 0.3f;
//		spotLights[0].SetFlash(lowerLight, camera.getCameraDirection());
//
//		//información al shader de fuentes de iluminación
//		shaderList[0].SetDirectionalLight(&mainLight);
//		shaderList[0].SetPointLights(pointLights, pointLightCount);
//		shaderList[0].SetSpotLights(spotLights, spotLightCount);
//
//
//
//		glm::mat4 model(1.0);
//		glm::mat4 modelaux(1.0);
//		glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
//		glm::vec2 toffset = glm::vec2(0.0f, 0.0f);
//
//		glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
//		model = glm::mat4(1.0);
//		model = glm::translate(model, glm::vec3(0.0f, -2.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(30.0f, 1.0f, 30.0f));
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
//		pisoTexture.UseTexture();
//		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
//
//		meshList[2]->RenderMesh();
//
//		model = glm::mat4(1.0);
//		model = glm::translate(model, glm::vec3(0.0f, -1.8f, 0.0f));
//		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(5.0f, 1.0f, 5.0f));
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		tablero.UseTexture();
//		meshList[9]->RenderMesh();
//
//		//Instancia del dado de 8 caras 
//		model = glm::mat4(1.0);
//		posDado8 = glm::vec3(posXDado8 - salto, movDado8, posZDado8);
//		model = glm::translate(model, posDado8);
//		model = glm::scale(model, glm::vec3(4.5f, 4.5f, 4.5f));
//
//		model = glm::rotate(model, -90 * rotDado_8 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
//		model = glm::rotate(model, float(-rotDado8 * toRadians), glm::vec3(0.0f, 0.0f, 1.0f));
//		model = glm::rotate(model, lastRot * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
//		Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		dado8.RenderModel();
//
//		//Instancia del dado de 4 caras
//		model = glm::mat4(1.0);
//		posDado8 = glm::vec3(posXDado8 +5 + salto, movDado8, posZDado8 - 15);
//		model = glm::translate(model, posDado8);
//		model = glm::scale(model, glm::vec3(4.5f, 4.5f, 4.5f));
//
//		model = glm::rotate(model, -90 * rotDado_8 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
//		model = glm::rotate(model, float(rotDado_4 * toRadians), glm::vec3(0.0f, 0.0f, 1.0f));
//		model = glm::rotate(model, lastRot4 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		Dado4.UseTexture();
//		meshList[8]->RenderMesh();
//
//
//		////Instancia del coche 
//		//model = glm::mat4(1.0);
//		//model = glm::translate(model, glm::vec3(movCoche - 50.0f, 0.5f, -2.0f));
//		//modelaux = model;
//		//model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
//		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//Kitt_M.RenderModel();
//
//		////Llanta delantera izquierda
//		//model = modelaux;
//		//model = glm::translate(model, glm::vec3(7.0f, -0.5f, 8.0f));
//		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
//		//model = glm::rotate(model, rotllanta * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		//model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
//		//color = glm::vec3(0.5f, 0.5f, 0.5f);//llanta con color gris
//		//glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//Llanta_M.RenderModel();
//
//		////Llanta trasera izquierda
//		//model = modelaux;
//		//model = glm::translate(model, glm::vec3(15.5f, -0.5f, 8.0f));
//		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
//		//model = glm::rotate(model, rotllanta * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		//model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//Llanta_M.RenderModel();
//
//		////Llanta delantera derecha
//		//model = modelaux;
//		//model = glm::translate(model, glm::vec3(7.0f, -0.5f, 1.5f));
//		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
//		//model = glm::rotate(model, -rotllanta * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		//model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//Llanta_M.RenderModel();
//
//		////Llanta trasera derecha
//		//model = modelaux;
//		//model = glm::translate(model, glm::vec3(15.5f, -0.5f, 1.5f));
//		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
//		//model = glm::rotate(model, -rotllanta * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		//model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//Llanta_M.RenderModel();
//
//
//		//model arco
//		model = glm::mat4(1.0);
//		model = glm::translate(model, glm::vec3(40.0f, -0.8f, 43.5f));
//		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
//		modelaux = model;
//		model = glm::scale(model, glm::vec3(0.40f, 0.5f, 0.5f));
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		arco.RenderModel();
//
//		//modelo tabla de letrero
//		model = modelaux;
//		model = glm::translate(model, glm::vec3(1.2f, 11.8f, -.5f));
//		modelaux = model;
//		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
//		model = glm::rotate(model, 15 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		letrero.RenderModel();
//
//
//		//textura con movimiento
//		//Importantes porque la variable uniform no podemos modificarla directamente
//		toffsetletrerou -= 0.0001;
//		toffsetletrerov = 0.000;
//		//para que no se desborde la variable
//		if (toffsetletrerou < -1.0)
//			toffsetletrerou = 0.0;
//		//pasar a la variable uniform el valor actualizado
//		toffset = glm::vec2(toffsetletrerou, toffsetletrerov);
//
//		model = modelaux;
//		model = glm::translate(model, glm::vec3(-.9f, 1.0f, .48f));
//		model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(4.6f, 2.5f, 2.5f));
//		glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		/*color = glm::vec3(0.0f, 1.0f, 0.0f);*/
//		/*glUniform3fv(uniformColor, 1, glm::value_ptr(color));*/
//		Letrero.UseTexture();
//		Material_brillante.UseMaterial(0, 0);
//		meshList[7]->RenderMesh();
//
//		color = glm::vec3(0.6f, .6f, 0.6f);
//
//
//		////modelo dragon
//		//model = glm::mat4(1.0);
//		//model = glm::translate(model, glm::vec3(0.0f, 5.0f + sin(glm::radians(angulovaria)), 6.0));
//		//model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
//		//model = glm::rotate(model, -90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		//Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		///*color = glm::vec3(0.0f, 1.0f, 0.0f);
//		//glUniform3fv(uniformColor, 1, glm::value_ptr(color));*/
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//Dragon_M.RenderModel();
//
//		////dragon segmentado
//		////+ sin(glm::radians(angulovaria))
//		//model = glm::mat4(1.0);
//		//model = glm::translate(model, glm::vec3(movDragon, posy_d, 6.0));
//		//model = glm::rotate(model, rot * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
//		//modelaux = model;
//		//model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
//		//model = glm::rotate(model, toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		//Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		///*color = glm::vec3(0.0f, 1.0f, 0.0f);
//		//glUniform3fv(uniformColor, 1, glm::value_ptr(color));*/
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//Body_D.RenderModel();
//
//		//model = modelaux;
//		//model = glm::translate(model, glm::vec3(1.0f, 0.0f, -0.24f));
//		//model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
//		////model = glm::rotate(model, toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		//model = glm::rotate(model, a_ala * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		//Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		///*color = glm::vec3(0.0f, 1.0f, 0.0f);
//		//glUniform3fv(uniformColor, 1, glm::value_ptr(color));*/
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//Ala_der.RenderModel();
//
//		//model = modelaux;
//		//model = glm::translate(model, glm::vec3(1.0f, 0.0f, 0.24f));
//		//model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
//		//model = glm::rotate(model, a_ala2 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		//Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		///*color = glm::vec3(0.0f, 1.0f, 0.0f);
//		//glUniform3fv(uniformColor, 1, glm::value_ptr(color));*/
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//Ala_izq.RenderModel();
//
//		////heads
//		//model = modelaux;
//		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
//		//model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
//		///*model = glm::rotate(model, toRadians, glm::vec3(1.0f, 0.0f, 0.0f));*/
//		////model = glm::rotate(model, e_z , glm::vec3(1.0f, 0.0f, 0.0f));
//		//model = glm::rotate(model, e_z, glm::vec3(0.0f, 0.0f, 1.0f));
//		//Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		//color = glm::vec3(1.0f, 0.0f, 0.0f);
//		//glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//dh1.RenderModel();
//
//
//		//model = modelaux;
//		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
//		//model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
//		//model = glm::rotate(model, val, glm::vec3(0.0f, 1.0f, .0f));
//		//Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		//color = glm::vec3(0.0f, 0.0f, 1.0f);
//		//glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//dh2.RenderModel();
//
//		//model = modelaux;
//		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
//		//model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
//		//model = glm::rotate(model, val_c, glm::vec3(1.0f, 0.0f, 0.0f));
//		//Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		//color = glm::vec3(0.0f, 1.0f, 0.0f);
//		//glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//dh3.RenderModel();
//
//		//model = modelaux;
//		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
//		//model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
//		//model = glm::rotate(model, val_o, glm::vec3(1.0f, 1.0f, 0.0f));
//		//Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		//color = glm::vec3(1.0f, 1.0f, 1.0f);
//		//glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//dh4.RenderModel();
//
//		//model = modelaux;
//		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
//		//model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
//		//model = glm::rotate(model, val_l, glm::vec3(1.0f, 0.0f, 1.0f));
//		//Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		//color = glm::vec3(.8f, .5f, 0.3f);
//		//glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//dh5.RenderModel();
//
//
//
//		toffset = glm::vec2(0.0f, 0.0f);
//		/*color = glm::vec3(1.0f, 1.0f, 1.0f);
//		glUniform3fv(uniformColor, 1, glm::value_ptr(color));*/
//		//Agave ¿qué sucede si lo renderizan antes del coche y de la pista?
//		model = glm::mat4(1.0);
//		model = glm::translate(model, glm::vec3(0.0f, 0.5f, -2.0f));
//		model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
//		glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		//blending: transparencia o traslucidez
//		glEnable(GL_BLEND);
//		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//		AgaveTexture.UseTexture();
//		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		meshList[3]->RenderMesh();
//
//		//textura con movimiento
//		//Importantes porque la variable uniform no podemos modificarla directamente
//		toffsetflechau += 0.001;
//		toffsetflechav = 0.000;
//		//para que no se desborde la variable
//		if (toffsetflechau > 1.0)
//			toffsetflechau = 0.0;
//		//if (toffsetv > 1.0)
//		//	toffsetv = 0;
//		//printf("\ntfosset %f \n", toffsetu);
//		//pasar a la variable uniform el valor actualizado
//		toffset = glm::vec2(toffsetflechau, toffsetflechav);
//
//		model = glm::mat4(1.0);
//		model = glm::translate(model, glm::vec3(-2.0f, 1.0f, -6.0f));
//		model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
//		glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		color = glm::vec3(1.0f, 0.0f, 0.0f);
//		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		FlechaTexture.UseTexture();
//		Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		meshList[4]->RenderMesh();
//
//		//plano con todos los números
//		toffsetnumerou = 0.0;
//		toffsetnumerov = 0.0;
//		toffset = glm::vec2(toffsetnumerou, toffsetnumerov);
//		model = glm::mat4(1.0);
//		model = glm::translate(model, glm::vec3(-6.0f, 2.0f, -6.0f));
//		model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
//		glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		color = glm::vec3(1.0f, 1.0f, 1.0f);
//		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		NumerosTexture.UseTexture();
//		Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		meshList[5]->RenderMesh();
//
//		//número 1
//		//toffsetnumerou = 0.0;
//		//toffsetnumerov = 0.0;
//		model = glm::mat4(1.0);
//		model = glm::translate(model, glm::vec3(-10.0f, 2.0f, -6.0f));
//		model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
//		//glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		color = glm::vec3(1.0f, 1.0f, 1.0f);
//		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		NumerosTexture.UseTexture();
//		Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		meshList[6]->RenderMesh();
//
//		for (int i = 1; i < 4; i++)
//		{
//			//números 2-4
//			toffsetnumerou += 0.25;
//			toffsetnumerov = 0.0;
//			toffset = glm::vec2(toffsetnumerou, toffsetnumerov);
//			model = glm::mat4(1.0);
//			model = glm::translate(model, glm::vec3(-10.0f - (i * 3.0), 2.0f, -6.0f));
//			model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//			model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
//			glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
//			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//			color = glm::vec3(1.0f, 1.0f, 1.0f);
//			glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//			NumerosTexture.UseTexture();
//			Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//			meshList[6]->RenderMesh();
//
//		}
//
//		for (int j = 1; j < 5; j++)
//		{
//			//números 5-8
//			toffsetnumerou += 0.25;
//			toffsetnumerov = -0.33;
//			toffset = glm::vec2(toffsetnumerou, toffsetnumerov);
//			model = glm::mat4(1.0);
//			model = glm::translate(model, glm::vec3(-7.0f - (j * 3.0), 5.0f, -6.0f));
//			model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//			model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
//			glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
//			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//			color = glm::vec3(1.0f, 1.0f, 1.0f);
//			glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//			NumerosTexture.UseTexture();
//			Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//			meshList[6]->RenderMesh();
//		}
//
//
//		//número cambiante 
//		/*
//		¿Cómo hacer para que sea a una velocidad visible?
//		*/
//		toffsetnumerocambiau += 0.0001;
//		if (toffsetnumerocambiau > 1.0)
//			toffsetnumerocambiau = 0.0;
//		toffsetnumerov = 0.0;
//		toffset = glm::vec2(toffsetnumerocambiau, toffsetnumerov);
//		model = glm::mat4(1.0);
//		model = glm::translate(model, glm::vec3(-10.0f, 10.0f, -6.0f));
//		model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
//		glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		color = glm::vec3(1.0f, 1.0f, 1.0f);
//		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		NumerosTexture.UseTexture();
//		Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		meshList[6]->RenderMesh();
//
//
//		//cambiar entre textura número 1 y número 2
//
//		//if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_T) && alternar) {
//		//	switch_number = !switch_number;
//		//	alternar = false;
//		//}
//		//if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_T) == GLFW_RELEASE) {
//		//	alternar = true;
//		//}
//
//		toffsetnumerou = 0.0;
//		toffsetnumerov = 0.0;
//		toffset = glm::vec2(toffsetnumerou, toffsetnumerov);
//		model = glm::mat4(1.0);
//		model = glm::translate(model, glm::vec3(-13.0f, 10.0f, -6.0f));
//		model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
//		glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		color = glm::vec3(1.0f, 1.0f, 1.0f);
//		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
//		//Numero1Texture.UseTexture();
//
//		if (switch_number) {
//			Numero1Texture.UseTexture();
//		}
//		else {
//			Numero2Texture.UseTexture();
//		}
//
//		Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
//		meshList[5]->RenderMesh();
//
//
//
//		if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_T))
//		{
//			if (reproduciranimacion < 1)
//			{
//				if (play == false && (FrameIndex > 1))
//				{
//					resetElements();
//					//First Interpolation				
//					interpolation();
//					play = true;
//					playIndex = 0;
//					i_curr_steps = 0;
//					reproduciranimacion++;
//					printf("\n presiona 0 para habilitar reproducir de nuevo la animación'\n");
//					habilitaranimacion = 0;
//
//				}
//				else
//				{
//					play = false;
//
//				}
//			}
//		}
//		if (glfwGetKey(mainWindow.getMainWindow(), GLFW_KEY_Y))
//		{
//			if (habilitaranimacion < 1 && reproduciranimacion>0)
//			{
//				printf("Ya puedes reproducir de nuevo la animación con la tecla de barra espaciadora'\n");
//				reproduciranimacion = 0;
//
//			}
//		}
//
//
//		glDisable(GL_BLEND);
//
//
//
//
//
//		glUseProgram(0);
//
//		mainWindow.swapBuffers();
//	}
//
//	return 0;
//}
