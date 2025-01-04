#include "GameObjects/ChildObject.h"
#include "GameObjects/ParentObject.h"
#include "Matrix.h"
#include "Renderer.h"
#include "TranslateAndRotate.h"

Renderer renderer;
void DrawObject(Matrix objectTransformMatrix, int color)
{
    renderer.SetConsoleColor(color);
    Vector objectPosition = GetPositionVectorFromMatrix(objectTransformMatrix);
    // renderer.RenderVector(objectPosition);
    renderer.DrawPoint(objectPosition[0], objectPosition[1]);
}
int main(int argc, char *argv[])
{
    TranslateAndRotate translateAndRotate;

    double rotationAngleDegrees = 90;
    double rotationAngle = rotationAngleDegrees * M_PI / 180;

    ParentObject parentObject;
    Matrix translateMatrix = {
        {{1, 0, 0, 2},
        {0, 1, 0, 2},
        {0, 0, 1, 2},
        {0, 0, 0, 1}} 
    };  
    for (size_t i = 0; i < 5; i++)
    {
        parentObject.TransformMatrix =
            MultiplyMatrix(parentObject.TransformMatrix, translateMatrix);
        DrawObject(parentObject.TransformMatrix, 2);

        ChildObject childObject;
        childObject.TransformMatrix = 
            MultiplyMatrix(childObject.TransformMatrix, parentObject.TransformMatrix);
        DrawObject(childObject.TransformMatrix, 1);
    }

    // translate position of the dot
    // create second dot as child of the first dot
    // rotate the parent dot 90 degrees
    // renderer.DrawPoint(15, 15); // origin point
    return 0;
}

// TIP: ctrl + w + s or v split. ctrl + hjkl change window. ctrl + w + q quit
// window Space + / toggle comment
