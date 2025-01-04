#include "GameObjects/ChildObject.h"
#include "GameObjects/ParentObject.h"
#include "Matrix.h"
#include "Renderer.h"
#include "TranslateAndRotate.h"

Renderer renderer;
void DrawObject(Matrix objectTransformMatrix, int color)
{
    renderer.SetConsoleColor(color);
    Matrix translateMatrix = {// move to origin a bit
        {{1, 0, 0, 50},
        {0, 1, 0, 15},
        {0, 0, 1, 0},
        {0, 0, 0, 1}} 
    };  
    Vector objectPosition = GetPositionVectorFromMatrix(MultiplyMatrix(objectTransformMatrix, translateMatrix));
    // renderer.RenderVector(objectPosition);
    renderer.DrawPoint(objectPosition[0], objectPosition[1]);
}
void MoveParentWithChildren()
{
    ParentObject parentObject;
    ChildObject childObject;
    Matrix translateMatrix = {
        {{1, 0, 0, 2},
        {0, 1, 0, 2},
        {0, 0, 1, 2},
        {0, 0, 0, 1}} 
    };  
    for (size_t i = 0; i < 1; i++)
    {
        parentObject.TransformMatrix =
            MultiplyMatrix(parentObject.TransformMatrix, translateMatrix);
        DrawObject(parentObject.TransformMatrix, 2);

        childObject.TransformMatrix = 
            MultiplyMatrix(childObject.TransformMatrix, translateMatrix);
        DrawObject(childObject.TransformMatrix, 1);
    }
}
void RotateObject()
{
    TranslateAndRotate translateAndRotate;
    double rotationAngleDegrees = 0;

    ParentObject parentObject;
    for (size_t i = 0; i < 11; i++)
    {
        rotationAngleDegrees += 1;
        double rotationAngle = rotationAngleDegrees * M_PI / 180;
        parentObject.TransformMatrix = translateAndRotate.RotateMatrixOnZ(parentObject.TransformMatrix, rotationAngle);
            
        DrawObject(parentObject.TransformMatrix, 2);

    }
}
int main(int argc, char *argv[])
{
    // MoveParentWithChildren();
    RotateObject();
    
    // rotate the parent dot 90 degrees
    // renderer.DrawPoint(15, 15); // origin point
    return 0;
}

// TIP: ctrl + w + s or v split. ctrl + hjkl change window. ctrl + w + q quit
// window Space + / toggle comment
