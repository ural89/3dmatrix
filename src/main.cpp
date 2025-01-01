#include "Renderer.h"
#include "TranslateAndRotate.h"

int main(int argc, char *argv[])
{
    Renderer renderer;
    TranslateAndRotate translateAndRotate;

    double rotationAngleDegrees = 90;
    double rotationAngle = rotationAngleDegrees * M_PI / 180;

    //TODO: put second dot to a position
    //translate position of the dot
    //create second dot as child of the first dot
    //rotate the parent dot 90 degrees 
    renderer.DrawPoint(15, 15);
    return 0;
}
