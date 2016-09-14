#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glu.h>

#define SPEED_RATE 0.5f

static GLfloat rotation = 2.5f, rotationspeed=SPEED_RATE, t_x=0.0f, t_y=0.0f, t_z=0.0f;
static double delay = 0;

void draw_cube(float x, float y, float z, float size)
{
    size /= 2;
    glBegin(GL_QUADS);

    /* Cube Top */
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f * size + x, 1.0f * size + y,  1.0f * size + z);
    glVertex3f(-1.0f * size + x, 1.0f * size + y, -1.0f * size + z);
    glVertex3f( 1.0f * size + x, 1.0f * size + y, -1.0f * size + z);
    glVertex3f( 1.0f * size + x, 1.0f * size + y,  1.0f * size + z);


    /* Cube Bottom */
    glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
    glVertex3f(-1.0f * size + x, -1.0f * size + y,  1.0f * size + z);
    glVertex3f(-1.0f * size + x, -1.0f * size + y, -1.0f * size + z);
    glVertex3f( 1.0f * size + x, -1.0f * size + y, -1.0f * size + z);
    glVertex3f( 1.0f * size + x, -1.0f * size + y,  1.0f * size + z);

    /* Cube Front */
    glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f * size + x,  1.0f * size + y, 1.0f * size + z);
    glVertex3f( 1.0f * size + x,  1.0f * size + y, 1.0f * size + z);
    glVertex3f( 1.0f * size + x, -1.0f * size + y, 1.0f * size + z);
    glVertex3f(-1.0f * size + x, -1.0f * size + y, 1.0f * size + z);

    /* Cube Back */ 
    glColor4f(0.0f, 1.0f, 0.5f, 1.0f);
    glVertex3f(-1.0f * size + x,  1.0f * size + y, -1.0f * size + z);
    glVertex3f( 1.0f * size + x,  1.0f * size + y, -1.0f * size + z);
    glVertex3f( 1.0f * size + x, -1.0f * size + y, -1.0f * size + z);
    glVertex3f(-1.0f * size + x, -1.0f * size + y, -1.0f * size + z);

    /* Cube Left Side */
    glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
    glVertex3f(-1.0f * size + x,  1.0f * size + y, -1.0f * size + z);
    glVertex3f(-1.0f * size + x,  1.0f * size + y,  1.0f * size + z);
    glVertex3f(-1.0f * size + x, -1.0f * size + y,  1.0f * size + z);
    glVertex3f(-1.0f * size + x, -1.0f * size + y, -1.0f * size + z);

    /* Cube Right Side */
    glColor4f(0.15f, 0.25f, 0.75f, 1.0f);
    glVertex3f( 1.0f * size + x,  1.0f * size + y, -1.0f * size + z);
    glVertex3f( 1.0f * size + x,  1.0f * size + y,  1.0f * size + z);
    glVertex3f( 1.0f * size + x, -1.0f * size + y,  1.0f * size + z);
    glVertex3f( 1.0f * size + x, -1.0f * size + y, -1.0f * size + z);


    glEnd();
}


void draw_cube_with_hole(float x, float y, float z, float size)
{
   size /= 3;
//back side
   draw_cube(x - size, y - size, z - size, size);
   draw_cube(x - size, y , z - size, size);
   draw_cube(x - size, y + size, z - size, size);

   draw_cube(x + size, y - size, z - size, size);
   draw_cube(x + size, y , z - size, size);
   draw_cube(x + size, y + size, z - size, size);

   draw_cube(x, y - size, z - size, size);
   draw_cube(x, y + size, z - size, size);
//front side
   draw_cube(x - size, y - size, z + size, size);
   draw_cube(x - size, y , z + size, size);
   draw_cube(x - size, y + size, z + size, size);

   draw_cube(x + size, y - size, z + size, size);
   draw_cube(x + size, y , z + size, size);
   draw_cube(x + size, y + size, z + size, size);

   draw_cube(x, y - size, z + size, size);
   draw_cube(x, y + size, z + size, size);
//left size, 2 cubes left
   draw_cube(x - size, y - size, z, size);
//right size, 2 cubes left
   draw_cube(x + size, y - size, z, size);
   draw_cube(x + size, y + size, z, size);
   draw_cube(x - size, y + size, z, size);
}
 
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    else if(key == GLFW_KEY_DOWN)
    {
        t_y += (action == GLFW_PRESS ? SPEED_RATE : 0);
        printf("y = %f\n", t_y);
    }
    else if(key == GLFW_KEY_UP)
    {
        t_y -= (action == GLFW_PRESS ? SPEED_RATE : 0);
        printf("y = %f\n", t_y);
    }
    else if(key == GLFW_KEY_LEFT)
    {
        t_x += (action == GLFW_PRESS ? SPEED_RATE : 0);
        printf("x = %f\n", t_x);
    }
    else if(key == GLFW_KEY_RIGHT)
    {
        t_x -= (action == GLFW_PRESS ? SPEED_RATE : 0);
        printf("x = %f\n", t_x);
    }
    else if(key == GLFW_KEY_PAGE_UP)
    {
        t_z += (action == GLFW_PRESS ? SPEED_RATE : 0);
        printf("z = %f\n", t_z);
    }
    else if(key == GLFW_KEY_PAGE_DOWN)
    {
        t_z -= (action == GLFW_PRESS ? SPEED_RATE : 0);
        printf("z = %f\n", t_z);
    }
}
int main(void)
{
    GLfloat position[4] =
        { 0, 25, 15, 1 };
    GLfloat color[4] =
        { 0, 0, 1, 1 };
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, color);
    color[1] = 1;
    color[2] = 0;
    glLightfv(GL_LIGHT1, GL_AMBIENT, color);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_COLOR_MATERIAL);
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-10.f, 10.f, -10.f, 10.f, 10.f, -10.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//        gluLookAt(0, 25, 10, 0, 0, 2, 0, 1, 0);
        glTranslatef(t_x, t_y, t_z);
//        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

        double new_time = glfwGetTime();
        if(new_time - delay > 0.01)
        {
            delay = new_time;
            rotation += rotationspeed;
            if(rotation > 360)
                rotation -= 360;
            if(rotation < 0)
                rotation += 360;
        }
        printf("%f %f\n", new_time, delay);
        glRotatef(rotation, 1.0f, 1.5f, 0.0f);
        glLightfv(GL_LIGHT1, GL_POSITION, position);

#define MAX 5
#define SPACE 0.5
#define MIDDLE (MAX * 2 + (MAX - 1) * SPACE)/2
        for (int cmpt1 = 0; cmpt1 < MAX; cmpt1++)
        {
            for(int cmpt2 = 0; cmpt2 < MAX; cmpt2++)
            {
                for(int cmpt3 = 0; cmpt3 < MAX; cmpt3++)
                {
                    draw_cube_with_hole(cmpt1 * (2 + SPACE) - MIDDLE, cmpt2 * (2 + SPACE) - MIDDLE, cmpt3 * (2 + SPACE) - MIDDLE, 2);
                }
            }
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
