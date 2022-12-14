#include "PlayerController.h"
#include <iostream>

using namespace sf;
using namespace gm;
using namespace std;	// debug


gm::PlayerController::PlayerController(Paddle* paddle)
{
	this->paddle = paddle;
}

void gm::PlayerController::handleInput(Event event)
{
	if (event.type == Event::KeyPressed) {
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			paddle->move(Vector2f(0, -1));
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			paddle->move(Vector2f(0, 1));
		}
	}
}

void gm::PlayerController::update()
{

}

PlayerController::~PlayerController()
{

}
