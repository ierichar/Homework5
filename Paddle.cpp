#include "Paddle.h"

using namespace sf;
using namespace gm;

Paddle::Paddle(const sf::Vector2f& position, const sf::Vector2f& size)
	: GameObject(position, size) {
	body.setPosition(position);
	body.setSize(size);
}

void gm::Paddle::update(sf::RenderWindow& window)
{
	body.setPosition(this->GameObject::getPosition());
}

void gm::Paddle::render(sf::RenderWindow& window)
{
	window.draw(body);
}

void Paddle::move(const Vector2f& force)
{
	this->GameObject::move(force);
}

Paddle::~Paddle()
{

}