#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

#include "matrix.hpp"
#include "constants.hpp"

std::array<Matrix1x3, 8> cubeVertices;  // Coordonnées des sommets du cube.
std::array<sf::CircleShape, 8> circles; // Les 8 sommets du cube (graphique)
sf::VertexArray lines(sf::Lines, 24);   // Coordonnées des arrêtes du cube

int main()
{
    initCubeVertices(cubeVertices); // On initialise les coordonnées du cubes
    initCircles(circles, cubeVertices); // Initialisation des 8 sommets (graphique)

    // Créer une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML Projection", sf::Style::None);
    window.setFramerateLimit(60);

    // Boucle principale
    while(window.isOpen())
    {
        // Gestion des événements
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    window.close();
                }
            }
        }

        // Appliquer la rotation sur X, Y et Z au cube
        applyRotation(cubeVertices, rotationMatrixY);
        applyRotation(cubeVertices, rotationMatrixX);
        applyRotation(cubeVertices, rotationMatrixZ);

        // Mettre à jour les 8 sommets du cube
        for(int i = 0; i < 8; ++i) {
            circles[i].setPosition(
                OFFSET_X + SCALE * cubeVertices[i][0], 
                OFFSET_Y + SCALE * cubeVertices[i][1]
            );
        }

        // Mettre à jour les 12 arrêtes du cube
        updateCubeLines(lines, cubeVertices);

        // Effacer la fenêtre avec une couleur blanche
        window.clear(sf::Color::White);

        // Dessiner les 12 arrêtes du cube (12x2 pour les coordonnées)
        for(int i{0}; i < 24; ++i){
            window.draw(lines);
        }

        // Afficher le contenu de la fenêtre
        window.display();
    }

    return 0;
}
