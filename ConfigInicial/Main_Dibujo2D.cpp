/*
Practica #2. Dibujo de primitivas en 2D                 |   Sánchez López Osvaldo
Fecha de entrega: 24 de febrero de 2026                 |   No. Cuenta: 318211396
*/

#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificaci�n de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Sánchez López Osvaldo", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificaci�n de errores de creacion  ventana
	if (window== NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificaci�n de errores de inicializaci�n de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Sanchez Lopez Osvaldo " << std::endl;
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	// Define las dimensiones del viewport
	//glViewport(0, 0, screenWidth, screenHeight);

	//Primer cambio significativo: se carga la información de los archivos que se tiene por
	//separado, siendo el shaders de vertices (core.vs) y el shader de fragmentos (core.frag)
    Shader ourShader("Shader/core.vs", "Shader/core.frag");

	// Set up vertex data (and buffer(s)) and attribute pointers
	//Aquí, a diferencia del código anterior, se tiene la posición de cada uno de los vertices,
	//dado que se va a trabajar en 2D, la componente Z (profundidad) se deja en 0
	// al lado está el color que van a tener cada uno de los atributos de los vertices, están
	//en formato o modelo de color RGB
	/*float vertices[] = {
		0.5f,  0.5f, 0.0f,    1.0f,1.0f,0.0f,  // top right
		0.5f, -0.5f, 0.0f,    1.0f,1.0f,0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,   1.0f,0.0f,1.0f,  // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f,1.0f,0.0f, // top left 
	};

	//Sección de los indices que tiene cada uno de los vertices que se va a ocupara para dibujar
	//cada uno de los vertices con diferentes funciones.
	unsigned int indices[] = {  // note that we start from 0!
		3,2,1,// second Triangle
		0,1,3,
		
	};*/

	float vertices[] = {
		// Posición (X, Y, Z)     // Color (R, G, B) - Puse todo de Naranja
		-0.8438f,   0.9062f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 0 (Pixel: 40,24)
		-0.6133f,   0.8555f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 1 (Pixel: 99,37)
		-0.7305f,   0.7695f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 2 (Pixel: 69,59)
		-0.7891f,   0.7109f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 3 (Pixel: 54,74)
		-0.6875f,   0.6836f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 4 (Pixel: 80,81)
		-0.7227f,   0.8398f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 5 (Pixel: 71,41)
		-0.4258f,   0.8359f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 6 (Pixel: 147,42)
		-0.5469f,   0.7734f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 7 (Pixel: 116,58)
		-0.7852f,   0.5273f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 8 (Pixel: 55,121)
		-0.5000f,   0.6367f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 9 (Pixel: 128,93)
		-0.5820f,   0.4180f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 10 (Pixel: 107,149)
		-0.2656f,   0.6836f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 11 (Pixel: 188,81)
		-0.6797f,   0.3789f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 12 (Pixel: 82,159)
		-0.7461f,   0.4727f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 13 (Pixel: 65,135)
		-0.8125f,   0.4414f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 14 (Pixel: 48,143)
		-0.2148f,   0.4648f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 15 (Pixel: 201,137)
		-0.6250f,   0.1875f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 16 (Pixel: 96,208)
		-0.4414f,  -0.1250f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 17 (Pixel: 143,288)
		-0.0234f,   0.2852f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 18 (Pixel: 250,183)
		 0.0781f,  -0.4336f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 19 (Pixel: 276,367)
		 0.0234f,  -0.0625f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 20 (Pixel: 262,272)
		 0.2930f,   0.1211f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 21 (Pixel: 331,225)
		 0.4219f,  -0.3047f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 22 (Pixel: 364,334)
		 0.4336f,  -0.6719f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 23 (Pixel: 367,428)
		 0.0586f,  -0.9023f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 24 (Pixel: 271,487)
		 0.6758f,  -0.8984f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 25 (Pixel: 429,486)
		 0.8438f,  -0.6719f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 26 (Pixel: 472,428)
		 0.5352f,  -0.7539f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 27 (Pixel: 393,449)
		 0.6055f,  -0.2461f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 28 (Pixel: 411,319)
		 0.5898f,  -0.4375f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 29 (Pixel: 407,368)
		 0.6836f,  -0.7109f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 30 (Pixel: 431,438)
		 0.8164f,  -0.1445f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 31 (Pixel: 465,293)
		 0.6953f,  -0.4062f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 32 (Pixel: 434,360)
		-0.5391f,  -0.4961f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 33 (Pixel: 118,383)
		-0.3633f,  -0.4062f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 34 (Pixel: 163,360)
		-0.2773f,  -0.2305f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 35 (Pixel: 185,315)
		-0.2148f,  -0.7188f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 36 (Pixel: 201,440)
		-0.3828f,  -0.7383f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 37 (Pixel: 158,445)
		-0.3125f,  -0.5273f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 38 (Pixel: 176,391)
		-0.3828f,  -0.9023f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 39 (Pixel: 158,487)
		-0.0547f,  -0.8984f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 40 (Pixel: 242,486)
		-0.4688f,  -0.7891f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 41 (Pixel: 136,458)
		-0.5625f,  -0.8320f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 42 (Pixel: 112,469)
		-0.4375f,  -0.8320f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 43 (Pixel: 144,469)
		-0.5977f,  -0.7500f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 44 (Pixel: 103,448)
		-0.5312f,  -0.7070f, 0.0f,   1.0f, 0.64f, 0.0f, // Indice 45 (Pixel: 120,437)
	};

	unsigned int indices[] = {
		 0,  1,  0,  2,  2,  1,  3,  1,  3,  4,  4,  5,
		 4,  6,  5,  7,  1,  6,  3,  8,  4,  8,  4,  9,
		 9,  7,  4, 10, 10,  6,  6, 11, 10, 11, 10, 12,
		12, 13, 13, 14, 14, 12, 14,  8,  8, 13, 11, 15,
		10, 15, 15, 16, 16, 10, 16, 17, 17, 15, 15, 18,
		18, 17, 17, 19, 19, 18, 17, 20, 18, 21, 21, 19,
		19, 22, 22, 21, 22, 23, 23, 19, 19, 24, 24, 23,
		24, 25, 25, 23, 25, 26, 26, 27, 26, 28, 29, 30,
		29, 28, 28, 31, 31, 32, 17, 33, 33, 34, 34, 35,
		34, 19, 19, 36, 36, 34, 36, 37, 37, 38, 36, 39,
		39, 24, 36, 40, 39, 41, 41, 37, 42, 43, 42, 44,
		44, 45, 45, 33,

		// ÍNDICES PARA LOS TRIÁNGULOS
		12, 13, 14,  // Triángulo 1
		18, 17, 19,  // Triángulo 2
		21, 19, 22,  // Triángulo 3
		23, 19, 24,  // Triángulo 4
		34, 19, 36   // Triángulo 5
	};

	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)


	
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Draw our first triangle
        ourShader.Use();
        glBindVertexArray(VAO);

		// Draw our first triangle -> Ahora dibuja el Gato
		ourShader.Use();
		glBindVertexArray(VAO);

		// Uso de GL_TRIANGLES  para los triangulos que mapee
		// Son 15 índices. Se empieza a leer a partir del índice 136.
		// (136 * sizeof(unsigned int)) es el offset (desplazamiento) en memoria.
		glDrawElements(GL_TRIANGLES, 15, GL_UNSIGNED_INT, (void*)(136 * sizeof(unsigned int)));

		// Agregué un grosor de 4 para que se vea mejor.
		glLineWidth(4.0f);

		// Uso de GL_LINES para las lineas
		// Hay 136 índices en total (lo que equivale a 68 líneas)
		// Son 136 índices.Empezamos a leer desde el inicio(offset 0).
		glDrawElements(GL_LINES, 136, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

        //glPointSize(10);
        //glDrawArrays(GL_POINTS,0,4);
        
        //glDrawArrays(GL_LINES,0,4);
        //glDrawArrays(GL_LINE_LOOP,0,4);
        
       // glDrawArrays(GL_TRIANGLES,1,3);
        //glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT,0);

        
        
        glBindVertexArray(0);
    
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}