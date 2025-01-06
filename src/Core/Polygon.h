#pragma once
#include "Matrix.h"
#include "TranslateAndRotate.h"
#include <cstdio>
#include <ncurses.h>

class Polygon
{
    // TODO: try polygon matrix for each vertex
    // but change if not makes sense
  private:
    TranslateAndRotate translateAndRotate;

    Matrix RightTop =  IdentityMatrix;
    Matrix LeftTop =  IdentityMatrix;
    Matrix LeftBottom =  IdentityMatrix;
    Matrix RightBottom =  IdentityMatrix;

    Matrix LeftTopLocal = {{
        {1, 0, 0, -5},
        {0, 1, 0, 0},
        {0, 0, 1, 0}, 
        {0, 0, 0, 1}}};
    Matrix RightTopLocal = {
        {{1, 0, 0, 5},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}}};
    Matrix LeftBottomLocal = {
        {{1, 0, 0, -5},
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
        &LeftTop,
        &RightTop,
        &RightBottom,
        &LeftBottom
    };
    void RotateAround()
    {

        Matrix PolygonTransform = IdentityMatrix;
        Matrix RotatePointLocal = {
        {
        {1, 0, 0, 10},
        {0, 1, 0, 15},
        {0, 0, 1, 0},
        {0, 0, 0, 1}}};

        double rotationAngleDegrees = 20;
        double rotationAngle = rotationAngleDegrees * M_PI / 180;
        Matrix RotatePoint = MultiplyMatrix(PolygonTransform, RotatePointLocal);

        RightTopLocal = translateAndRotate.RotateMatrixOnZ(RightTopLocal, rotationAngle); //rotate local
        RightTop = MultiplyMatrix(RotatePoint, RightTopLocal); //find world transform from local transform
        
        LeftBottomLocal = translateAndRotate.RotateMatrixOnZ(LeftBottomLocal, rotationAngle);
        LeftBottom = MultiplyMatrix(RotatePoint, LeftBottomLocal);

        RightBottomLocal = translateAndRotate.RotateMatrixOnZ(RightBottomLocal, rotationAngle);
        RightBottom = MultiplyMatrix(RotatePoint, RightBottomLocal);

        LeftTopLocal = translateAndRotate.RotateMatrixOnZ(LeftTopLocal, rotationAngle);
        LeftTop = MultiplyMatrix(RotatePoint, LeftTopLocal);

        Matrix translateMatrix = {
        {{1, 0, 0, 0.3},
        {0, 1, 0, 0.3},
        {0, 0, 1, 0.3},
        {0, 0, 0, 1}} 
    };  
        // LeftTop = MultiplyMatrix(LeftTop , translateMatrix);
    }
};
