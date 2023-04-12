#include "application.hpp"
#include <iostream>

int main(int argc, char* args[])
{
    // Create app window
    Application app = Application(600, 600, 10, 10);
    app.loop();

    return 0;
}