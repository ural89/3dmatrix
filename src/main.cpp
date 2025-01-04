#include "GameObjects/ChildObject.h"
#include "GameObjects/ParentObject.h"
#include "Matrix.h"
#include "Renderer.h"
#include "TranslateAndRotate.h"
#include <chrono>
#include <thread>

Renderer renderer;
void DrawObject(Matrix objectTransformMatrix, int color)
{
    renderer.SetConsoleColor(color);
    // Matrix translateMatrix = {// move to origin a bit
    //     {{1, 0, 0, 100},
    //     {0, 1, 0, 30},
    //     {0, 0, 1, 0},
    //     {0, 0, 0, 1}} 
    // };  
    Vector objectPosition = GetPositionVectorFromMatrix(objectTransformMatrix);//MultiplyMatrix(objectTransformMatrix, translateMatrix));
    objectPosition[0] += 15;
    objectPosition[1] += 15;

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
    for (size_t i = 0; i < 4; i++)
    {
        parentObject.TransformMatrix =
            MultiplyMatrix(parentObject.TransformMatrix, translateMatrix);
        DrawObject(parentObject.TransformMatrix, 2);

        childObject.TransformMatrix = 
            MultiplyMatrix(parentObject.TransformMatrix, childObject.LocalTransformMatrix);
        DrawObject(childObject.TransformMatrix, 1);
    }
}
void RotateObject()
{
    TranslateAndRotate translateAndRotate;
    double rotationAngleDegrees = 0;

    ParentObject parentObject;
    for (size_t i = 0; i < 10; i++)
    {
        rotationAngleDegrees += 1;
        double rotationAngle = rotationAngleDegrees * M_PI / 180;
        parentObject.TransformMatrix = translateAndRotate.RotateMatrixOnZ(parentObject.TransformMatrix, rotationAngle);
            
        DrawObject(parentObject.TransformMatrix, 2);

    }
}

void RotateObjectWithChild()
{
    TranslateAndRotate translateAndRotate;
    double rotationAngleDegrees = 0;

    ChildObject childObject;
    ParentObject parentObject;
    Matrix translateMatrix = {
        {{1, 0, 0, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 1}} 
    };  
    for (size_t i = 0; i < 100; i++)
    {
        rotationAngleDegrees += 1;
        double rotationAngle = rotationAngleDegrees * M_PI / 180;
        childObject.LocalTransformMatrix = translateAndRotate.RotateMatrixOnZ(childObject.LocalTransformMatrix, rotationAngle);
        childObject.TransformMatrix = MultiplyMatrix(parentObject.TransformMatrix, childObject.LocalTransformMatrix);

        parentObject.TransformMatrix = MultiplyMatrix(parentObject.TransformMatrix, translateMatrix);

            
        DrawObject(parentObject.TransformMatrix, 2);
        DrawObject(childObject.TransformMatrix, 1);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }
}

int main(int argc, char *argv[])
{
    // MoveParentWithChildren();
    // RotateObject();
    RotateObjectWithChild();
    
    // rotate the parent dot 90 degrees
    // renderer.DrawPoint(15, 15); // origin point
    return 0;
}

// TIP: ctrl + w + s or v split. ctrl + hjkl change window. ctrl + w + q quit
// window Space + / toggle comment
