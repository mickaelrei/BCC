#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cmath>

#include <shader.hpp>

// Window resize
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Input
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
    // Init GLFW
    // ---------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    // -------------
    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Load GLAD
    // ---------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        glfwTerminate();
        return -1;
    }

    Shader shader{"./shaders/vertex_shader.glsl", "./shaders/fragment_shader.glsl"};

    // Setup vertex data (and buffer) and configure vertex attributes
    // --------------------------------------------------------------
    // float vertices[] = {
    //      0.5f,  0.5f, 0.0f,  // top right
    //      0.5f, -0.5f, 0.0f,  // bottom right
    //     -0.5f, -0.5f, 0.0f,  // bottom left
    //     -0.5f,  0.5f, 0.0f   // top left
    // };
    float vertices[] = {
        // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
    }; 
    unsigned int indices[] = {
        0, 1, 3,        // first triangle
        1, 2, 3         // second triangle
    };

    // Create vertex objects
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Bind the array (VAO) first
    glBindVertexArray(VAO);

    // Then bind and set the elements buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Then bind and set the buffer (VBO)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // How to interpret the vertex data (layout location on vertex shader)
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Unbind buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Set polygon mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // Input
        // -----
        processInput(window);

        // Rendering commands
        // ------------------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Set shader uniform "ourColor"
        float timeValue = glfwGetTime();
        // float greenValue = (std::sin(timeValue) / 2.0f) + 0.5f;
        shader.use();
        shader.setFloat("offset", std::sin(timeValue));
        // shader.setFloat4("ourColor", 0.0f, greenValue, 0.0f, 1.0f);

        // Render triangles
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / sizeof(float));
        glBindVertexArray(0);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0);

        // Swap buffers and poll events
        // ----------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}