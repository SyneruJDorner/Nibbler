
#include "LibGLFW.hpp"

extern "C" IGraphicsLib *createLib()
{
    return new LibGLFW;
}

extern "C" void destroyLib(IGraphicsLib* instance)
{
    instance->terminateWindow();
    delete instance;
}

e_GraphicLibInput LibGLFW::status = STD;

/*
const GLfloat LibGLFW::g_vertex_buffer_data[9] = {
   -0.1f, -0.1f, 0.0f,
   0.1f, -0.1f, 0.0f,
   0.0f,  0.1f, 0.0f,
};
*/

void LibGLFW::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
            case GLFW_KEY_ESCAPE:
                glfwDestroyWindow(window);
                glfwTerminate();
                LibGLFW::status = ESCAPE;
                break;
            case GLFW_KEY_F1:
                LibGLFW::status = GLFW;
                break;
            case GLFW_KEY_F2:
                LibGLFW::status = SDL2;
                break;
            case GLFW_KEY_F3:
                LibGLFW::status = SFML;
                break;
            case GLFW_KEY_A:
                std::cout << "Event GLFW key A" << std::endl;
                LibGLFW::status = LEFT;
                break;
            case GLFW_KEY_D:
                std::cout << "Event GLFW key D" << std::endl;
                LibGLFW::status = RIGHT;
                break;
            case GLFW_KEY_W:
                std::cout << "Event GLFW key W" << std::endl;
                LibGLFW::status = UP;
                break;
            case GLFW_KEY_S:
                std::cout << "Event GLFW key S" << std::endl;
                LibGLFW::status = DOWN;
                break;
            default:
                LibGLFW::status = STD;
                break;
        }
    }
    else
        LibGLFW::status = STD;
    (void)scancode;
    (void)mods;
}

LibGLFW::LibGLFW(void)
{
    window = NULL;
    LibGLFW::status = STD;
    return ;
}

LibGLFW::~LibGLFW(void)
{
    return ;
}

LibGLFW::LibGLFW(const LibGLFW &other)
{
    *this = other;
}


GLuint LibGLFW::LoadShaders(const char * vertex_file_path,const char * fragment_file_path){

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if(VertexShaderStream.is_open()){
		std::stringstream sstr;
		sstr << VertexShaderStream.rdbuf();
		VertexShaderCode = sstr.str();
		VertexShaderStream.close();
	}else{
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		getchar();
		return 0;
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if(FragmentShaderStream.is_open()){
		std::stringstream sstr;
		sstr << FragmentShaderStream.rdbuf();
		FragmentShaderCode = sstr.str();
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}

	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}

	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> ProgramErrorMessage(InfoLogLength+1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}
	
	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);
	
	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}

LibGLFW *LibGLFW::operator=(const LibGLFW &other)
{
    (void)other;
    return this;
}

void LibGLFW::init(int width, int height, std::string title)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glfwSetErrorCallback([](int thing, const char *str) {
        std::cout << thing << ": " << str << std::endl;
    });


    this->window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    if (window == NULL)
    {
        glfwTerminate();
        throw GraphicLibraryExceptions::CreateWindowFailedException();
    }

    glfwSetKeyCallback(this->window, keyboardCallback);
    glfwMakeContextCurrent(this->window);

    gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress));
    glGenVertexArrays(1, &this->vertexArrayID);
    glBindVertexArray(this->vertexArrayID);

    //Load Shaders
    this->programID = LoadShaders( "./shaders/SimpleVertexShader.vertexshader", "./shaders/SimpleFragmentShader.fragmentshader" );


    glMatrixMode(GL_PROJECTION); //determines the properties of the camera that views the objects in the world coordinate frame.

    glLoadIdentity(); //replace the current matrix with the identity Matrix, and starts afresh, because matrix transforms such as glOrtho and glRotate cumulate, so this basically puts us at (0, 0, 0)

    //glFrustum(0, 1, 1, 0, 0, 100);
    glOrtho(0, width, 0, height, -1, 1); //basically setting the coordinate system.
    glViewport(0.0f, 0.0f, 640, 480); //the part the openGL will draw (in pixels).

    glMatrixMode(GL_MODELVIEW); //(default matrix mode), defines how your objects are transformed (rotation, translation, scaling) in your world.

    glLoadIdentity();

    /*
    //int screenWidth, screenHeight;

    //glfwGetFramebufferSize(this->window, &screenWidth, &screenHeight);


    //glMatrixMode(GL_PROJECTION); //determines the properties of the camera that views the objects in the world coordinate frame.

    //glLoadIdentity(); //replace the current matrix with the identity Matrix, and starts afresh, because matrix transforms such as glOrtho and glRotate cumulate, so this basically puts us at (0, 0, 0)

    //glFrustum(0, 1, 1, 0, 0, 100);
    //glOrtho(0, width, 0, height, -1, 1); //basically setting the coordinate system.

    // glMatrixMode(GL_MODELVIEW); //(default matrix mode), defines how your objects are transformed (rotation, translation, scaling) in your world.

    // glLoadIdentity();

    */

}

e_GraphicLibInput LibGLFW::events()
{
    glfwPollEvents();
    return LibGLFW::status;
}

void LibGLFW::updateDisplay()
{
    //glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    int ind = 0;
    glGenBuffers(this->buffers.size(), &this->vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

    for (auto i = this->buffers.begin(); i != this->buffers.end(); ++i)
    {
        // Give our vertices to OpenGL.
        glBufferData(GL_ARRAY_BUFFER, sizeof(*i), *i, GL_STATIC_DRAW);
        
        //glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

        // Use our shader
        glUseProgram(programID);

        glEnableVertexAttribArray(0);
        
        glVertexAttribPointer(
            ind,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4); // Starting from vertex 0; 3 vertices total -> 1 triangle
        // Draw the triangle !
        glDisableVertexAttribArray(0);
        ind++;
    }

    glfwSwapBuffers(this->window);
    this->buffers.clear();

    return ;
}

GLfloat LibGLFW::screenPosX(float pixelPos)
{
    return static_cast<GLfloat>(2.0f * (pixelPos + 0.5f) / 640 - 1.0f);
}

GLfloat LibGLFW::screenPosY(float pixelPos)
{
    return static_cast<GLfloat>(2.0f * (pixelPos + 0.5f) / 480 - 1.0f);
}

void LibGLFW::draw(Vector2 point)
{
    int blockSize = 30;
    GLfloat g_vertex_buffer_data[] = {
        screenPosX((point.x * 10) + (blockSize/2)), screenPosY((point.y * 10) + (blockSize/2)), 0,
        screenPosX((point.x * 10) - (blockSize/2)), screenPosY((point.y * 10) + (blockSize/2)), 0,
        screenPosX((point.x * 10) + (blockSize/2)), screenPosY((point.y * 10) - (blockSize/2)), 0,
        screenPosX((point.x * 10) - (blockSize/2)), screenPosY((point.y * 10) - (blockSize/2)), 0
    };

    this->buffers.push_back(g_vertex_buffer_data);

    /*
    int blockSize = 30;
    const GLfloat g_vertex_buffer_data[] = {
        screenPosX((point.x * 10) + (blockSize/2)), screenPosY((point.y * 10) + (blockSize/2)), 0,
        screenPosX((point.x * 10) - (blockSize/2)), screenPosY((point.y * 10) + (blockSize/2)), 0,
        screenPosX((point.x * 10) + (blockSize/2)), screenPosY((point.y * 10) - (blockSize/2)), 0,
        screenPosX((point.x * 10) - (blockSize/2)), screenPosY((point.y * 10) - (blockSize/2)), 0
    };
    */

    /*
    static const GLfloat g_vertex_buffer_data[12] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
        0.5f,  0.5f, 0.0f,
    };
    */


    //glGenBuffers(1, &this->vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    //glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);


    /*
    int blockSize = 30;
    GLfloat vertices[] = {
        static_cast<GLfloat>((point.x * 10) - (blockSize/2)), static_cast<GLfloat>((point.y * 10) - (blockSize/2)), 0,
        static_cast<GLfloat>((point.x * 10) + (blockSize/2)), static_cast<GLfloat>((point.y * 10) - (blockSize/2)), 0,
        static_cast<GLfloat>((point.x * 10) - (blockSize/2)), static_cast<GLfloat>((point.y * 10) + (blockSize/2)), 0,
        static_cast<GLfloat>((point.x * 10) + (blockSize/2)), static_cast<GLfloat>((point.y * 10) + (blockSize/2)), 0
    };
    */

    /*if (!glfwWindowShouldClose(this->window))
    {
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glBegin(GL_QUADS);
        glViewport(0.0f, 0.0f, 640, 480); //the part the openGL will draw (in pixels).
            glColor3f(1, 0, 0);
            glVertex2f(162, 10);
            glVertex2f(162, 50);
            glVertex2f(220, 10);
            glVertex2f(220, 50);

            // glVertex3f(20, 100, 0);
            // glVertex3f(100, 100, 0);
            // glVertex3f(500, 50, 0);
            // glVertex3f(320, 10, 0);

        glEnd();
        glFlush();




        GLfloat vertices[] = {
            20, 100, 0,
            100, 100, 0,
            500, 50, 0,
            320, 10, 0,
            40, 40, 0
        };

        // GLfloat colour[] = {
        //     255, 255, 255,
        //     255, 255, 255,
        //     255, 255, 255,
        //     255, 255, 255
        // };

        glEnableClientState(GL_VERTEX_ARRAY);
        //glEnableClientState(GL_COLOR_ARRAY);

        glVertexPointer(3, GL_FLOAT, 0, vertices);
        //glColorPointer(3, GL_FLOAT, 0, colour);
        glDrawArrays(GL_POLYGON, 0, 5);

        //glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
        glfwSwapBuffers(this->window);

    }*/
    return ;
}

void LibGLFW::terminateWindow()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
    return ;
}
