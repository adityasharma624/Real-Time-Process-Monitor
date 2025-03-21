#pragma once
#include <string>
#include <memory>
#include <GLFW/glfw3.h>
#include "../monitor/process_monitor.hpp"

class Window {
public:
    Window(const std::string& title, int width, int height, ProcessMonitor& monitor);
    ~Window();

    void run();

private:
    std::string title;
    int width;
    int height;
    ProcessMonitor& monitor;
    GLFWwindow* window;

    // Sorting state
    struct {
        int columnIndex = -1;
        bool ascending = true;
    } sortState;

    void renderProcessTable();
    void sortProcessList(std::vector<ProcessInfo>& processes);
}; 