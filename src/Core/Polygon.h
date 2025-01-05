#pragma once
#include "Matrix.h"
#include "TranslateAndRotate.h"
#include <ncurses.h>

class Polygon
{
    // TODO: try polygon matrix for each vertex
    // but change if not makes sense
  public:
    TranslateAndRotate translateAndRotate;

    Matrix RightTop =  IdentityMatrix;
    Matrix LeftTop =  IdentityMatrix;
    Matrix LeftBottom =  IdentityMatrix;
    Matrix RightBottom =  IdentityMatrix;

    Matrix LeftTopLocal = {{
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0}, 
        {0, 0, 0, 1}}};
    Matrix RightTopLocal = {
        {{1, 0, 0, 5},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}}};
    Matrix LeftBottomLocal = {
        {{1, 0, 0, 0},
        {0, 1, 0, 5},
        {0, 0, 1, 0},
        {0, 0, 0, 1}}};
    Matrix RightBottomLocal = {
        {{1, 0, 0, 5},
        {0, 1, 0, 5},
        {0, 0, 1, 0},
        {0, 0, 0, 1}}};

  public:
    Matrix* vertices[4] = {
        &LeftTopLocal,
        &RightTop,
        &RightBottomLocal,
        &LeftBottomLocal
    };
    void RotateAroundTopLeft()
    {
        double rotationAngleDegrees = 5;
        double rotationAngle = rotationAngleDegrees * M_PI / 180;
        RightTopLocal = translateAndRotate.RotateMatrixOnZ(RightTopLocal, rotationAngle);
        RightTop = MultiplyMatrix(LeftTop, RightTopLocal);
        
        //
        LeftBottomLocal = translateAndRotate.RotateMatrixOnZ(LeftBottomLocal, rotationAngle);
        LeftBottom = MultiplyMatrix(LeftTop, LeftBottomLocal);
        // // 
        RightBottomLocal = translateAndRotate.RotateMatrixOnZ(RightBottomLocal, rotationAngle);
        RightBottom = MultiplyMatrix(LeftTop, RightBottomLocal);
    }
};
