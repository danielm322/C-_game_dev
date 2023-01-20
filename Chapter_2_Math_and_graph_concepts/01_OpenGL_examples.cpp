//
// Created by daniel on 20/01/23.
//

#include <glm/glm.hpp>
#include <glm/ext.hpp>

int main()
{
    glm::vec2 p1 = glm::vec2(2.0f, 10.0f);
    glm::vec3 p2 = glm::vec3(10.0f, 5.0f, 2.0f);
    glm::mat4 matrix = glm::mat4(1.0f);
    //Here the 1.0f parameter passed in shows that the matrix is
    //initialized as a identity matrix.
    glm::mat4 translation = glm::translate(glm::mat4(1.0f),
                                           glm::vec3(3.0f,4.0f, 8.0f));
    glm:: mat4 scale = glm::scale(glm::mat4(1.0f),
                                  glm::vec3( 2.0f, 2.0f, 2.0f));
    glm::mat4 rxMatrix = glm::rotate(glm::mat4(), glm::radians(45.0f),
                                     glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 ryMatrix = glm::rotate(glm::mat4(), glm::radians(25.0f),
                                     glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rzMatrix = glm::rotate(glm::mat4(), glm::radians(10.0f),
                                     glm::vec3(0.0, 0.0, 1.0));
//    This above code block rotate the object by 45 degrees along the x-axis, 25.0f degrees along
//    the y-axis, and 10.0f degrees along the z-axis.

// View space
//    However, there is an easier way to create the view matrix using GLM. We give three
//    variables to define the camera position, camera target position, and camera up vector as
//    shown follows:
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 200.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//    We can use these variables to create a view matrix by calling the lookAt function and
//    passing the camera position, the look at position, and up vector, as follows:
    glm::mat4 viewMatrix = glm::lookAt(cameraPos, cameraPos +
                                                  cameraFront, cameraUp);
    //Once we have the view matrix, the local positions can be multiplied by the world and the
    //view matrix to get the position in the view space, as follows:
    // Position_view = View_matrix x World_matrix x Position_local

    //In the projection matrix, we define a projection volume called the frustum. All the objects
    //inside the frustum will be projected onto the 2D display. The objects outside the projection
    //plane will not be rendered:

    //In GLM, there is a function we can use to create the perspective projection matrix, as
    //follows:

    GLfloat FOV = 45.0f;
    GLfloat width = 1280.0f;
    GLfloat height = 720.0f;
    GLfloat nearPlane = 0.1f;
    Glfloat farPlane = 1000.0f;

    glm::mat4 projectionMatrix = glm::perspective(FOV, width /height,
                                                  nearPlane, farPlane);
    //So, after obtaining the projection matrix, we can finally perform a perspective projection
    //transform on our view-transformed points to project the vertices onto the screen:
    //Position final = Projection matrix × View matrix × World matrix × Position local


}