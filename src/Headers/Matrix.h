#pragma once
#include <array>

#define Matrix std::array<std::array<int, 4>, 4>
#define Vector std::array<int, 4>

static Vector MultiplyMatrix(const Matrix& mat, const Vector& vec) {
    Vector result = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i] += mat[i][j] * vec[j];
        }
    }

    return result;
}

static Matrix MultiplyMatrix(const Matrix &mat1, const Matrix &mat2)
{
    Matrix result = {};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}
