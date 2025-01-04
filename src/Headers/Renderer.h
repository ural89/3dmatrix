#pragma once
#include <iostream>
#include "Matrix.h"
class Renderer
{
  public:
    ~Renderer();
    void Render();
    void RendererMatrix(const Matrix& matrix);
    void RenderVector(const Vector& vector);
    void GoToXY(int x, int y) { std::cout << "\033[" << y << ";" << x << "H"; }
    void SetConsoleColor(int color);
    void DrawPoint(int x, int y);
};
