#include "matrix.hpp"

Matrix1x3 multiplyMatrix(const Matrix1x3& vec, const Matrix3x3& mat){
    Matrix1x3 result = {0.f, 0.f, 0.f};
    for(int j{0}; j < 3; ++j){
        for(int i{0}; i < 3; ++i){
            result[j] += vec[i] * mat[i][j];
        }
    }
    return result;
}