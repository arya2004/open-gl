#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <queue>


const int windowWidth = 800;
const int windowHeight = 600;


void setPixel(int x, int y, std::vector<unsigned char>& pixels, int width, unsigned char r, unsigned char g, unsigned char b) {
    if (x >= 0 && x < width && y >= 0 && y < windowHeight) {
        int index = (y * width + x) * 3;
        pixels[index] = r;
        pixels[index + 1] = g;
        pixels[index + 2] = b;
    }
}

//  NON RECURSIVE APPROACH, CAUSE STACK OVERFLOW

void Algoirthm(int x, int y, std::vector<unsigned char>& pixels, int width, int height, unsigned char targetColorR, unsigned char targetColorG, unsigned char targetColorB, unsigned char fillColorR, unsigned char fillColorG, unsigned char fillColorB) {
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(x, y));

    while (!q.empty()) {
        std::pair<int, int> current = q.front();
        q.pop();

        int cx = current.first;
        int cy = current.second;

        if (cx < 0 || cx >= width || cy < 0 || cy >= height) {
            continue;
        }

        int index = (cy * width + cx) * 3;

        if (pixels[index] == targetColorR && pixels[index + 1] == targetColorG && pixels[index + 2] == targetColorB) {
            setPixel(cx, cy, pixels, width, fillColorR, fillColorG, fillColorB);

            q.push(std::make_pair(cx + 1, cy));
            q.push(std::make_pair(cx - 1, cy));
            q.push(std::make_pair(cx, cy + 1));
            q.push(std::make_pair(cx, cy - 1));
        }
    }
}

int main() {
    if (!glfwInit()) {
        std::cerr << "GLFW initialization failed" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "C-57", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

  
    glViewport(0, 0, windowWidth, windowHeight);

    // Create a buffer for storing pixel data
    std::vector<unsigned char> pixels(windowWidth * windowHeight * 3, 255); 

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    float x1 = 0;
    float x2 = 0;
    float y2 = 0;
    float y1 = 0;
    std::cout << "enter x1,y1\n";
    std::cin >> x1;
    std::cin >> y1;
    std::cout << "enter x2,y2\n";
    std::cin >> x2;
    std::cin >> y2;
    glBegin(GL_LINES);
    glVertex2f(x1/800, y1/600);
    glVertex2f(x2 / 800, y1 / 600);

    glVertex2f(x2 / 800, y1 / 600);
    glVertex2f(x2 / 800, y2 / 600);

    glVertex2f(x2 / 800, y2 / 600);
    glVertex2f(x1 / 800, y2 / 600);

    glVertex2f(x1 / 800, y2 / 600);
    glVertex2f(x1 / 800, y1 / 600);
    glEnd();

   

    int startX = 300;
    int startY = 250;
    unsigned char targetColorR = 255; // White color (background)
    unsigned char targetColorG = 255;
    unsigned char targetColorB = 255;
    unsigned char fillColorR = 255; // Red color (interior)
    unsigned char fillColorG = 0;
    unsigned char fillColorB = 0;

    Algoirthm(startX, startY, pixels, windowWidth, windowHeight, targetColorR, targetColorG, targetColorB, fillColorR, fillColorG, fillColorB);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Render the pixel data to the screen
        glDrawPixels(windowWidth, windowHeight, GL_RGB, GL_UNSIGNED_BYTE, pixels.data());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
