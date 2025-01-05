#pragma once
#include "Matrix.h"
#include <cmath>

class TranslateAndRotate
{
public:

    
    Vector RotateVectorOnZ(const Vector& vectorToRotate, float rotationAngle)
    {
        return MultiplyMatrix(GetRotationZMatrix(rotationAngle), vectorToRotate);
    }
    Matrix RotateMatrixOnZ(const Matrix& matrixToRotate, float rotationAngle)
    {
        return MultiplyMatrix(GetRotationZMatrix(rotationAngle), matrixToRotate);
    }

private:

    Matrix GetRotationZMatrix(float rotationAngle)
    {
        return{
        {{{std::cos(rotationAngle), -std::sin(rotationAngle), 0, 0}},
         {{std::sin(rotationAngle), std::cos(rotationAngle), 0, 0}},
         {{0, 0, 1, 0}},
         {{0, 0, 0, 1}}}};}
};
