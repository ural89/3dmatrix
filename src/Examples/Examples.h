#pragma  once
#include "../GameObjects/ChildObject.h"
#include "../GameObjects/ParentObject.h"
#include "Matrix.h"
#include "Polygon.h"
#include "Renderer.h"
#include "TranslateAndRotate.h"
#include <chrono>
#include <thread>
#include "ncurses.h"

void static RotateObject(Renderer& renderer)
{
    TranslateAndRotate translateAndRotate;
    double rotationAngleDegrees = 0;

    ParentObject parentObject;
    for (size_t i = 0; i < 10; i++)
    {
        rotationAngleDegrees += 1;
        double rotationAngle = rotationAngleDegrees * M_PI / 180;
        parentObject.TransformMatrix = translateAndRotate.RotateMatrixOnZ(parentObject.TransformMatrix, rotationAngle);
            
        renderer.DrawObject(parentObject.TransformMatrix, 2);

    }
}
void static RotateObjectWithChild(Renderer &renderer)
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

    while (true)
    {
        clear(); // Clear the screen

        rotationAngleDegrees = 30;
        double rotationAngle = rotationAngleDegrees * M_PI / 180;
        childObject.LocalTransformMatrix = translateAndRotate.RotateMatrixOnZ(childObject.LocalTransformMatrix, rotationAngle);
        childObject.TransformMatrix = MultiplyMatrix(parentObject.TransformMatrix, childObject.LocalTransformMatrix);

        parentObject.TransformMatrix = MultiplyMatrix(parentObject.TransformMatrix, translateMatrix);

        renderer.DrawObject(parentObject.TransformMatrix, 3);
        renderer.DrawObject(childObject.TransformMatrix, 5);

        refresh(); // Refresh the screen to apply changes
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
void static MoveParentWithChildren(Renderer& renderer)
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
        renderer.DrawObject(parentObject.TransformMatrix, 2);

        childObject.TransformMatrix = 
            MultiplyMatrix(parentObject.TransformMatrix, childObject.LocalTransformMatrix);
        renderer.DrawObject(childObject.TransformMatrix, 1);
    }
}
void static RenderPolygon(Renderer& renderer)
{
    Polygon polygon;
    
    while (true)
    {
        clear(); // Clear the screen

        polygon.RotateAround();
        renderer.RenderPolygon(polygon);
        // renderer.RenderMatrix(*polygon.vertices[1]);
        refresh(); // Refresh the screen to apply changes
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

