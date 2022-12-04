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
	ball_speed = 5.f; // starting speed
}

void SquareBall::update(sf::RenderWindow& window) {
	position.x += velocity.x * ball_speed;
	position.y += velocity.y * ball_speed;

	body.setPosition(position);
	this->setPosition(position);
}

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

// Velocity Accessor & Mutator
const sf::Vector2f& gm::SquareBall::getVelocity() const
{
	return this->velocity;
}

void SquareBall::setVelocity(const sf::Vector2f& velocity)
{
	this->velocity = velocity;
}

void SquareBall::resetBallSpeed() 
{
	ball_speed = 5.f;
}

void gm::SquareBall::increaseBallSpeed() {
	ball_speed += 1.5f;
}

void gm::SquareBall::bounce(const sf::Vector2f& normalVector)
{
	if (velocity != Vector2f(0, 0) && normalVector != Vector2f(0, 0)) {
		// Projection of Vi onto n
		// Vf = Vi - 2 * (Vi * n / mag(n)**2) * n
		Vector2f projVector, fVector;

		// (Vi * n) * n
		projVector = vScalarProduct(
			dotProduct(velocity, normalVector), normalVector);
		cout << "1: " << projVector.x << ", " << projVector.y << endl;

		// (---) / mag(n) ** 2
		projVector = vScalarProduct(1/calcMagnitude(normalVector), projVector);
		cout << "2: " << projVector.x << ", " << projVector.y << endl;

		// 2 * (---)
		projVector = vScalarProduct(2.0f, projVector);
		cout << "3: " << projVector.x << ", " << projVector.y << endl;

		// Vi - (---)
		fVector = velocity - projVector;
		cout << "4: " << fVector.x << ", " << fVector.y << endl;
		
		this->setVelocity(fVector);
	}
	return;
}

// Apply force by calling base class move
void gm::SquareBall::move(const sf::Vector2f& force)
{
	velocity += force;
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
