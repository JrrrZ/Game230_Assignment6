#ifndef LEVEL_H
#define LEVEL_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "Brick.h"
#include "SquareBall.h"

using namespace sf;

namespace gm {
    class Level
    {
    private:
        std::vector<Brick*> bricks;
        //SquareBall* ball;
    public:
        // Constructor
        Level(int map[5][7]);

        std::vector<Brick*> GetBricks();

        void update(sf::RenderWindow& window, float deltaTime, SquareBall* ball);

        void render(sf::RenderWindow& window, float deltaTime);

        // void reset();

        // Destructor
        ~Level();
    };
}

#endif
