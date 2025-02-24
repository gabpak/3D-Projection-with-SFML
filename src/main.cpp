#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

#include "matrix.hpp"

int main()
{
    Matrix1x3 vec = {1, 2, 3};
    Matrix3x3 mat = {{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }};

    Matrix1x3 result = multiplyMatrix(vec, mat);
    std::cout << result[0] << '\n';
    std::cout << result[1] << '\n';
    std::cout << result[2] << '\n';

    // Créer une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Projection");

    // Créer un cercle
    sf::CircleShape shape(50);
    shape.setPosition(25.f, 25.f);
    shape.setFillColor(sf::Color::Green);

    // Boucle principale
    while (window.isOpen())
    {
        // Gérer les événements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Effacer la fenêtre avec une couleur noire
        window.clear(sf::Color::Black);

        // Dessiner le cercle
        window.draw(shape);

        // Afficher le contenu de la fenêtre
        window.display();
    }

    return 0;
}
