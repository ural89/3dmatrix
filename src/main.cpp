#include "Renderer.h"
#include "Matrix.h"
#include <cmath>

int main(int argc, char *argv[])
{
    Renderer renderer;

    Matrix translationMatrix = {{
        {{1, 0, 0, 5}}, 
        {{0, 1, 0, -2}}, 
        {{0, 0, 1, 3}}, 
        {{0, 0, 0, 1}}}};

    double rotationAngleDegrees = 90;

    double rotationAngle = rotationAngleDegrees * M_PI/180;

    Matrix rotationMatrixZ = {{
        {{std::cos(rotationAngle), -std::sin(rotationAngle), 0, 0}}, 
        {{std::sin(rotationAngle), std::cos(rotationAngle), 0, 0}}, 
        {{0, 0, 1, 0}}, 
        {{0, 0, 0, 1}}}};

    Vector positionVector {
        {2,3,4,1}
    }; 

    Vector directionVector {
        {1, 0, 0, 1}
    };
    Vector moveVector = MultiplyMatrix(translationMatrix, positionVector);
    Vector rotateVector = MultiplyMatrix(rotationMatrixZ, directionVector);
   // renderer.RenderVector(moveVector);
    renderer.RenderVector(rotateVector);
    //    renderer.GoToXY(10, 10);
    //    renderer.Render();
    return 0;
}
