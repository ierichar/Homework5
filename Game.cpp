// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include <iostream>

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;
using namespace std;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GAME_WIDTH, GAME_HEIGHT), "Game"),
	p1(Vector2f(0, 0), Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT)),
	p2(Vector2f(GAME_WIDTH - PADDLE_WIDTH, 0), Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT)),
	ball(Vector2f(GAME_WIDTH/2 - BALL_RADIUS, GAME_HEIGHT/6 - BALL_RADIUS),  BALL_RADIUS),
	isGameStart(false), pController(&p1) {
	// Set our fps to 60
	window.setFramerateLimit(60);
}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	while (window.isOpen())
	{
		ball.move(Vector2f(-1, 0));

		// Every frame we...
		// Handle input first...
		handleInput();

		// Then update...
		update();

		// Then render...
		render();
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {
	// Check for events from the window
	// E.g., is the window being closed?
	Event event;
	while (window.pollEvent(event))
	{
		//std::cout << "Debug here" << std::endl;
		if (event.type == Event::Closed)
			window.close();

		if (event.type == Event::KeyPressed) {
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				// reset game
				ball.setPosition(Vector2f(
					GAME_WIDTH / 2 - BALL_RADIUS, GAME_HEIGHT / 2 - BALL_RADIUS));
			}
			else {
				pController.handleInput(event);
			}
		}

	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	p1.update(window);
	p2.update(window);
	ball.update(window);
	if (ball.getPosition().x < 10)
		cout << "bounce here!" << endl;
		ball.bounce(Vector2f(1, .2));
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	p1.render(window);
	p2.render(window);
	ball.render(window);

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}