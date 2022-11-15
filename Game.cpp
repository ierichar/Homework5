// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include <iostream>

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;
using namespace std;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GAME_WIDTH, GAME_HEIGHT), "Game"),
	box1(Vector2f(0, 0), Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT)),
	box2(Vector2f(GAME_WIDTH - PADDLE_WIDTH, 0), Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT)),
	circle1(Vector2f(GAME_WIDTH/2 - BALL_RADIUS, GAME_WIDTH/2 - BALL_RADIUS),  BALL_RADIUS),
	isGameStart(false) {
	// Set our fps to 60
	window.setFramerateLimit(60);
}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	while (window.isOpen())
	{
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
			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				cout << "test up" << endl;
				box1.move(Vector2f(0, -1));
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down)) {
				cout << "test down" << endl;
				box1.move(Vector2f(0, 1));
			}
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	box1.update(window);
	box2.update(window);
	circle1.update(window);
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	box1.render(window);
	box2.render(window);
	circle1.render(window);

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}