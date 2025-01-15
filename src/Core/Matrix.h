#pragma once
#include <array>
#include <xmmintrin.h>

#define Matrix std::array<std::array<double, 4>, 4>
#define Vector std::array<double, 4>

static Vector GetPositionVectorFromMatrix(const Matrix &mat)
{
    Vector positionVector;
    for (int i = 0; i < 4; i++)
    {
        positionVector[i] = mat[i][3];
    }
    return positionVector;
}
static Vector MultiplyMatrix(const Matrix &mat, const Vector &vec)
{
    Vector result = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result[i] += mat[i][j] * vec[j];
        }
    }

    return result;
}
static Matrix IdentityMatrix = {
    {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}};

static Matrix MultiplyMatrixSIMD(const Matrix &mat1, const Matrix &mat2)
{
    Matrix result = {};

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            // Accumulator for result[i][j]
            __m128d sum = _mm_setzero_pd();

            for (int k = 0; k < 4; k += 2)
            {
                // Load two doubles from the row of mat1
                __m128d row = _mm_loadu_pd(&mat1[i][k]);

                // Load two doubles from the column of mat2
                __m128d col = _mm_set_pd(mat2[k + 1][j], mat2[k][j]);

                // Multiply and accumulate
                __m128d mul = _mm_mul_pd(row, col);
                sum = _mm_add_pd(sum, mul);
            }

            // Horizontal add
            double temp[2];
            _mm_storeu_pd(temp, sum);
            result[i][j] = temp[0] + temp[1];
        }
    }

    return result;
}
static Matrix MultiplyMatrix(const Matrix &mat1, const Matrix &mat2)
{
    // return MultiplyMatrixSIMD(mat1, mat2);

    Matrix result = {};
    for (size_t i = 0; i < 4; ++i)
    {
        for (size_t j = 0; j < 4; ++j)
        {
            result[i][j] = mat1[i][0] * mat2[0][j];
            for (size_t k = 1; k < 4; ++k)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
    // Matrix result = {};
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         for (int k = 0; k < 4; k++)
    //         {
    //             result[i][j] += mat1[i][k] * mat2[k][j];
    //         }
    //     }
    // }
    // return result;
}
