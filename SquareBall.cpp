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
	body.setPosition(this->getPosition());
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
	// Assume velocity nor normalVector is 0 vector
	// v is the approach vector
	// n is the normal of the wall
	// u = (v dot n / n dot n) n
	// w = v - u
	if (velocity != Vector2f(0, 0) && normalVector != Vector2f(0, 0)) {
		Vector2f uVector, wVector;

		float scalar = dotProduct(velocity, normalVector) / dotProduct(normalVector, normalVector);
		cout << "dot product result: " << scalar << endl;
		uVector = Vector2f(scalar * normalVector.x, scalar * normalVector.y);
		cout << "new x: " << uVector.x << ", new y: " << uVector.y << endl;
		setVelocity(velocity - uVector);	// our w-vector given by: w = v - u
	}
	return;
}

const float gm::SquareBall::calcMagnitude(const sf::Vector2f& vector) 
{
	float magnitude = float(pow(pow(vector.x, 2) + pow(vector.y, 2), 2));
	cout << "mag is " << magnitude << endl;
	return magnitude;
}

const float gm::SquareBall::angleBetweenVectors(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	float theta = ((v1.x * v2.x) + (v1.y * v2.y)) / float((calcMagnitude(v1) * calcMagnitude(v2)));
	cout << "angle is " << theta << endl;
	return acos(theta);
}

const float gm::SquareBall::dotProduct(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	return (calcMagnitude(v1) * calcMagnitude(v2) * cos(angleBetweenVectors(v1, v2)));
}
