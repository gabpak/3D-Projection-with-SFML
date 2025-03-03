#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "constants.hpp"

#include <SFML/Graphics.hpp>
#include <array>

constexpr float SCALE {100};
constexpr float OFFSET_X {WIDTH / 2};
constexpr float OFFSET_Y {HEIGHT / 2};
extern float thetaX;
extern float thetaY;
extern float thetaZ;

using Matrix1x3 = std::array<float, 3>;
using Matrix3x3 = std::array<std::array<float, 3>, 3>;

// Matrices
extern Matrix3x3 rotationMatrixX;
extern Matrix3x3 rotationMatrixY;
extern Matrix3x3 rotationMatrixZ;


// Multiplication d'une matrice 1x3 à 3x3
Matrix1x3 multiplyMatrix(const Matrix1x3& vec, const Matrix3x3& mat);
// Initialisation des sommets de notre cube
void initCubeVertices(std::array<Matrix1x3, 8> &arr);
// Initialisation des arrêtes
void updateCubeLines(sf::VertexArray &lines, std::array<Matrix1x3, 8> &vertices);
// Initialisation des cercles graphiques SFML avec les vertices (qui contiennent les coordonnées)
void initCircles(std::array<sf::CircleShape, 8> &circles, const std::array<Matrix1x3, 8> &vertices);
// Application des matrices de rotation
void applyRotation(std::array<Matrix1x3, 8> &vertices, const Matrix3x3& mat) ;

#endif // MATRIX_HPP