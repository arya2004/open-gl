#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

int ma(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.3f, 0.5f);
        glVertex2f(0.3f, -0.5f);
        glEnd();


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

int m(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }



    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;
       
    float positions[6] = {
        0.0f,  0.0f,
        0.3f,  0.5f,
        0.3f, -0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 6);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
//_________________________________________

void draw_pixel(float _x, float _y) {
  
    float x = _x/100 ;
    float y = _y/100 ;
    cout << x;
    cout << y;
    cout << "\n\n";
    glVertex2f(x, y);

}


void MidPointELlipse(float _rx, float _ry, float _xc, float _yc)
{
    float x = 0;
    float y = _ry;
    float d1 = (_ry * _ry)
        - (_rx * _rx * _ry)
        + (0.25 * _rx * _rx);
   float  dx = 2 * _ry * _ry * x;
   float dy = 2 * _rx * _rx * y;

   //region 1
   while (dx < dy)
   {
       draw_pixel(x + _xc, y + _yc);
       draw_pixel(-x + _xc, y + _yc);
       draw_pixel(x + _xc, -y + _yc);
       draw_pixel(-x + _xc, -y + _yc);
    
       if (d1 < 0) {
           x++;
           dx = dx + (2 * _ry * _ry);
           d1 = d1 + dx + (_ry * _ry);
       }
       else {
           x++;
           y--;
           dx = dx + (2 * _ry * _ry);
           dy = dy - (2 * _rx * _rx);
           d1 = d1 + dx - dy + (_ry * _ry);
       }
   }
   //region2
   float d2 = ((_ry * _ry) * ((x + 0.5) * (x + 0.5)))
       + ((_rx * _rx) * ((y - 1) * (y - 1)))
       - (_rx * _rx * _ry * _ry);

   while (y >= 0)
   {
       draw_pixel(-x + _xc, y + _yc);
       draw_pixel(x + _xc, y + _yc);
       draw_pixel(x + _xc, -y + _yc);
       draw_pixel(-x + _xc, -y + _yc);

       if (d2 > 0) {
           y--;
           dy = dy - (2 * _rx * _rx);
           d2 = d2 + (_rx * _rx) - dy;
       }
       else {
           y--;
           x++;
           dx = dx + (2 * _ry * _ry);
           dy = dy - (2 * _rx * _rx);
           d2 = d2 + dx - dy + (_rx * _rx);
       }
   }
}

//_________________________________________


int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }



    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;


    /* Loop until the user closes the window */
   while (!glfwWindowShouldClose(window)){
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_POINTS);
        MidPointELlipse(90,44.5,0,0);
       
        
        glEnd();


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
   }
   //     int q;
     //   cin >> q;
    glfwTerminate();
    return 0;
    return 0;
}



