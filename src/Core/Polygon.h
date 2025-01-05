#pragma once
#include "Matrix.h"
#include <ncurses.h>

class Polygon
{
    // TODO: try polygon matrix for each vertex
    // but change if not makes sense
  private:
    Matrix LeftTop = {{{1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0}, 
        {0, 0, 0, 1}}};
    Matrix RightTop = {
        {{1, 0, 0, 5},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}}};
    Matrix LeftBottom = {
        {{1, 0, 0, 0},
        {0, 1, 0, 5},
        {0, 0, 1, 0},
        {0, 0, 0, 1}}};
    Matrix RightBottom = {
        {{1, 0, 0, 5},
        {0, 1, 0, 5},
        {0, 0, 1, 0},
        {0, 0, 0, 1}}};

  public:
    Matrix vertices[4] = {
        {LeftTop},
        {RightTop},
        {RightBottom},
        {LeftBottom},

    };
};
