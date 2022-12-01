#ifndef SQUARE_BALL_H
#define SQUARE_BALL_H

#include <math.h>

#include "GameObject.h"

#define PI 3.1415192654
#define BALL_SPEED 10.0f

namespace gm {
    class SquareBall :
        public GameObject
    {
    private:
        sf::CircleShape body;
        sf::Vector2f velocity;
    public:
        SquareBall(const sf::Vector2f& position, const float radius);

        // Our update interface, NOTE it is a pure virtual function
        virtual void update(sf::RenderWindow& window);

        // Our render interface, NOTE it is a pure virtual function
        virtual void render(sf::RenderWindow& window);

        virtual const sf::Vector2f& getPosition() const;

        virtual void setPosition(const sf::Vector2f& position);

        virtual void move(const sf::Vector2f& force);

        const sf::Vector2f& getVelocity() const;

        void setVelocity(const sf::Vector2f& velocity);

        void bounce(const sf::Vector2f& normalVector);

        virtual void move(const sf::Vector2f& force) override;

        // Vector Math Helper Functions
        const float calcMagnitude(const sf::Vector2f& vector);
        sf::Vector2f vScalarProduct(const float c, const sf::Vector2f & vector);
        const float dotProduct(const sf::Vector2f& v1, const sf::Vector2f& v2);
    };
}

#endif // !CIRCLE_H
