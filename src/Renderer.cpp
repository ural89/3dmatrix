#include "Renderer.h"
void Renderer::Render()
{
    system("clear");
    for (size_t i = 0; i < 10; i++)
    {
        GoToXY(i, i);
        std::cout << "X";
    }
}
