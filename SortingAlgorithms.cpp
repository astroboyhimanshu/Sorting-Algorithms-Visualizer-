/* The Code works well for OpenGL Windows so nothing needs to be changed */
#include <GL/glut.h>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>

// Made by Himanshu

const int ARRAY_SIZE = 50;
int arr[ARRAY_SIZE];
bool sorting = false;
int arri[ARRAY_SIZE];

void init()
{
    // Initialize array with random values
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 100 + 1; // Generating random numbers between 1 and hundered 
    }
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arri[i] = rand() % 100 + 1;
    }
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);

                // Draw bars after each swap
                glClear(GL_COLOR_BUFFER_BIT);
                float bar_width = 2.0 / ARRAY_SIZE; // bar width based on height of array
                float bar_height_scale = 2.0 / 100; //This line calculates the scaling factor for the height of each bar based on the maximum value in the array.
                for (int k = 0; k < ARRAY_SIZE; k++)
                {
                    float x1 = -1 + k * bar_width;
                    float x2 = x1 + bar_width;
                    float y1 = -1;
                    float y2 = y1 + arr[k] * bar_height_scale;

                    if (k == j || k == j + 1)
                    {
                        glColor3f(1.0, 0.0, 0.0); // Set color to red for the swapped bars
                    }
                    else
                    {
                        glColor3f(0.0, 0.0, 1.0); // Set color to blue for other bars
                    }
                    glBegin(GL_QUADS);
                    glVertex2f(x1, y1);
                    glVertex2f(x1, y2);
                    glVertex2f(x2, y2);
                    glVertex2f(x2, y1);
                    glEnd();
                }

                glutSwapBuffers();

                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Add delay for visualization
            }
            else // Add this else clause to set the color to blue if the bar is not being swapped
            {
                glClear(GL_COLOR_BUFFER_BIT);
                float bar_width = 2.0 / ARRAY_SIZE;
                float bar_height_scale = 2.0 / 100;
                for (int k = 0; k < ARRAY_SIZE; k++)
                {   // bar dimensions 
                    float x1 = -1 + k * bar_width;
                    float x2 = x1 + bar_width;
                    float y1 = -1;
                    float y2 = y1 + arr[k] * bar_height_scale;

                    glColor3f(0.0, 0.0, 1.0); // Set color to blue for other bars
                    glBegin(GL_QUADS); // quadrilateral 
                    glVertex2f(x1, y1);
                    glVertex2f(x1, y2);
                    glVertex2f(x2, y2);
                    glVertex2f(x2, y1);
                    glEnd();
                }

                glutSwapBuffers();

                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Add delay for visualization
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);

        // Draw bars after each swap
        glClear(GL_COLOR_BUFFER_BIT);
        float bar_width = 2.0 / ARRAY_SIZE; // bar width based on height of array
        float bar_height_scale = 2.0 / 100; //This line calculates the scaling factor for the height of each bar based on the maximum value in the array.
        for (int k = 0; k < ARRAY_SIZE; k++)
        {
            float x1 = -1 + k * bar_width;
            float x2 = x1 + bar_width;
            float y1 = -1;
            float y2 = y1 + arr[k] * bar_height_scale;

            if (k == i || k == min_index)
            {
                glColor3f(1.0, 0.0, 0.0); // Set color to red for the swapped bars
            }
            else
            {
                glColor3f(0.0, 0.0, 1.0); // Set color to blue for other bars
            }
            glBegin(GL_QUADS);
            glVertex2f(x1, y1);
            glVertex2f(x1, y2);
            glVertex2f(x2, y2);
            glVertex2f(x2, y1);
            glEnd();
        }

        glutSwapBuffers();

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Add delay for visualization
    }

    // Sorting complete, show all bars as blue
    glClear(GL_COLOR_BUFFER_BIT);
    float bar_width = 2.0 / ARRAY_SIZE;
    float bar_height_scale = 2.0 / 100;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        float x1 = -1 + i * bar_width;
        float x2 = x1 + bar_width;
        float y1 = -1;
        float y2 = y1 + arr[i] * bar_height_scale;

        glColor3f(0.0, 0.0, 1.0); // Set color to blue
        glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x1, y2);
        glVertex2f(x2, y2);
        glVertex2f(x2, y1);
        glEnd();
    }

    glutSwapBuffers();
}

void display() // responsible for rendering the graphics 
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw bars
    float bar_width = 2.0 / ARRAY_SIZE;
    float bar_height_scale = 2.0 / 100;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        float x1 = -1 + i * bar_width;
        float x2 = x1 + bar_width;
        float y1 = -1;
        float y2 = y1 + arr[i] * bar_height_scale;

        glColor3f(0.0, 0.0, 1.0); // Set color to blue
        glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x1, y2);
        glVertex2f(x2, y2);
        glVertex2f(x2, y1);
        glEnd();
    }

    glutSwapBuffers(); //swap the front and back buffers and display the newly rendered graphics on the screen.
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == ' ' || key=='h' || key=='n') // if spacebar or 'h' or 'n' is pressed 
    {
        sorting = !sorting;
        if (sorting)
        {
            bubbleSort(arr, ARRAY_SIZE);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            selectionSort(arri, ARRAY_SIZE);
           

        }
    }
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(650, 650);
    glutCreateWindow("Bubble & Selection Sorting Algorithms Visualizer");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

