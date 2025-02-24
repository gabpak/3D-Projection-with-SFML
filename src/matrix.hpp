#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <array>

using Matrix1x3 = std::array<float, 3>;
using Matrix3x3 = std::array<std::array<float, 3>, 3>;

// Multiply a Vector 1x3 to a Matrix 3x3
Matrix1x3 multiplyMatrix(const Matrix1x3& vec, const Matrix3x3& mat);

#endif