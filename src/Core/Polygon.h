#pragma once
#include "Matrix.h"
#include "TranslateAndRotate.h"
#include <cstdlib>

class Polygon
{
private:
    TranslateAndRotate translateAndRotate;
    double rotationAngle;
    double rotationSpeed;

    Matrix PolygonTransform = {
        {{2, 0, 0, 25},
         {0, 1, 0, 0},
         {0, 0, 1, 0},
         {0, 0, 0, 1}}};
;

    Matrix LeftTopLocal =  {
        {{1, 0, 0, -5},
         {0, 1, 0, -5},
         {0, 0, 1, 0},
         {0, 0, 0, 1}}};
;
    Matrix RightTopLocal = {
        {{1, 0, 0, 5},
         {0, 1, 0, -5},
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

    Matrix LeftTop = IdentityMatrix;
    Matrix RightTop = IdentityMatrix;
    Matrix LeftBottom = IdentityMatrix;
    Matrix RightBottom = IdentityMatrix;

public:
    Polygon() : rotationSpeed(rand() % 5 + 59) 
    {
        double randomScale = (rand() % 200) / 100. + 1;
        Matrix translateMatrix = {
            {{randomScale, 0, 0, 0},
             {0, randomScale, 0, 0},
             {0, 0, 1, 0},
             {0, 0, 0, 1}}};
        PolygonTransform = MultiplyMatrix(PolygonTransform, translateMatrix);
    }
    void SetTransformMatrix(Matrix transformMatrix)
    {
        PolygonTransform = transformMatrix;
    }

    Matrix* vertices[4] = {
        &LeftTop,
        &RightTop,
        &RightBottom,
        &LeftBottom
    };
    void RotateAround(double DeltaTime)
    {
        rotationAngle = rotationSpeed * M_PI / 180 * DeltaTime;

        LeftTopLocal = translateAndRotate.RotateMatrixOnZ(LeftTopLocal, rotationAngle);
        RightTopLocal = translateAndRotate.RotateMatrixOnZ(RightTopLocal, rotationAngle);
        LeftBottomLocal = translateAndRotate.RotateMatrixOnZ(LeftBottomLocal, rotationAngle);
        RightBottomLocal = translateAndRotate.RotateMatrixOnZ(RightBottomLocal, rotationAngle);

        LeftTop = MultiplyMatrix(PolygonTransform, LeftTopLocal);
        RightTop = MultiplyMatrix(PolygonTransform, RightTopLocal);
        LeftBottom = MultiplyMatrix(PolygonTransform, LeftBottomLocal);
        RightBottom = MultiplyMatrix(PolygonTransform, RightBottomLocal);

    }

};

