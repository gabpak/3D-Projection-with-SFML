#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

#include "matrix.hpp"
#include "constants.hpp"

std::array<Matrix1x3, 8> cubeVertices;  // Coordonnées des sommets du cube.
std::array<sf::CircleShape, 8> circles; // Objet sfml cercle pour l'affichage graphique. 

int main()
{
    initCubeVertices(cubeVertices); // On applique les coordonnées normalisées du cubes
    initCircles(circles, cubeVertices);

    // Créer une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML Projection", sf::Style::None);
    window.setFramerateLimit(60);

    // Boucle principale
    while(window.isOpen())
    {
        // Gérer les événements
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

        // Appliquer la rotation sur X, Y et Z
        applyRotation(cubeVertices, rotationMatrixY);
        applyRotation(cubeVertices, rotationMatrixX);
        applyRotation(cubeVertices, rotationMatrixZ);

        // Mettre à jour les cercles
        for(int i = 0; i < 8; ++i) {
            circles[i].setPosition(
                OFFSET_X + SCALE * cubeVertices[i][0], 
                OFFSET_Y + SCALE * cubeVertices[i][1]
            );
        }

        // Effacer la fenêtre avec une couleur blanche
        window.clear(sf::Color::White);

        // Dessiner les sommets du cube
        for(int i{0}; i < 8; ++i){
            window.draw(circles[i]);
        }

        // Afficher le contenu de la fenêtre
        window.display();
    }

    return 0;
}
