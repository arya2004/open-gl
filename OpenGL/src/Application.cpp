#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <algorithm>

// Define the window dimensions
const int windowWidth = 800;
const int windowHeight = 600;

// Define a structure to represent a vertex
struct Vertex {
    int x, y;
    Vertex(int _x, int _y) : x(_x), y(_y) {}
};

// Function to draw a horizontal line between two points
void drawHorizontalLine(int x1, int x2, int y, std::vector<unsigned char>& pixels) {
    for (int x = std::min(x1, x2); x <= std::max(x1, x2); ++x) {
        int index = (y * windowWidth + x) * 3;
        pixels[index] = 255;   // Red
        pixels[index + 1] = 0; // Green
        pixels[index + 2] = 0; // Blue
    }
}

// Function to fill a convex polygon using scanline fill algorithm
void scanFillConvexPolygon(const std::vector<Vertex>& vertices, std::vector<unsigned char>& pixels) {
    int minY = windowHeight;
    int maxY = 0;

    // Find the minimum and maximum Y coordinates of the polygon
    for (const Vertex& vertex : vertices) {
        minY = std::min(minY, vertex.y);
        maxY = std::max(maxY, vertex.y);
    }

    // Iterate through scanlines
    for (int y = minY; y <= maxY; ++y) {
        std::vector<int> intersections;

        // Find intersections of the scanline with polygon edges
        for (size_t i = 0; i < vertices.size(); ++i) {
            const Vertex& v1 = vertices[i];
            const Vertex& v2 = vertices[(i + 1) % vertices.size()];

            if ((v1.y <= y && v2.y > y) || (v2.y <= y && v1.y > y)) {
                int x = v1.x + (static_cast<double>(y - v1.y) / (v2.y - v1.y)) * (v2.x - v1.x);
                intersections.push_back(x);
            }
        }

        // Sort the intersections
        std::sort(intersections.begin(), intersections.end());

        // Draw horizontal line segments between pairs of intersections
        for (size_t i = 0; i < intersections.size(); i += 2) {
            int x1 = intersections[i];
            int x2 = intersections[i + 1];
            drawHorizontalLine(x1, x2, y, pixels);
        }
    }
}

int main() {
    if (!glfwInit()) {
        std::cerr << "GLFW initialization failed" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Scanline Fill Example", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Set up OpenGL viewport
    glViewport(0, 0, windowWidth, windowHeight);

    // Create a buffer for storing pixel data
    std::vector<unsigned char> pixels(windowWidth * windowHeight * 3, 0); // Initialize with black color

    // Define the vertices of the convex polygon
    int a;
    std::cout << "enter number of vertices for convex poly\n";
    std::cin >> a;
    std::vector<Vertex> vertices;
    for (int i = 0; i < a; i++)
    {
        int x = 0; int yy = 0;
        std::cin >> x;
        std::cin >> yy;
        vertices.push_back(Vertex(x, yy));
       
    }


    // Fill the convex polygon using scanline fill
    scanFillConvexPolygon(vertices, pixels);

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
