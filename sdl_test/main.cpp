#include "application.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    int w, h;
    if (argc == 3) {
        w = std::stoi(argv[1]);
        h = std::stoi(argv[2]);
    } else {
        w = 50; h = 50;
    }

    // Create app window
    Application app = Application(600, 600, w, h);
    app.loop();

    return 0;
}