#include "Renderer.h"
#include "ncurses.h"

#include <cmath>
#include <iostream>
#include <ostream>
void Renderer::Render()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0); // Hide the cursor    
}
Renderer::~Renderer()
{
    std::cout << std::endl;
}
void Renderer::DrawPoint(int x, int y)
{
    GoToXY(x, y);
    std::cout << "x\n";
}
void Renderer::RendererMatrix(const Matrix &matrix)
{
    for (const auto &row : matrix)
    {
        for (const auto &value : row)
        {
            if (std::fabs(value) < 0.01)
            {
                std::cout << 0 << ", ";
            }
            else
            {
                std::cout << value << ", ";
            }
        }
        std::cout << '\n';
    }
}

void Renderer::RenderVector(const Vector &vector)
{

    for (const auto i : vector)
    {
        if (std::fabs(i) < 1e-10)
        {
            std::cout << 0 << ", ";
        }
        else
        {
            std::cout << i << ", ";
        }
    }
    std::cout << '\n';
}
