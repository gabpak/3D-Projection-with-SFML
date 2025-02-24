#include "matrix.hpp"

// Definition de la variable extern présente dans matrix.hpp
Matrix3x3 projectionMatrix = {{
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
}};

Matrix1x3 multiplyMatrix(const Matrix1x3& vec, const Matrix3x3& mat){
    Matrix1x3 result = {0.f, 0.f, 0.f};
    for(int j{0}; j < 3; ++j){
        for(int i{0}; i < 3; ++i){
            result[j] += vec[i] * mat[i][j];
        }
    }
    return result;
}

void initCubeVertices(std::array<Matrix1x3, 8> &arr){
    arr[0] = {-1.f, -1.f, -1.f};
    arr[1] = {-1.f, 1.f, -1.f};
    arr[2] = {1.f, 1.f, -1.f};
    arr[3] = {1.f, -1.f, -1.f};

    arr[4] = {1.f, -1.f, 1.f};
    arr[5] = {-1.f, -1.f, 1.f};
    arr[6] = {-1.f, 1.f, 1.f};
    arr[7] = {1.f, 1.f, 1.f};
}

void initCircles(std::array<sf::CircleShape, 8> &circles, const std::array<Matrix1x3, 8> &vertices){
    for(int i{0}; i < 8; ++i){
        circles[i] = sf::CircleShape(2.5);
        circles[i].setFillColor(sf::Color::Black);
    }

    circles[0].setPosition(vertices[0][0] * SCALE + OFFSET_X, vertices[0][1] * SCALE + OFFSET_Y);
    circles[1].setPosition(vertices[1][0] * SCALE + OFFSET_X, vertices[1][1] * SCALE + OFFSET_Y);
    circles[2].setPosition(vertices[2][0] * SCALE + OFFSET_X, vertices[2][1] * SCALE + OFFSET_Y);
    circles[3].setPosition(vertices[3][0] * SCALE + OFFSET_X, vertices[3][1] * SCALE + OFFSET_Y);

    circles[4].setPosition(vertices[4][0] * SCALE + OFFSET_X, vertices[4][1] * SCALE + OFFSET_Y);
    circles[5].setPosition(vertices[5][0] * SCALE + OFFSET_X, vertices[5][1] * SCALE + OFFSET_Y);
    circles[6].setPosition(vertices[6][0] * SCALE + OFFSET_X, vertices[6][1] * SCALE + OFFSET_Y);
    circles[7].setPosition(vertices[7][0] * SCALE + OFFSET_X, vertices[7][1] * SCALE + OFFSET_Y);
}

