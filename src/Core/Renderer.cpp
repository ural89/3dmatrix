#include "Renderer.h"
#include "ncurses.h"
#include "Polygon.h"

#include <cmath>

Renderer::Renderer()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0); // Hide the cursor
    start_color(); // Initialize color functionality
    clear(); // Clear the screen initially
}

void Renderer::DrawObject(Matrix objectTransformMatrix, int color)
{
    SetConsoleColor(color);

    Vector objectPosition = GetPositionVectorFromMatrix(objectTransformMatrix);
    objectPosition[0] += 15; // Move to origin a bit
    objectPosition[1] += 15;

    // renderer.RenderMatrix(objectTransformMatrix);
    // renderer.RenderVector(objectPosition);

    DrawPoint(objectPosition[0], objectPosition[1]);
}
Renderer::~Renderer()
{
    endwin(); // Restore the terminal settings when the renderer is destroyed
}

void Renderer::DrawPoint(int x, int y)
{
    if (x >= 0 && y >= 0 && x < COLS && y < LINES)
    {
        mvprintw(y, x, "x"); // Draw 'x' at the given position
    }
    else
    {
        mvprintw(0, 0, "Coordinates out of bounds: x=%d, y=%d", x, y);
    }
}

void Renderer::SetConsoleColor(int color)
{
    static int pairId = 1;
    init_pair(pairId, color, COLOR_BLACK);
    attron(COLOR_PAIR(pairId));
    pairId++;
}

void Renderer::RenderMatrix(const Matrix &matrix)
{
    int rowIndex = 0;
    for (const auto &row : matrix)
    {
        int colIndex = 0; 
        for (const auto &value : row)
        {
            if (std::fabs(value) < 0.01)
            {
                mvprintw(rowIndex, colIndex, "0, "); 
            }
            else
            {
                mvprintw(rowIndex, colIndex, "%.2f, ", value); 
            }
            colIndex += 6; 
        }
        rowIndex++; 
    }
}

void Renderer::RenderVector(const Vector &vector)
{
    int colIndex = 0; 
    for (const auto &value : vector)
    {
        if (std::fabs(value) < 0.01)
        {
            mvprintw(0, colIndex, "0, "); 
        }
        else
        {
            mvprintw(0, colIndex, "%.2f, ", value); 
        }
        colIndex += 8; 
    }

}

void Renderer::RenderPolygon(const Polygon& Polygon)
{

}
