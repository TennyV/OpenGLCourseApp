#include <stdio.h> // standard input output library
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;


// window dimensions
const GLint WIDTH = 800, HEIGHT = 600;



int main()
{

	//initialize GLFW

	if (!glfwInit())
	{
		printf("GLFW inizialiation failed!");
		glfwTerminate();
		return 1; // return bug/issue
	}

	// set up GLFW window properties
	// OPENLG Version

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // set major version to 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // set minor version to 3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // how to treat the core profile... don't use deprecated versions
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // allowing forward compatibility

	//create window     // glfwCreateWindow function is built in
	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Window", NULL, NULL);
	
	if (!mainWindow)
	{
		printf("GLFW window creation failed!");
		glfwTerminate();
		return 1;
	}

	//get buffer size information   get dimension of the area within the window
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, & bufferHeight);  //reference to buffer height and width


	// Set context for GLEW to use
	glfwMakeContextCurrent(mainWindow); // use the current window

	//Allow modern extension features
	glewExperimental = GL_TRUE;


	// initialize GLEW, but if GLEW fails.... then
	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initilization failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	};

	// set up viewport size

	glViewport(0, 0, bufferWidth, bufferHeight);

	// loop unitl window closed

	while (!glfwWindowShouldClose(mainWindow))  // specify which window
	{
		// Get + handle user input events
		glfwPollEvents();  // GLFW feature
		
		
		//clear window,, fresh start

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);  //clear everything to include depth data and stencil data

		glfwSwapBuffers(mainWindow); // 
	}


	return 0;
}