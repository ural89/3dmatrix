#include "GameObjects/ParentObject.h"
#include "Renderer.h"
#include "TranslateAndRotate.h"

Renderer renderer;

void DrawObject(Matrix objectTransformMatrix)
{
    Vector position;
    for (int i = 0; i < 4; i++)
    {
        position[i] = objectTransformMatrix[i][3];
    }
    renderer.RenderVector(position);
    renderer.DrawPoint(position[0], position[1]);
}
int main(int argc, char *argv[])
{
    TranslateAndRotate translateAndRotate;

    double rotationAngleDegrees = 90;
    double rotationAngle = rotationAngleDegrees * M_PI / 180;

    // TODO: put second dot to a position
    // translate position of the dot
    // create second dot as child of the first dot
    // rotate the parent dot 90 degrees
    ParentObject parenObject;
    DrawObject(parenObject.TransformMatrix);
    // renderer.DrawPoint(15, 15); // origin point
    return 0;
}
