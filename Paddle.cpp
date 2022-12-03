#include "Paddle.h"
#include <iostream>

using namespace sf;
using namespace gm;
using namespace std;

Paddle::Paddle(const sf::Vector2f& position, const sf::Vector2f& size)
	: GameObject(position, size) {
	body.setPosition(position);
	body.setSize(size);
}

void Paddle::update(sf::RenderWindow& window)
{
	this->GameObject::setPosition(position);
	body.setPosition(position);
}

void Paddle::render(sf::RenderWindow& window)
{
	window.draw(body);
}

void Paddle::move(const Vector2f& force)
{
	this->GameObject::setPosition(getPosition() +
		Vector2f(force.x, force.y * PADDLE_SPEED));
}

Paddle::~Paddle()
{

}