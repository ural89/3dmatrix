#pragma once
#include "ncurses.h"
#include <iostream>
class Renderer
{
  public:
    void Render();
    void GoToXY(int x, int y) { std::cout << "\033[" << y << ";" << x << "H"; }
    void HideCursor() { curs_set(0); }
};
