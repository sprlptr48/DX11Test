#include <GLFW/glfw3.h>
#include <cstdint>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";
    if (!glfwInit())
    {
        std::cout << "GLFW: Unable to initialize\n";
        return -1;
    }

    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);
    const int32_t width = static_cast<int32_t>(videoMode->width * 0.8f);
    const int32_t height = static_cast<int32_t>(videoMode->height * 0.8f);

    glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_FALSE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(
        width,
        height,
        "LearnD3D11 - Hello Window",
        nullptr,
        nullptr);
    if (window == nullptr)
    {
        std::cout << "GLFW: Unable to create window\n";
        glfwTerminate();
        return -1;
    }

    const int32_t windowLeft = videoMode->width / 2 - width / 2;
    const int32_t windowTop = videoMode->height / 2 - height / 2;
    glfwSetWindowPos(window, windowLeft, windowTop);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        // future update code
        // future render code
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
