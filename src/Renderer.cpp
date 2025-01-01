#include "Renderer.h"
#include <cmath>
#include <iostream>
void Renderer::Render()
{
    system("clear");
    for (size_t i = 0; i < 10; i++)
    {
        GoToXY(i, i);
        std::cout << "X";
    }
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
