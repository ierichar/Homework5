#ifndef CIRCLE_H
#define CIRCLE_H

#include "GameObject.h"

namespace gm {
    class Circle :
        public GameObject
    {
    private:
        sf::CircleShape body;
    public:
        Circle(const sf::Vector2f& position, const float radius);

        // Our update interface, NOTE it is a pure virtual function
        virtual void update(sf::RenderWindow& window);

        // Our render interface, NOTE it is a pure virtual function
        virtual void render(sf::RenderWindow& window);
    };
}

#endif // !CIRCLE_H
