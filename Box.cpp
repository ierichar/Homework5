#include "Box.h"

using namespace sf;
using namespace gm;

Box::Box(const sf::Vector2f& position, const sf::Vector2f& size)
	: GameObject(position, size) {
	body.setPosition(position);
	body.setSize(size);
}

void gm::Box::update(sf::RenderWindow& window)
{
	body.setPosition(this->GameObject::getPosition());
}

void gm::Box::render(sf::RenderWindow& window)
{
	window.draw(body);
}

