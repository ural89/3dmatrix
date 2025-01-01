#include "Renderer.h"
#include "TranslateAndRotate.h"

int main(int argc, char *argv[])
{
    Renderer renderer;
    TranslateAndRotate translateAndRotate;

    double rotationAngleDegrees = 90;
    double rotationAngle = rotationAngleDegrees * M_PI / 180;

    renderer.DrawPoint(15, 15);

    //    renderer.GoToXY(10, 10);
    //    renderer.Render();
    return 0;
}
