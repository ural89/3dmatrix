#include "Renderer.h"
#include "ncurses.h"

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

Renderer::~Renderer()
{
    endwin(); // Restore the terminal settings when the renderer is destroyed
}

void Renderer::DrawPoint(int x, int y)
{
    // Check if the coordinates are within bounds
    if (x >= 0 && y >= 0 && x < COLS && y < LINES)
    {
        mvprintw(y, x, "x"); // Draw 'x' at the given position
    }
    else
    {
        // Debug message for out-of-bound coordinates
        mvprintw(0, 0, "Coordinates out of bounds: x=%d, y=%d", x, y);
    }
}

void Renderer::SetConsoleColor(int color)
{
    // Use a dynamic color pair ID based on the input color
    static int pairId = 1;
    init_pair(pairId, color, COLOR_BLACK);
    attron(COLOR_PAIR(pairId));
    pairId++;
}

void Renderer::RendererMatrix(const Matrix &matrix)
{
    int y = 0;
    for (const auto &row : matrix)
    {
        int x = 0;
        for (const auto &value : row)
        {
            mvprintw(y, x * 4, "%0.2f", value); // Print the matrix values
            x++;
        }
        y++;
    }
}

void Renderer::RenderVector(const Vector &vector)
{
    int x = 0;
    for (const auto value : vector)
    {
        mvprintw(0, x * 4, "%0.2f", value); // Print the vector values
        x++;
    }
}

