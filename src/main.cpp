#include "Renderer.h"
#include "GameObjects/ParentObject.h"
#include "TranslateAndRotate.h"

void DrawObject(Matrix objectTransformMatrix)
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << objectTransformMatrix[i][3];
    }
}
int main(int argc, char *argv[])
{
    Renderer renderer;
    TranslateAndRotate translateAndRotate;

    double rotationAngleDegrees = 90;
    double rotationAngle = rotationAngleDegrees * M_PI / 180;

    // TODO: put second dot to a position
    // translate position of the dot
    // create second dot as child of the first dot
    // rotate the parent dot 90 degrees
    ParentObject parenObject;
    DrawObject(parenObject.TransformMatrix);
    //renderer.DrawPoint(15, 15); // origin point
    return 0;
}
