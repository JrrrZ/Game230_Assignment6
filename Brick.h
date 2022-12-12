#ifndef BRICK_H
#define BRICK_H

#include "GameObject.h"

using namespace sf;

namespace gm {

    struct BrickType
    {
        int hp;
        //Texture* tex;
        Color col;
        //SoundBuffer* buf;
    };

    
    class Brick :
        public GameObject
    {
    protected:
        sf::RectangleShape body;
        int type;
        int health;
        bool alive;
        int id;
    public:
        Brick(const Vector2f& position, const Vector2f& size, int t, int index);

        virtual void update(sf::RenderWindow& window, float deltaTime) override;

        virtual void render(sf::RenderWindow& window, float deltaTime) override;

        virtual void setPosition(const sf::Vector2f& position) override;

        void SetAlive(bool _alive);
        void Kill();
        int GetID();

        bool IsAlive() const;

        void SetHealth(int _health);

        int GetHealth() const;

        //void Reset();

    };
}

#endif