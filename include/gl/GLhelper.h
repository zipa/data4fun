#ifndef _GLHELPER_H_
#define _GLHELPER_H_

#include <iostream>
#include <memory>
#include <exception>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <spdlogwrap.h>

class GLhelper
{
public:
    GLhelper();
    ~GLhelper();
    GLhelper(const GLhelper&) = delete;
    GLhelper(GLhelper&&) = delete;
    GLhelper& operator=(const GLhelper&) = delete;
    GLhelper& operator=(GLhelper&&) = delete;

    void Run();
private:
    std::shared_ptr<spdlog::logger> log_;
    GLFWwindow* window;
};

#endif // _GLHELPER_H_