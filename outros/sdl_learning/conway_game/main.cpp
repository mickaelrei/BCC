#include "application.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    int w, h;
    if (argc == 3) {
        try
        {
            w = std::stoi(argv[1]);
            h = std::stoi(argv[2]);
        }
        catch(const std::exception &e)
        {
            std::cout << "Error converting to int\n";
            return -1;
        }
    } else {
        w = 200; h = 200;
    }

    // Create app window
    Application app = Application(600, 600, w, h);
    app.loop();

    return 0;
}