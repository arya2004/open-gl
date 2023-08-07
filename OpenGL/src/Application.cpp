#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

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

void draw_pixel(double _x, double _y) {
    
   
    double x = _x/1000.0 ;
    double y = _y/1000.0 ;
  
    glVertex2d(x, y);
    
    

}


void MidPointELlipse(double _rx, double _ry, double _xc, double _yc)
{
    double x = 0.0;
    double y = _ry;
    double d1 = (_ry * _ry) - (_rx * _rx * _ry) + (0.25 * _rx * _rx);
    double  dx = 2.0 * _ry * _ry * x;
    double dy = 2.0 * _rx * _rx * y;

   //region 1
   while (dx < dy)
   {    

       draw_pixel(x + _xc, y + _yc);
       draw_pixel(-x + _xc, y + _yc);
       draw_pixel(x + _xc, -y + _yc);
       draw_pixel(-x + _xc, -y + _yc);
    
       if (d1 < 0) {
           x = x + 1.0;
           dx = dx + (2 * _ry * _ry);
           d1 = d1 + dx + (_ry * _ry);
       }
       else {
           x = x + 1.0;
           y = y - 1.0;
           dx = dx + (2.0 * _ry * _ry);
           dy = dy - (2.0 * _rx * _rx);
           d1 = d1 + dx - dy + (_ry * _ry);
       }
   }
   //region2
   double d2 = ((_ry * _ry) * ((x + 0.5) * (x + 0.5))) + ((_rx * _rx) * ((y - 1.0) * (y - 1.0))) - (_rx * _rx * _ry * _ry);

   while (y >= 0)
   {
       draw_pixel(-x + _xc, y + _yc);
       draw_pixel(x + _xc, y + _yc);
       draw_pixel(x + _xc, -y + _yc);
       draw_pixel(-x + _xc, -y + _yc);

       if (d2 > 0) {
           y = y -1.0;
           dy = dy - (2 * _rx * _rx);
           d2 = d2 + (_rx * _rx) - dy;
       }
       else {
           y = y - 1.0;
           x = x + 1.0;
           dx = dx + (2 * _ry * _ry);
           dy = dy - (2 * _rx * _rx);
           d2 = d2 + dx - dy + (_rx * _rx);
       }
   }
}

//_________________________________________


void house()
{
    glBegin(GL_LINES);
    //front
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, -0.60);

    glVertex2f(0.0, -0.60);
    glVertex2f(-0.60, -0.60);

    glVertex2f(-0.60, -0.60);
    glVertex2f(-0.60, 0.00);

    glVertex2f(-0.60, 0.00);
    glVertex2f(0.0, 0.0);

    //side
    glVertex2f(0.0, 0.00);
    glVertex2f(0.80, 0.20);

    glVertex2f(0.80, 0.20);
    glVertex2f(0.80, -0.40);


    glVertex2f(0.80, -0.40);
    glVertex2f(0.0, -0.60);

    //front top
    glVertex2f(-0.60, 0.00);
    glVertex2f(-0.30, 0.40);

    glVertex2f(-0.30, 0.40);
    glVertex2f(0.0,0.00);

    //slope

    glVertex2f(-0.30, 0.40);
    glVertex2f(0.50, 0.60);

    glVertex2f(0.50, 0.60);
    glVertex2f(0.80, 0.20);

    //door

    glVertex2f(-0.20, -0.60);
    glVertex2f(-0.20, -0.20);

    glVertex2f(-0.20, -0.20);
    glVertex2f(-0.40, -0.20);

    glVertex2f(-0.40, -0.20);
    glVertex2f(-0.40, -0.60);

    glEnd();
   

}


//_____________________________________________
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

      //  glBegin(GL_POINTS);
      //MidPointELlipse(600.0,400.0,0,0);
      // glEnd();
        house();


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
   }
   //     int q;
     //   cin >> q;
    glfwTerminate();
    return 0;
    
}



