#include "matrix.hpp"

#include <math.h>

float thetaX {0.01f};
float thetaY {0.02f};
float thetaZ {0.03f};

// Definition des variables externes présente dans matrix.hpp
Matrix3x3 rotationMatrixX= {{
    {1, 0, 0},
    {0, cos(thetaX), -sin(thetaX)},
    {0, sin(thetaX), cos(thetaX)}
}};

Matrix3x3 rotationMatrixY= {{
    {cos(thetaY), 0, sin(thetaY)},
    {0, 1, 0},
    {-sin(thetaY), 0, cos(thetaY)}
}};

Matrix3x3 rotationMatrixZ= {{
    {cos(thetaZ), -sin(thetaZ), 0},
    {sin(thetaZ), cos(thetaZ), 0},
    {0, 0, 1}
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

void updateCubeLines(sf::VertexArray &lines, std::array<Matrix1x3, 8> &vertices){
    lines[0] = sf::Vertex(sf::Vector2f(vertices[0][0] * SCALE + OFFSET_X, vertices[0][1] * SCALE + OFFSET_Y));
    lines[1] = sf::Vertex(sf::Vector2f(vertices[1][0] * SCALE + OFFSET_X, vertices[1][1] * SCALE + OFFSET_Y));

    lines[2] = sf::Vertex(sf::Vector2f(vertices[1][0] * SCALE + OFFSET_X, vertices[1][1] * SCALE + OFFSET_Y));
    lines[3] = sf::Vertex(sf::Vector2f(vertices[2][0] * SCALE + OFFSET_X, vertices[2][1] * SCALE + OFFSET_Y));

    lines[4] = sf::Vertex(sf::Vector2f(vertices[2][0] * SCALE + OFFSET_X, vertices[2][1] * SCALE + OFFSET_Y));
    lines[5] = sf::Vertex(sf::Vector2f(vertices[3][0] * SCALE + OFFSET_X, vertices[3][1] * SCALE + OFFSET_Y));

    lines[6] = sf::Vertex(sf::Vector2f(vertices[3][0] * SCALE + OFFSET_X, vertices[3][1] * SCALE + OFFSET_Y));
    lines[7] = sf::Vertex(sf::Vector2f(vertices[0][0] * SCALE + OFFSET_X, vertices[0][1] * SCALE + OFFSET_Y));

    lines[8] = sf::Vertex(sf::Vector2f(vertices[4][0] * SCALE + OFFSET_X, vertices[4][1] * SCALE + OFFSET_Y));
    lines[9] = sf::Vertex(sf::Vector2f(vertices[5][0] * SCALE + OFFSET_X, vertices[5][1] * SCALE + OFFSET_Y));

    lines[10] = sf::Vertex(sf::Vector2f(vertices[5][0] * SCALE + OFFSET_X, vertices[5][1] * SCALE + OFFSET_Y));
    lines[11] = sf::Vertex(sf::Vector2f(vertices[6][0] * SCALE + OFFSET_X, vertices[6][1] * SCALE + OFFSET_Y));

    lines[12] = sf::Vertex(sf::Vector2f(vertices[6][0] * SCALE + OFFSET_X, vertices[6][1] * SCALE + OFFSET_Y));
    lines[13] = sf::Vertex(sf::Vector2f(vertices[7][0] * SCALE + OFFSET_X, vertices[7][1] * SCALE + OFFSET_Y));

    lines[14] = sf::Vertex(sf::Vector2f(vertices[7][0] * SCALE + OFFSET_X, vertices[7][1] * SCALE + OFFSET_Y));
    lines[15] = sf::Vertex(sf::Vector2f(vertices[4][0] * SCALE + OFFSET_X, vertices[4][1] * SCALE + OFFSET_Y));

    lines[16] = sf::Vertex(sf::Vector2f(vertices[0][0] * SCALE + OFFSET_X, vertices[0][1] * SCALE + OFFSET_Y));
    lines[17] = sf::Vertex(sf::Vector2f(vertices[5][0] * SCALE + OFFSET_X, vertices[5][1] * SCALE + OFFSET_Y));

    lines[18] = sf::Vertex(sf::Vector2f(vertices[1][0] * SCALE + OFFSET_X, vertices[1][1] * SCALE + OFFSET_Y));
    lines[19] = sf::Vertex(sf::Vector2f(vertices[6][0] * SCALE + OFFSET_X, vertices[6][1] * SCALE + OFFSET_Y));

    lines[20] = sf::Vertex(sf::Vector2f(vertices[2][0] * SCALE + OFFSET_X, vertices[2][1] * SCALE + OFFSET_Y));
    lines[21] = sf::Vertex(sf::Vector2f(vertices[7][0] * SCALE + OFFSET_X, vertices[7][1] * SCALE + OFFSET_Y));

    lines[22] = sf::Vertex(sf::Vector2f(vertices[3][0] * SCALE + OFFSET_X, vertices[3][1] * SCALE + OFFSET_Y));
    lines[23] = sf::Vertex(sf::Vector2f(vertices[4][0] * SCALE + OFFSET_X, vertices[4][1] * SCALE + OFFSET_Y));

    // Nous mettons les arrêtes en couleur noir
    for (int i = 0; i < 24; ++i) {
        lines[i].color = sf::Color::Black;
    }
}

void initCircles(std::array<sf::CircleShape, 8> &circles, const std::array<Matrix1x3, 8> &vertices){
    for(int i{0}; i < 8; ++i){
        circles[i] = sf::CircleShape(1.f);
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

void applyRotation(std::array<Matrix1x3, 8> &vertices, const Matrix3x3& mat) {
    for (auto& vertex : vertices) {
        vertex = multiplyMatrix(vertex, mat);
    }
}
