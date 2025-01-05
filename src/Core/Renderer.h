#pragma once
#include "Matrix.h"
class Renderer
{
  public:
    Renderer();
    ~Renderer();
    void DrawObject(Matrix objectTransformMatrix, int color);
    void RenderMatrix(const Matrix& matrix);
    void RenderVector(const Vector& vector);
    void RenderPolygon(const class Polygon& polygon);
    void SetConsoleColor(int color);
    void DrawPoint(int x, int y);
};
