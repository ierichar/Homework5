#include "Circle.h"

using namespace gm;
using namespace sf;

Circle::Circle(const Vector2f& position, const float radius)
	: GameObject(position, Vector2f(radius, radius)) {
	body.setPosition(position);
	body.setRadius(radius);
}

// Our update interface, NOTE it is a pure virtual function
void Circle::update(sf::RenderWindow& window) {
	body.setPosition(this->getPosition());
}

// Our render interface, NOTE it is a pure virtual function
void Circle::render(sf::RenderWindow& window) {
	window.draw(body);
}