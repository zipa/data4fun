#include <GLhelper.h>

using namespace glm;

GLhelper::GLhelper()
{
    log_ = LogWrap::GetLog("GLhelper");
    log_->debug("Initializing GL...");

    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW.");
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow( 1024, 768, "Window Title", NULL, NULL);
    if (window == nullptr)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to open GLFW window.");
    }
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLEW.");
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    log_->info("Initialized GL.");
}

GLhelper::~GLhelper()
{
    glfwTerminate();
    log_->info("Terminated GL.");
}

void GLhelper::Run()
{
    do
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // ..
        
        glfwSwapBuffers(window);
        glfwPollEvents();

    }  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
        && glfwWindowShouldClose(window) == 0);
}
