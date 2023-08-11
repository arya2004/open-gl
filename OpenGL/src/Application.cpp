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
   

}//_____________________________________________
float greaterModulo(int i, int j)
{
    int ii = i;
    int jj = j;
    if (i < 0)
    {
        ii = -i;

    }
    if (j < 0)
    {
        jj = -j;
    }
    if (jj > ii)
    {
        return j;
    }
    else
    {
        return i;
    }
}

void dda_infinite(int x,int y1, int y2)
{
    int temp_Y = y1;

    while (temp_Y <= y2)
    {

        draw_pixel(x, temp_Y);
        
        temp_Y = temp_Y + 1;
        // delay(10);
    }
}

void dda_zero(int x1, int x2, int y)
{
    int temp_X = x1;

    while (temp_X <= x2)
    {

        draw_pixel(temp_X, y);

        temp_X = temp_X + 1;
        // delay(10);
    }
}

void dda_positive(int x1, int y1, int x2, int y2)
{
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;

    float step = greaterModulo(delta_x, delta_y);
    


    float inc_x = delta_x / step;
    float inc_y = delta_y / step;

    float temp_x = x1;
    float temp_y = y1;
    while (temp_x <= x2 && temp_y <= y2)
    {

        draw_pixel(temp_x, temp_y);
        temp_x = temp_x + inc_x;
        temp_y = temp_y + inc_y;
        // delay(10);
    }
}


void dda_negative(int x1, int y1, int x2, int y2)
{
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;

    float step = greaterModulo(delta_x, delta_y);



    float inc_x = delta_x / step;
    float inc_y = delta_y / step;

    float temp_x = x1;
    float temp_y = y1;
    while (temp_x <= x2 && temp_y >= y2)
    {

        draw_pixel(temp_x, temp_y);
        temp_x = temp_x + inc_x;
        temp_y = temp_y + inc_y;
        // delay(10);
    }
}


void dda_secondQuad(int x1, int y1, int x2, int y2)
{
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;

    float step = greaterModulo(delta_x, delta_y);
  


    float inc_x = delta_x / step;
    float inc_y = delta_y / step;

    float temp_x = x1;
    float temp_y = y1;
    while (temp_x >= x2 && temp_y <= y2)
    {

        draw_pixel(temp_x, temp_y);
        temp_x = temp_x + inc_x;
        temp_y = temp_y + inc_y;
        // delay(10);
    }
}

void dda_thirdQuad(int x1, int y1, int x2, int y2)
{
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;

    float step = greaterModulo(delta_x, delta_y);
 


    float inc_x = delta_x / step;
    float inc_y = delta_y / step;

    float temp_x = x1;
    float temp_y = y1;
    while (temp_x >= x2 && temp_y >= y2)
    {

        draw_pixel(temp_x, temp_y);
        temp_x = temp_x + inc_x;
        temp_y = temp_y + inc_y;
        // delay(10);
    }
}

void dda_(int x1, int y1, int x2, int y2)
{
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;

    if (delta_x == 0)
    {
        if (delta_y > 0)
        {
            dda_infinite(x1, y1, y2);
        }
        else
        {
            dda_infinite(x1, y2, y1);
        }
    }
    else if (delta_y == 0)
    {
        if (delta_x > 0)
        {
            dda_zero(x1, y2, y1);
        }
        else
        {
            dda_zero(x2, x1, y1);
        }
    }
    else if (delta_x > 0 && delta_y > 0)
    {
        dda_positive(x1, y1, x2, y2);
    }
    else if (delta_x < 0 && delta_y > 0)
    {
        dda_secondQuad(x1, y1, x2, y2);
    }
    else if (delta_x > 0 && delta_y < 0)
    {
        dda_negative(x1, y1, x2, y2);
    }
    else if (delta_x < 0 && delta_y < 0)
    {
        dda_thirdQuad(x1, y1, x2, y2);
    }
}
//_____________________________________________

void bressenhamLine(int x1, int y1, int x2, int y2)
{
    int x = x1;
    int y = y1;
    int dx = x2 - x1;
    int dy = y2 - y1;

    dx = x2 - x1;
    dy = y2 - y1;
    int p = 2 * dy - dx;
    float m = dy / dx;
 
    if (abs(m) < 1)
    {

        for (int i = 0; i <= dx; i++)
        {
            draw_pixel(x, y);
            x++;
            if (p < 0)
            {
                p = p + 2 * dy;
            }
            else
            {
                p = p + 2 * dy - 2 * dx;
                y++;
            }
        }
    }
    else if (abs(m) >= 1)
    {
        for (int i = 0; i <= dy; i++)
        {
            draw_pixel(x, y);
            y++;
            if (p < 0)
            {
                p = p + 2 * dx;
            }
            else
            {
                p = p + 2 * dx - 2 * dy;
                x++;
            }
        }
    }
}
//_____________________________________________

void drawCircle(int xc, int yc, int x, int y)
{
    draw_pixel(xc + x, yc + y); // o7
    draw_pixel(xc - x, yc + y); // 06
    draw_pixel(xc + x, yc - y); // octant 2
    draw_pixel(xc - x, yc - y); // o 3
    draw_pixel(xc + y, yc + x); // o 8
    draw_pixel(xc - y, yc + x); // o5
    draw_pixel(xc + y, yc - x); // o 1
    draw_pixel(xc - y, yc - x); // o4
}

void circleBres(int r)
{
    int xc = 0;
    int yc = 0;
    int x = 0;
    int y = r;
    int s = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    draw_pixel(xc + x, yc + y);
    while (x <= y)
    {
        x++;
        if (s <= 0)
        {
            s = s + 4 * x + 6;
        }
        else
        {
            y--;
            s = s + 4 * (x - y) + 10;
        }

        drawCircle(xc, yc, x, y);
        draw_pixel(xc + x, yc + y);
    }
}
//_____________________________________________

void midPointCircleDraw(int x_centre, int y_centre, int r)
{
    int x = r, y = 0;


    int P = 1 - r;
    while (x > y)
    {
        y++;


        if (P <= 0)
        {
            P = P + (2*y) + 1;
        }
            

        else
        {
            x--;
            P = P + (2*y) - (2*x) + 1;
        }

        drawCircle(x_centre, y_centre, x, y);

      
        
    }
}


//----------------------------------------------

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
       
        int raduius, xc,yc;
        cout << "enter x-centre, y-centre and radius for midpoint circple\n";
        cin >> xc >> yc >> raduius;
    

        glBegin(GL_POINTS);
        midPointCircleDraw(xc, yc ,raduius);
       
        glEnd();
        //house();


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



