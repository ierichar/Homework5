#include "SquareBall.h"
#include <iostream>

using namespace gm;
using namespace sf;
using namespace std;

SquareBall::SquareBall(const Vector2f& position, const float radius)
	: GameObject(position, Vector2f(radius, radius)) {
	body.setPosition(position);
	body.setRadius(radius);
	velocity = Vector2f(0, 0);
}

// Our update interface, NOTE it is a pure virtual function
void SquareBall::update(sf::RenderWindow& window) {
	this->position.x += velocity.x;
	this->position.y += velocity.y;
	body.setPosition(getPosition());
}

// Our render interface, NOTE it is a pure virtual function
void SquareBall::render(sf::RenderWindow& window) {
	window.draw(body);
}

// Position Accessor & Mutator
const sf::Vector2f& gm::SquareBall::getPosition() const
{
	return this->GameObject::getPosition();
}

void gm::SquareBall::setPosition(const sf::Vector2f& position)
{
	this->GameObject::setPosition(position);
}

// Apply force by calling base class move
void gm::SquareBall::move(const sf::Vector2f& force)
{
	velocity += force;
	velocity.x *= BALL_SPEED;
	velocity.y *= BALL_SPEED;
	this->GameObject::move(velocity);
}

// Velocity Accessor & Mutator
const sf::Vector2f& gm::SquareBall::getVelocity() const
{
	return this->velocity;
}

void gm::SquareBall::setVelocity(const sf::Vector2f& velocity)
{
	this->velocity = velocity;
}

void gm::SquareBall::bounce(const sf::Vector2f& normalVector)
{
	if (velocity != Vector2f(0, 0) && normalVector != Vector2f(0, 0)) {
		// Projection of Vi onto n
		// Vf = Vi - 2 * (Vi * n / mag(n)**2) * n

		Vector2f projVector, fVector;

		projVector = 2 * dotProduct(velocity, normalVector) * normalVector;
		projVector = vScalarProduct(calcMagnitude(normalVector), projVector);

		fVector = velocity - vScalarProduct(2.0f, projVector);

		setVelocity(fVector);
	}
	return;
}

const float gm::SquareBall::calcMagnitude(const sf::Vector2f& vector) 
{
	float magnitude = float(pow(pow(vector.x, 2) + pow(vector.y, 2), 2));
	return magnitude;
}

Vector2f gm::SquareBall::vScalarProduct(const float c, const Vector2f& vector)
{
	// vector * c = (v.x * c , v.y * c)
	Vector2f sVector = Vector2f(vector.x * c, vector.y * c);
	return sVector;
}


const float gm::SquareBall::dotProduct(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	// Dot Product Formula
	// x1 * x2 + y1 * y2
	return ((v1.x * v2.x) + (v1.y * v2.y));
}
