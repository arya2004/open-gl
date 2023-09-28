#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>  

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

void boundaryqFill(int x, int y, float fillColor[], float borderColor[]) {
    float currentColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, currentColor);

    if ((currentColor[0] != borderColor[0] || currentColor[1] != borderColor[1] || currentColor[2] != borderColor[2]) &&
        (currentColor[0] != fillColor[0] || currentColor[1] != fillColor[1] || currentColor[2] != fillColor[2])) {

        draw_pixel(x, y);

        boundaryqFill(x + 1, y, fillColor, borderColor); // Right
        boundaryqFill(x - 1, y, fillColor, borderColor); // Left
        boundaryqFill(x, y + 1, fillColor, borderColor); // Up
        boundaryqFill(x, y - 1, fillColor, borderColor); // Down
    }
}

//----------------------------------------------



//----------------------------------------------
//float fillColor[] = { 1.0, 0.0, 0.0 };
bool visited[200][200];

float fillColor[] = { 1.0, 0.0, 0.0 }; // Red

// Function to set the color of a pixel
void setPixel(int x, int y, float color[]) {
    glPointSize(1.0);
    glBegin(GL_POINTS);
    glColor3fv(color);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

// Recursive-like boundary fill algorithm
void boundaryFill(int x, int y, float fillColor[], float borderColor[]) {
    float currentColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, currentColor);
    if (visited[x+ 99][y+99] == true)
    {
        return;
    }

    if ((currentColor[0] != borderColor[0] || currentColor[1] != borderColor[1] || currentColor[2] != borderColor[2]) &&
        (currentColor[0] != fillColor[0] || currentColor[1] != fillColor[1] || currentColor[2] != fillColor[2])) {

        setPixel(x, y, fillColor);
        visited[x+ 99][y+99] = true;
        boundaryFill(x + 1, y, fillColor, borderColor); // Right
        boundaryFill(x - 1, y, fillColor, borderColor); // Left
        boundaryFill(x, y + 1, fillColor, borderColor); // Up
        boundaryFill(x, y - 1, fillColor, borderColor); // Down
    }
}


//_______________________________________________________

const int WIDTH = 800;
const int HEIGHT = 600;

//bool visited[WIDTH][HEIGHT];

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   // gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void floodFill(int x, int y, float fillColor[3], float interiorColor[3]) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;

    if (visited[x][y])
        return;

    float pixelColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, pixelColor);

    if (pixelColor[0] != interiorColor[0] ||
        pixelColor[1] != interiorColor[1] ||
        pixelColor[2] != interiorColor[2])
        return;

    visited[x][y] = true;
    drawPixel(x, y);

    floodFill(x + 1, y, fillColor, interiorColor);
    floodFill(x - 1, y, fillColor, interiorColor);
    floodFill(x, y + 1, fillColor, interiorColor);
    floodFill(x, y - 1, fillColor, interiorColor);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(100, 100);
    glVertex2i(150, 100);
    glVertex2i(150, 150);
    glVertex2i(100, 150);
    glEnd();
    glFlush();

    float fillColor[] = { 0.0, 1.0, 0.0 }; // Green fill color
    float interiorColor[] = { 1.0, 1.0, 1.0 }; // White interior color

    floodFill(101, 101, fillColor, interiorColor);

    glFlush();
}

//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(WIDTH, HEIGHT);
//    glutCreateWindow("Flood Fill Algorithm in OpenGL");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}



//void LiangBarskey(int x1,int y1, int x2, int y2, int x_win_min, int y_win_max, int x_win_max, int y_win_min)
//{   
//   /* int t = 1;
//    int x_param = x1 + (t * (x2 - x1));
//    int y_param = y1 + (t * (y2 - y1));*/
//
//    int delta_x = x2 - x1;
//    int delta_y = y2 - y1;
//
//    int p1 = -delta_x;
//    int p2 = delta_x;
//    int p3 = -delta_y;
//    int p4 = delta_y;
//
//    int q1 = x1 - x_win_min;
//    int q2 = x_win_max - x1;
//    int q3 = y1 - y_win_min;
//    int q4 = y_win_max - y1;
//
//    int r1 = q1 / p1;
//    int r2 = q2 / p2;
//    int r3 = q3 / p3;
//    int r4 = q4 / q4;
//
//}



// this function gives the maximum
float maxi(float arr[], int n) {
    float m = 0;
    for (int i = 0; i < n; ++i)
        if (m < arr[i])
            m = arr[i];
    return m;
}

// this function gives the minimum
float mini(float arr[], int n) {
    float m = 1;
    for (int i = 0; i < n; ++i)
        if (m > arr[i])
            m = arr[i];
    return m;
}

void liang_barsky_clipper(float xmin, float ymin, float xmax, float ymax,
    float x1, float y1, float x2, float y2) {
    // defining variables
    float p1 = -(x2 - x1);
    float p2 = -p1;
    float p3 = -(y2 - y1);
    float p4 = -p3;

    float q1 = x1 - xmin;
    float q2 = xmax - x1;
    float q3 = y1 - ymin;
    float q4 = ymax - y1;

    float posarr[5], negarr[5];
    int posind = 1, negind = 1;
    posarr[0] = 1;
    negarr[0] = 0;

 

    glVertex2f(xmin/1000, ymin/1000);
    glVertex2f(xmin/1000, ymax/1000);

    glVertex2f(xmin/1000, ymax/1000);
    glVertex2f(xmax/1000, ymax/1000);

    glVertex2f(xmax/1000, ymax/1000);
    glVertex2f(xmax/1000, ymin/1000);

    glVertex2f(xmax/1000, ymin/1000);
    glVertex2f(xmin/1000, ymin/1000);

  
    //rectangle(xmin, ymin, xmax, ymax); // drawing the clipping window

    if ((p1 == 0 && q1 < 0) || (p2 == 0 && q2 < 0) || (p3 == 0 && q3 < 0) || (p4 == 0 && q4 < 0)) {
        cout << "line parrl  to win";
        return;
    }
    if (p1 != 0) {
        float r1 = q1 / p1;
        float r2 = q2 / p2;
        if (p1 < 0) {
            negarr[negind++] = r1; // for negative p1, add it to negative array
            posarr[posind++] = r2; // and add p2 to positive array
        }
        else {
            negarr[negind++] = r2;
            posarr[posind++] = r1;
        }
    }
    if (p3 != 0) {
        float r3 = q3 / p3;
        float r4 = q4 / p4;
        if (p3 < 0) {
            negarr[negind++] = r3;
            posarr[posind++] = r4;
        }
        else {
            negarr[negind++] = r4;
            posarr[posind++] = r3;
        }
    }

    float xn1, yn1, xn2, yn2;
    float rn1, rn2;
    rn1 = maxi(negarr, negind); // maximum of negative array
    rn2 = mini(posarr, posind); // minimum of positive array

    if (rn1 > rn2) { // reject
      //  outtextxy(80, 80, "Line is outside the clipping window!");
        return;
    }

    xn1 = x1 + p2 * rn1;
    yn1 = y1 + p4 * rn1; // computing new points

    xn2 = x1 + p2 * rn2;
    yn2 = y1 + p4 * rn2;
   
    glVertex2f(xn1/1000, yn1/1000);
    glVertex2f(xn2/1000, yn2/1000); // the drawing the new line

    glColor3f(0.0, 1.0, 1.0);;

  

    glVertex2f(x1/1000, y1/1000);
    glVertex2f(xn1/1000, yn1/1000);
  

    glVertex2f(x2/1000, y2/1000);
    glVertex2f(xn2/1000, yn2/1000);
    
}



                    /*
                      ______          _______
                     /      \        /       \
                    /$$$$$$  |       $$$$$$$  |
                    $$____$$ |______ $$ |  $$ |
                     /    $$//      |$$ |  $$ |
                    /$$$$$$/ $$$$$$/ $$ |  $$ |
                    $$ |_____        $$ |__$$ |
                    $$       |       $$    $$/
                    $$$$$$$$/        $$$$$$$/

                    */


void scaling(float x1,float y1, float x2, float y2, float X_scale, float y_scale)
{
    //cli input for rectangle sides and transform
    //switch canse for all
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);

    glVertex2f(x1 / 1000, y1 / 1000);
    glVertex2f(x2 / 1000, y1 / 1000);

    glVertex2f(x2 / 1000, y1 / 1000);
    glVertex2f(x2 / 1000, y2 / 1000);

    glVertex2f(x2 / 1000, y2 / 1000);
    glVertex2f(x1 / 1000, y2 / 1000);

    glVertex2f(x1 / 1000, y2 / 1000);
    glVertex2f(x1 / 1000, y1 / 1000);

   


    float matrix[4][3] = { {x1,y1,1},{x2,y1,1},{x2,y2,1},{x1,y2,1} };

    float scaling[3][3] = { {X_scale,0,0},{0,y_scale,0},{0,0,1}};

    float temp[4][3] = { 0 };

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
            {
                temp[i][j] += matrix[i][k] * scaling[k][j];
            }
    x1 = temp[0][0];
    y1 = temp[0][1];

    x2 = temp[1][0];
    y2 = temp[2][1];

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    

    glVertex2f(x1 / 1000, y1 / 1000);
    glVertex2f(x2 / 1000, y1 / 1000);

    glVertex2f(x2 / 1000, y1 / 1000);
    glVertex2f(x2 / 1000, y2 / 1000);

    glVertex2f(x2 / 1000, y2 / 1000);
    glVertex2f(x1 / 1000, y2 / 1000);

    glVertex2f(x1 / 1000, y2 / 1000);
    glVertex2f(x1 / 1000, y1 / 1000);

    glEnd();

}

void translation(float x1, float y1, float x2, float y2, float X_tran, float y_tran)
{
    //cli input for rectangle sides and transform
    //switch canse for all
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);

    glVertex2f(x1 / 1000, y1 / 1000);
    glVertex2f(x2 / 1000, y1 / 1000);

    glVertex2f(x2 / 1000, y1 / 1000);
    glVertex2f(x2 / 1000, y2 / 1000);

    glVertex2f(x2 / 1000, y2 / 1000);
    glVertex2f(x1 / 1000, y2 / 1000);

    glVertex2f(x1 / 1000, y2 / 1000);
    glVertex2f(x1 / 1000, y1 / 1000);




    float matrix[4][3] = { {x1,y1,1},{x2,y1,1},{x2,y2,1},{x1,y2,1} };

    float scaling[3][3] = { {1,0,0},{0,1,0},{X_tran, y_tran, 1} };

    float temp[4][3] = { 0 };

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
            {
                temp[i][j] += matrix[i][k] * scaling[k][j];
            }
    x1 = temp[0][0];
    y1 = temp[0][1];

    x2 = temp[1][0];
    y2 = temp[2][1];

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);


    glVertex2f(x1 / 1000, y1 / 1000);
    glVertex2f(x2 / 1000, y1 / 1000);

    glVertex2f(x2 / 1000, y1 / 1000);
    glVertex2f(x2 / 1000, y2 / 1000);

    glVertex2f(x2 / 1000, y2 / 1000);
    glVertex2f(x1 / 1000, y2 / 1000);

    glVertex2f(x1 / 1000, y2 / 1000);
    glVertex2f(x1 / 1000, y1 / 1000);

    glEnd();

}

//void rotation(float x1, float y1, float x2, float y2, float theta)
//{
//    //cli input for rectangle sides and transform
//    //switch canse for all
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 0.0, 0.0);
//    glBegin(GL_LINES);
//
//    glVertex2f(x1 / 1000, y1 / 1000);
//    glVertex2f(x2 / 1000, y1 / 1000);
//
//    glVertex2f(x2 / 1000, y1 / 1000);
//    glVertex2f(x2 / 1000, y2 / 1000);
//
//    glVertex2f(x2 / 1000, y2 / 1000);
//    glVertex2f(x1 / 1000, y2 / 1000);
//
//    glVertex2f(x1 / 1000, y2 / 1000);
//    glVertex2f(x1 / 1000, y1 / 1000);
//
//
//    float radian = theta * 3.14159 / 180;
//
//    float matrix[4][3] = { {x1,y1,1},{x2,y1,1},{x2,y2,1},{x1,y2,1} };
//
//    float scaling[3][3] = { {cos(radian),-sin(radian),0},{sin(radian), cos(radian),0},{0, 0, 1} };
//
//    float temp[4][3] = { 0 };
//
//    for (int i = 0; i < 4; i++)
//        for (int j = 0; j < 3; j++)
//            for (int k = 0; k < 3; k++)
//            {
//                temp[i][j] += matrix[i][k] * scaling[k][j];
//            }
//    /*x1 = temp[0][0];
//    y1 = temp[0][1];
//
//    x2 = temp[1][0];
//    y2 = temp[2][1];*/
//
//    x1 = temp[0][0];
//    y1 = temp[0][1];
//
//    x2 = temp[1][0];
//    y2 = temp[2][1];
//
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0.0, 1.0, 0.0);
//
//
//    glVertex2f(temp[0][0] / 1000, temp[0][1] / 1000);
//    glVertex2f(temp[1][0] / 1000, temp[1][1] / 1000);
//
//    glVertex2f(temp[1][0] / 1000, temp[1][1] / 1000);
//    glVertex2f(temp[2][0] / 1000, temp[2][1] / 1000);
//
//    glVertex2f(temp[2][0] / 1000, temp[2][1] / 1000);
//    glVertex2f(temp[3][0] / 1000, temp[3][1] / 1000);
//
//    glVertex2f(temp[3][0] / 1000, temp[3][1] / 1000);
//    glVertex2f(temp[0][0] / 1000, temp[0][1] / 1000);
//
//    glEnd();
//}


    void rotation(float x1, float y1, float x2, float y2, float theta)
{
    //cli input for rectangle sides and transform
    //switch canse for all
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);

    glVertex2f(x1 / 1000, y1 / 1000);
    glVertex2f(x2 / 1000, y1 / 1000);

    glVertex2f(x2 / 1000, y1 / 1000);
    glVertex2f(x2 / 1000, y2 / 1000);

    glVertex2f(x2 / 1000, y2 / 1000);
    glVertex2f(x1 / 1000, y2 / 1000);

    glVertex2f(x1 / 1000, y2 / 1000);
    glVertex2f(x1 / 1000, y1 / 1000);


    float radian = theta * 3.14159 / 180;

    float matrix[4][3] = { {x1,y1,1},{x2,y1,1},{x2,y2,1},{x1,y2,1} };

    float scaling[3][3] = { {cos(radian),-sin(radian),0},{sin(radian), cos(radian),0},{0, 0, 1}};

    float temp[4][3] = { 0 };

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
            {
                temp[i][j] += matrix[i][k] * scaling[k][j];
            }
    /*x1 = temp[0][0];
    y1 = temp[0][1];

    x2 = temp[1][0];
    y2 = temp[2][1];*/

    x1 = temp[0][0];
    y1 = temp[0][1];

    x2 = temp[1][0];
    y2 = temp[2][1];

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);


    glVertex2f(temp[0][0] / 1000, temp[0][1] / 1000);
    glVertex2f(temp[1][0] / 1000, temp[1][1] / 1000);

    glVertex2f(temp[1][0] / 1000, temp[1][1] / 1000);
    glVertex2f(temp[2][0] / 1000, temp[2][1] / 1000);

    glVertex2f(temp[2][0] / 1000, temp[2][1] / 1000);
    glVertex2f(temp[3][0] / 1000, temp[3][1] / 1000);

    glVertex2f(temp[3][0] / 1000, temp[3][1] / 1000);
    glVertex2f(temp[0][0] / 1000, temp[0][1] / 1000);

    glEnd();

}

    void X_sheering(float x1, float y1, float x2, float y2, float x_sheer)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex2f(x1 / 1000, y1 / 1000);
        glVertex2f(x2 / 1000, y1 / 1000);

        glVertex2f(x2 / 1000, y1 / 1000);
        glVertex2f(x2 / 1000, y2 / 1000);

        glVertex2f(x2 / 1000, y2 / 1000);
        glVertex2f(x1 / 1000, y2 / 1000);

        glVertex2f(x1 / 1000, y2 / 1000);
        glVertex2f(x1 / 1000, y1 / 1000);


     

        float matrix[4][3] = { {x1,y1,1},{x2,y1,1},{x2,y2,1},{x1,y2,1} };

        float scaling[3][3] = { {1,x_sheer,0},{0, 1,0}, {0, 0, 1} };

        float temp[4][3] = { 0 };

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                {
                    temp[i][j] += matrix[i][k] * scaling[k][j];
                }

        x1 = temp[0][0];
        y1 = temp[0][1];

        x2 = temp[1][0];
        y2 = temp[2][1];

        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);


        glVertex2f(temp[0][0] / 1000, temp[0][1] / 1000);
        glVertex2f(temp[1][0] / 1000, temp[1][1] / 1000);

        glVertex2f(temp[1][0] / 1000, temp[1][1] / 1000);
        glVertex2f(temp[2][0] / 1000, temp[2][1] / 1000);

        glVertex2f(temp[2][0] / 1000, temp[2][1] / 1000);
        glVertex2f(temp[3][0] / 1000, temp[3][1] / 1000);

        glVertex2f(temp[3][0] / 1000, temp[3][1] / 1000);
        glVertex2f(temp[0][0] / 1000, temp[0][1] / 1000);

        glEnd();

    }

    void Y_sheering(float x1, float y1, float x2, float y2, float y_sheer)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex2f(x1 / 1000, y1 / 1000);
        glVertex2f(x2 / 1000, y1 / 1000);

        glVertex2f(x2 / 1000, y1 / 1000);
        glVertex2f(x2 / 1000, y2 / 1000);

        glVertex2f(x2 / 1000, y2 / 1000);
        glVertex2f(x1 / 1000, y2 / 1000);

        glVertex2f(x1 / 1000, y2 / 1000);
        glVertex2f(x1 / 1000, y1 / 1000);




        float matrix[4][3] = { {x1,y1,1},{x2,y1,1},{x2,y2,1},{x1,y2,1} };

        float scaling[3][3] = { {1,0,0},{y_sheer, 1,0}, {0, 0, 1} };

        float temp[4][3] = { 0 };

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                {
                    temp[i][j] += matrix[i][k] * scaling[k][j];
                }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);


        glVertex2f(temp[0][0] / 1000, temp[0][1] / 1000);
        glVertex2f(temp[1][0] / 1000, temp[1][1] / 1000);

        glVertex2f(temp[1][0] / 1000, temp[1][1] / 1000);
        glVertex2f(temp[2][0] / 1000, temp[2][1] / 1000);

        glVertex2f(temp[2][0] / 1000, temp[2][1] / 1000);
        glVertex2f(temp[3][0] / 1000, temp[3][1] / 1000);

        glVertex2f(temp[3][0] / 1000, temp[3][1] / 1000);
        glVertex2f(temp[0][0] / 1000, temp[0][1] / 1000);

        glEnd();


    }





    void X_reflection(float x1, float y1, float x2, float y2)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex2f(x1 / 1000, y1 / 1000);
        glVertex2f(x2 / 1000, y1 / 1000);

        glVertex2f(x2 / 1000, y1 / 1000);
        glVertex2f(x2 / 1000, y2 / 1000);

        glVertex2f(x2 / 1000, y2 / 1000);
        glVertex2f(x1 / 1000, y2 / 1000);

        glVertex2f(x1 / 1000, y2 / 1000);
        glVertex2f(x1 / 1000, y1 / 1000);




        float matrix[4][3] = { {x1,y1,1},{x2,y1,1},{x2,y2,1},{x1,y2,1} };

        float scaling[3][3] = { {1,0,0},{0, -1,0}, {0, 0, 1} };

        float temp[4][3] = { 0 };

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                {
                    temp[i][j] += matrix[i][k] * scaling[k][j];
                }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);


        glVertex2f(temp[0][0] / 1000, temp[0][1] / 1000);
        glVertex2f(temp[1][0] / 1000, temp[1][1] / 1000);

        glVertex2f(temp[1][0] / 1000, temp[1][1] / 1000);
        glVertex2f(temp[2][0] / 1000, temp[2][1] / 1000);

        glVertex2f(temp[2][0] / 1000, temp[2][1] / 1000);
        glVertex2f(temp[3][0] / 1000, temp[3][1] / 1000);

        glVertex2f(temp[3][0] / 1000, temp[3][1] / 1000);
        glVertex2f(temp[0][0] / 1000, temp[0][1] / 1000);

        glEnd();

    }

    void Y_reflection(float x1, float y1, float x2, float y2)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex2f(x1 / 1000, y1 / 1000);
        glVertex2f(x2 / 1000, y1 / 1000);

        glVertex2f(x2 / 1000, y1 / 1000);
        glVertex2f(x2 / 1000, y2 / 1000);

        glVertex2f(x2 / 1000, y2 / 1000);
        glVertex2f(x1 / 1000, y2 / 1000);

        glVertex2f(x1 / 1000, y2 / 1000);
        glVertex2f(x1 / 1000, y1 / 1000);




        float matrix[4][3] = { {x1,y1,1},{x2,y1,1},{x2,y2,1},{x1,y2,1} };

        float scaling[3][3] = { {-1,0,0},{0, 1,0}, {0, 0, 1} };

        float temp[4][3] = { 0 };

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                {
                    temp[i][j] += matrix[i][k] * scaling[k][j];
                }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);


        glVertex2f(temp[0][0] / 1000, temp[0][1] / 1000);
        glVertex2f(temp[1][0] / 1000, temp[1][1] / 1000);

        glVertex2f(temp[1][0] / 1000, temp[1][1] / 1000);
        glVertex2f(temp[2][0] / 1000, temp[2][1] / 1000);

        glVertex2f(temp[2][0] / 1000, temp[2][1] / 1000);
        glVertex2f(temp[3][0] / 1000, temp[3][1] / 1000);

        glVertex2f(temp[3][0] / 1000, temp[3][1] / 1000);
        glVertex2f(temp[0][0] / 1000, temp[0][1] / 1000);

        glEnd();

    }
//_____________________________________________________________________________________

                        /*
                          ______           _______
                         /      \         /       \
                        /$$$$$$  |        $$$$$$$  |
                        $$ ___$$ | ______ $$ |  $$ |
                          /   $$< /      |$$ |  $$ |
                         _$$$$$  |$$$$$$/ $$ |  $$ |
                        /  \__$$ |        $$ |__$$ |
                        $$    $$/         $$    $$/
                         $$$$$$/          $$$$$$$/
                                                   */



    void translation_3d(float p1[3], float p2[3], float p3[3], float p4[3], float X_tran, float y_tran, float z_tran)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2]/1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
       // glEnd();


       float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{X_tran, y_tran, z_tran, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };
       
       

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }

       

        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }
  

    //_____________________________________________________________________________________

    void scaling_3d(float p1[3], float p2[3], float p3[3], float p4[3], float X_scal, float y_scal, float z_scal)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {X_scal,0,0, 0},{0,y_scal,0, 0},{0,0,z_scal, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void X_sheer_3d(float p1[3], float p2[3], float p3[3], float p4[3], float y_sheer, float z_sheer)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,y_sheer,z_sheer, 0},{0,1,0, 0},{0,0,1, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void Y_sheer_3d(float p1[3], float p2[3], float p3[3], float p4[3], float x_sheer, float z_sheer)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{x_sheer,1,z_sheer, 0},{0,0,1, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }


    //_____________________________________________________________________________________

    void Z_sheer_3d(float p1[3], float p2[3], float p3[3], float p4[3], float x_sheer, float y_sheer)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{0,1,0, 0},{x_sheer,y_sheer,1, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }


    //_____________________________________________________________________________________

    void Z_rotation_3d(float p1[3], float p2[3], float p3[3], float p4[3], float theta)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();

        float radian = theta * 3.14159 / 180;

        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {cos(radian),sin(radian),0, 0},{-sin(radian),cos(radian),0, 0},{0,0,1, 0},{0,0,0, 1}};

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void Y_rotation_3d(float p1[3], float p2[3], float p3[3], float p4[3], float theta)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();

        float radian = theta * 3.14159 / 180;

        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {cos(radian),0,-sin(theta), 0},{0,1,0, 0},{sin(theta),0,cos(theta), 0},{0,0,0, 1}};

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void X_rotation_3d(float p1[3], float p2[3], float p3[3], float p4[3], float theta)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();

        float radian = theta * 3.14159 / 180;

        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{0,cos(radian),sin(theta), 0},{0,-sin(theta),cos(theta), 0},{0,0,0, 1}};

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }
    //_---------------------------------------------------------------------------------------------------

    void Z_rotation_parallel_3d(float p1[3], float p2[3], float p3[3], float p4[3], float theta, float x_tran, float y_tran)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);



        float matrix1[4][4] = { 0 };

        float scaling1[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{-x_tran, -y_tran, 0, 1} };

        float temp1[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };
        


        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix1[i][j] += temp1[i][k] * scaling1[k][j];
                }
            }
        }
        // glEnd();

        float radian = theta * 3.14159 / 180;

        float matrix2[4][4] = { 0 };

        float scaling[4][4] = { {cos(radian),sin(radian),0, 0},{-sin(radian),cos(radian),0, 0},{0,0,1, 0},{0,0,0, 1} };

       // float temp2[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix2[i][j] += matrix1[i][k] * scaling[k][j];
                }
            }
        }

        //__translation inverse

    

        float matrix[4][4] = { 0 };

        float scaling3[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{x_tran, y_tran, 0, 1} };

       // float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += matrix2[i][k] * scaling3[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    //_---------------------------------------------------------------------------------------------------

    void X_rotation_parallel_3d(float p1[3], float p2[3], float p3[3], float p4[3], float theta, float y_tran, float z_tran)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);



        float matrix1[4][4] = { 0 };

        float scaling1[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{0, -y_tran, -z_tran, 1} };

        float temp1[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix1[i][j] += temp1[i][k] * scaling1[k][j];
                }
            }
        }
        // glEnd();

        float radian = theta * 3.14159 / 180;

        float matrix2[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{0,cos(radian),sin(theta), 0},{0,-sin(theta),cos(theta), 0},{0,0,0, 1} };

        // float temp2[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix2[i][j] += matrix1[i][k] * scaling[k][j];
                }
            }
        }

        //__translation inverse



        float matrix[4][4] = { 0 };

        float scaling3[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{0, y_tran, z_tran, 1} };

        // float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += matrix2[i][k] * scaling3[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }
    //_---------------------------------------------------------------------------------------------------

    void Y_rotation_parallel_3d(float p1[3], float p2[3], float p3[3], float p4[3], float theta, float x_tran, float z_tran)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);



        float matrix1[4][4] = { 0 };

        float scaling1[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{-x_tran, 0,-z_tran, 1} };

        float temp1[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix1[i][j] += temp1[i][k] * scaling1[k][j];
                }
            }
        }
        // glEnd();

        float radian = theta * 3.14159 / 180;

        float matrix2[4][4] = { 0 };

        float scaling[4][4] = { {cos(radian),0,-sin(theta), 0},{0,1,0, 0},{sin(theta),0,cos(theta), 0},{0,0,0, 1} };

        // float temp2[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix2[i][j] += matrix1[i][k] * scaling[k][j];
                }
            }
        }

        //__translation inverse



        float matrix[4][4] = { 0 };

        float scaling3[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{x_tran, 0, z_tran, 1} };

        // float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += matrix2[i][k] * scaling3[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void XY_Reflection(float p1[3], float p2[3], float p3[3], float p4[3])
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,-1, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };


        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void XZ_Reflection(float p1[3], float p2[3], float p3[3], float p4[3])
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{0,-1,0, 0},{0,0,1, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void YZ_Reflection(float p1[3], float p2[3], float p3[3], float p4[3])
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {-1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }
   


        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

  


int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "C-57 Arya Pathak", NULL, NULL);
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
    float x1, y1, z1, x2, y2, z2, x3,y3, z3,x4,y4, z4;
    int value;
    std::cout << "Enter the x1, y1, z1, x2, y2, z2, x3,y3, z3,x4,y4, z4 of the quadrilateral\n";
    //std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;
    std::cout << "100 100 100 150 200 100 150 150 200 200 100 100 \n";
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
        glVertex2f(1000,0);
        glVertex2f(-1000, 0);
        glVertex2f(0, 1000);
        glVertex2f(0, - 1000);
       
        //liang_barsky_clipper(-100,-100,200,200, -330,-450, 250, 250);
       // glEnd();
        float t1[3] = {100,100,100};
        float t2[3] = { 150,200,100 };
        float t3[3] = { 150,150,200 };
        float t4[3] = { 200,100,100 };
 /*       float t1[3] = { x1,y1,z1 };
        float t2[3] = { x2,y2,z2 };
        float t3[3] = { x3,y3,z3 };
        float t4[3] = { x4,y4,z4 };*/
        //Z_sheer_3d(t1,t2,t3,t4, -1,-2);
       // Z_rotation_3d(t1, t2, t3, t4, 40);
        //Z_rotation_parallel_3d(t1, t2, t3, t4, 40, 0, 0);
       // XY_Reflection(t1, t2, t3, t4);
       /* X_reflection(100, 100, 400, 400);
        Y_reflection(100, 100, 400, 400);*/
       // translation(0, 0, 300, 300, 100, 100);
        /* Swap front and back buffers */

        std::cout << "1> Translation 2> Scaling 3> X-Sheer 4> Y-Sheer 5> Z-Sheer 6> X axis Rotation 7> Y axis Rotation 8> Z axis Rotation 9> Parralel to X axis Rotation 10> Parralel to Y axis Rotation 11> Parralel to Z axis Rotation 12> XY-Plane Rotation 13> YZ-Plane Rotation 14> XZ-PLane Rotation\n";
       
        std::cin >> value;
        switch (value) {
        case 1:
            float xa, ya, za;
            std::cout << "Enter x y z translation value \n";
            std::cin >> xa >> ya >> za;
           
            translation_3d(t1, t2, t3, t4, xa, ya , za);

            break;
        case 2:
            float x, y, z;
            std::cout << "Enter x y z scaling factor\n";
            std::cin >> x >> y >> z;
           
            scaling_3d(t1, t2, t3, t4, x, y, z);
            break;
        case 3:
            float xz, yz;
            std::cout << "Enter y z sheer factor\n";
            std::cin >> xz >> yz ;
           
            X_sheer_3d(t1, t2, t3, t4, xz, yz);
            break;
        case 4:
            float xs, ys;
            std::cout << "Enter x z sheer factor\n";
            std::cin >> xs >> ys;
            Y_sheer_3d(t1, t2, t3, t4, xs, ys);
            break;
        case 5:
            float xd, yd;
            std::cout << "Enter x y sheer factor\n";
            std::cin >> xd >> yd;
            Z_sheer_3d(t1, t2, t3, t4, xd, yd);
            break;
        case 6:
            float theta;
            std::cout << "Enter theta\n";
            std::cin >> theta;
            X_rotation_3d(t1, t2, t3, t4, theta);
            break;
        case 7:
            float thetaq;
            std::cout << "Enter theta\n";
            std::cin >> thetaq;
            Y_rotation_3d(t1, t2, t3, t4, thetaq);
            break;
        case 8:
           float thetaaa;
            std::cout << "Enter theta\n";
            std::cin >> thetaaa;
            Z_rotation_3d(t1, t2, t3, t4, thetaaa);
            break;
        case 9:
            float thetae, x_trne, y_trane ;
            std::cout << "Enter theta y z offset from X-axis\n";
            std::cin >> thetae >> x_trne >> y_trane;
            X_rotation_parallel_3d(t1, t2, t3, t4, thetae, x_trne, y_trane);
            break;
        case 10:
            float thetar, x_trnr, y_tranr;
            std::cout << "Enter theta x z offset from Y-axis\n";
            std::cin >> thetar >> x_trnr >> y_tranr;
            Y_rotation_parallel_3d(t1, t2, t3, t4, thetar, x_trnr, y_tranr);
            break;
        case 11:
            float thetau, x_trnu, y_tranu;
            std::cout << "Enter theta x y offset from Z-axis\n";
            std::cin >> thetau >> x_trnu >> y_tranu;
            Z_rotation_parallel_3d(t1, t2, t3, t4, thetau, x_trnu, y_tranu);
            break;
        case 12:
            XY_Reflection(t1, t2, t3, t4);
            break;
        case 13:
            XZ_Reflection(t1, t2, t3, t4);
            break;
        case 14:
            YZ_Reflection(t1, t2, t3, t4);
            break;
        default:
            std::cout << "Invalid input. Please enter a number between 1 and 14." << std::endl;
        }
     /*   scaling();
        translation();
        rotation();
        X_reflection();
        Y_reflection();
        X_sheering();
        Y_sheering();*/
        
        

        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        //std::cout << "udf";
    }
    //     int q;
      //   cin >> q;
    glfwTerminate();
    
    return 0;

}
