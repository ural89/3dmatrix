#include "GameObjects/ParentObject.h"
#include "GameObjects/ChildObject.h"
#include "Matrix.h"
#include "Renderer.h"
#include "TranslateAndRotate.h"

Renderer renderer;
void DrawObject(Matrix objectTransformMatrix)
{
    Vector objectPosition = GetPositionVectorFromMatrix(objectTransformMatrix);
    // renderer.RenderVector(objectPosition);
    renderer.DrawPoint(objectPosition[0], objectPosition[1]);
}
int main(int argc, char *argv[])
{
    TranslateAndRotate translateAndRotate;

    double rotationAngleDegrees = 90;
    double rotationAngle = rotationAngleDegrees * M_PI / 180;


    // TODO: put second dot to a position
    ChildObject childObject;
    DrawObject(childObject.TransformMatrix);
    // translate position of the dot
    // create second dot as child of the first dot
    // rotate the parent dot 90 degrees
    ParentObject parenObject;
    DrawObject(parenObject.TransformMatrix);
    // renderer.DrawPoint(15, 15); // origin point
    return 0;
}

// TIP: ctrl + w + s or v split. ctrl + hjkl change window. ctrl + w + q quit window
// Space + / toggle comment
