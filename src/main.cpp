#include "Examples/Examples.h"
#include "Renderer.h"

Renderer renderer;
int main(int argc, char *argv[])
{
    // MoveParentWithChildren(renderer);
    RotateObject(renderer);
    // RotateObjectWithChild(renderer);
    endwin();
    getch();
    return 0;
}

// TIP: ctrl + w + s or v split. ctrl + hjkl change window. ctrl + w + q quit
// window Space + / toggle comment
