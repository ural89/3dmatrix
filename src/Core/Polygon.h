#pragma once
#include "Matrix.h"
#include "TranslateAndRotate.h"

class Polygon
{
private:
    TranslateAndRotate translateAndRotate;

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
    Matrix* vertices[4] = {
        &LeftTop,
        &RightTop,
        &RightBottom,
        &LeftBottom
    };
    void RotateAround(double DeltaTime)
    {
        double rotationAngleDegrees = 90; 
        double rotationAngle = rotationAngleDegrees * M_PI / 180 * DeltaTime;

        LeftTopLocal = translateAndRotate.RotateMatrixOnZ(LeftTopLocal, rotationAngle);
        RightTopLocal = translateAndRotate.RotateMatrixOnZ(RightTopLocal, rotationAngle);
        LeftBottomLocal = translateAndRotate.RotateMatrixOnZ(LeftBottomLocal, rotationAngle);
        RightBottomLocal = translateAndRotate.RotateMatrixOnZ(RightBottomLocal, rotationAngle);

        LeftTop = MultiplyMatrix(PolygonTransform, LeftTopLocal);
        RightTop = MultiplyMatrix(PolygonTransform, RightTopLocal);
        LeftBottom = MultiplyMatrix(PolygonTransform, LeftBottomLocal);
        RightBottom = MultiplyMatrix(PolygonTransform, RightBottomLocal);

        Matrix translateMatrix = {
            {{1, 0, 0, 0.3},
             {0, 1, 0, 0.3},
             {0, 0, 1, 0},
             {0, 0, 0, 1}}};
        // PolygonTransform = MultiplyMatrix(PolygonTransform, translateMatrix);
    }

};

