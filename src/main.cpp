#include "LocalToWorldPosition.h"
#include "Renderer.h"
#include "TranslateAndRotate.h"
#include <cmath>

int main(int argc, char *argv[])
{
    Renderer renderer;
    TranslateAndRotate translateAndRotate;
    //renderer.RenderVector(translateAndRotate.moveVector);
    //renderer.RenderVector(translateAndRotate.rotateVector);

    LocalToWorldPosition localToWorldPosition;
    renderer.RenderVector(localToWorldPosition.objectWorldPosition);
    //    renderer.GoToXY(10, 10);
    //    renderer.Render();
    return 0;
}
