#pragma once
#include "Matrix.h"
#include <cmath>

class TranslateAndRotate
{
public:
    Matrix translationMatrix = {
        {{{1, 0, 0, 5}},
         {{0, 1, 0, -2}},
         {{0, 0, 1, 3}}, 
        {{0, 0, 0, 1}}}};

    double rotationAngleDegrees = 90;

    double rotationAngle = rotationAngleDegrees * M_PI / 180;

    Matrix rotationMatrixZ = {
        {{{std::cos(rotationAngle), -std::sin(rotationAngle), 0, 0}},
         {{std::sin(rotationAngle), std::cos(rotationAngle), 0, 0}},
         {{0, 0, 1, 0}},
         {{0, 0, 0, 1}}}};

    Vector positionVector{{2, 3, 4, 1}};

    Vector directionVector{{1, 0, 0, 1}};
    Vector moveVector = MultiplyMatrix(translationMatrix, positionVector);
    Vector rotateVector = MultiplyMatrix(rotationMatrixZ, directionVector);
};
