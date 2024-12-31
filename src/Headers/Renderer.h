#pragma once
#include "ncurses.h"
#include <iostream>
#include "Matrix.h"
class Renderer
{
  public:
    void Render();
    void RendererMatrix(const Matrix& matrix);
    void RenderVector(const Vector& vector);
    void GoToXY(int x, int y) { std::cout << "\033[" << y << ";" << x << "H"; }
    void HideCursor() { curs_set(0); }
};
