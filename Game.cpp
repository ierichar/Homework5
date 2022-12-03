// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include <iostream>

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;
using namespace std;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GAME_WIDTH, GAME_HEIGHT), "Game"),
	p1(Vector2f(0 + PADDLE_WIDTH + 2*PADDING, GAME_HEIGHT/2 - PADDLE_HEIGHT/2), Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT)),
	p2(Vector2f(GAME_WIDTH - PADDLE_WIDTH - 2*PADDING, GAME_HEIGHT / 2 - PADDLE_HEIGHT / 2), Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT)),
	
	leftWall(Vector2f(0, 0), Vector2f(PADDING, GAME_HEIGHT)),
	rightWall(Vector2f(GAME_WIDTH - PADDING, 0), Vector2f(PADDING, GAME_HEIGHT)),
	ceiling(Vector2f(0, 0), Vector2f(GAME_WIDTH, PADDING)),
	floor(Vector2f(0, GAME_HEIGHT - PADDING), Vector2f(GAME_WIDTH, PADDING)),

	ball(Vector2f(GAME_WIDTH/2 - BALL_RADIUS, GAME_HEIGHT/6 - BALL_RADIUS),  BALL_RADIUS),
	
	isGameStart(false), pController(&p1) {

	// Set our fps to 60
	window.setFramerateLimit(60);

	// Load txt font
	if (!font.loadFromFile("Assets/clover-sans.ttf")) {
		//error
	}
	// Load txt properties
	p1Text.setFont(font);
	p2Text.setFont(font);
	winnerText.setFont(font);
	p1Text.setPosition(GAME_WIDTH / 2 - PADDING*4, PADDING * 5);
	p2Text.setPosition(GAME_WIDTH / 2 + PADDING*4, PADDING * 5);
	winnerText.setPosition(0 + PADDING * 15, GAME_HEIGHT / 2 - PADDING * 2);
	p1Text.setCharacterSize(PADDING * 4);
	p2Text.setCharacterSize(PADDING * 4);
	winnerText.setCharacterSize(PADDING);
	p1Text.setFillColor(Color::White);
	p2Text.setFillColor(Color::White);
	winnerText.setFillColor(Color::White);
	p1Text.setString(std::to_string(p1Score));
	p2Text.setString(std::to_string(p2Score));
	winnerText.setString("Press SPACEBAR to Play");

	// Load sound from buffer
	paddleBounce.loadFromFile("Assets/paddle_bounce.wav");
	wallBounce.loadFromFile("Assets/wall_bounce.wav");
	score.loadFromFile("Assets/score.wav");
	victory.loadFromFile("Assets/victory.wav");

	sound.setVolume(7.f);
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
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				// Reset Game
				isGameStart = true;
				// Ball, p1, p2 positions
				ball.setPosition(Vector2f(
					GAME_WIDTH / 2 - BALL_RADIUS, GAME_HEIGHT / 2 - BALL_RADIUS));
				p1.setPosition(Vector2f(
					0 + PADDLE_WIDTH + 2 * PADDING, GAME_HEIGHT / 2 - PADDLE_HEIGHT / 2));
				p2.setPosition(Vector2f(
					GAME_WIDTH - PADDLE_WIDTH - 2 * PADDING, GAME_HEIGHT / 2 - PADDLE_HEIGHT / 2));
				if (Random::Range(0, 1))
					ball.setVelocity(Vector2f(-BALL_SPEED, 0.25f)); // serve to left
				else ball.setVelocity(Vector2f(BALL_SPEED, 0.25f)); // serve to right

				// p1 p2 score
				p1Score = 0;
				p2Score = 0;
				p1Text.setString(std::to_string(p1Score));
				p2Text.setString(std::to_string(p2Score));
			}
			else { 
				pController.handleInput(event);
			}
		}

	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	// Game Victory Condition - first to 5
	if (p1Score == 5 || p2Score == 5) {
		ball.setPosition(Vector2f(
			GAME_WIDTH / 2 - BALL_RADIUS, GAME_HEIGHT / 2 - BALL_RADIUS));
		isGameStart = false;
		if (p1Score == 5) {
			// "P1 Wins!"
			winnerText.setString("P1 Wins!\n Press SPACEBAR to Play Again");
		}
		else if (p2Score == 5) {
			// "P2 Wins!"
			winnerText.setString("P2 Wins!\n Press SPACEBAR to Play Again");
		}
		else {
			//error
		}
	}

	// Paddle Behavior
	if (p2.getPosition().y > ceiling.getPosition().y &&
		p2.getPosition().y < floor.getPosition().y + PADDING) {
		if (p2.getPosition().y > ball.getPosition().y) {
			p2.move(Vector2f(0, -1.f));
		}
		else if (p2.getPosition().y < ball.getPosition().y) {
			p2.move(Vector2f(0, 1.f));
		}
	}

	if (ball.collide(p1.getCollider())) {
		sound.setBuffer(paddleBounce);
		sound.play();
		// if ball is higher than middle of paddle
		if (ball.getPosition().y/2 > (p1.getPosition().y / 2)) {
			ball.bounce(Vector2f(0.5f, 0.5f));
		}
		else if (ball.getPosition().y/2 < (p1.getPosition().y / 2)) {
			ball.bounce(Vector2f(0.5f, -0.5f));
		}
		else {
			ball.bounce(Vector2f(1.f, 0));
		}
	}
	if (ball.collide(p2.getCollider())) {
		sound.setBuffer(paddleBounce);
		sound.play();
		// if ball is higher than middle of paddle
		if (ball.getPosition().y/2 > (p2.getPosition().y / 2)) {
			ball.bounce(Vector2f(-0.5f, -0.5f));
		}
		else if (ball.getPosition().y/2 < (p2.getPosition().y / 2)) {
			ball.bounce(Vector2f(-0.5f, 0.5f));
		}
		else {
			ball.bounce(Vector2f(-1.f, 0));
		}
	}
	if (ball.collide(ceiling.getCollider())) {
		sound.setBuffer(wallBounce);
		sound.play();
		ball.bounce(Vector2f(0, -1.f));
	}	
	if (ball.collide(floor.getCollider())) {
		sound.setBuffer(wallBounce);
		sound.play();
		ball.bounce(Vector2f(0, 1.f));
	}
	if (ball.collide(leftWall.getCollider())) {
		// Mark point
		p2Score++;
		p2Text.setString(std::to_string(p2Score));

		// reset game
		ball.setPosition(Vector2f(
			GAME_WIDTH / 2 - BALL_RADIUS, GAME_HEIGHT / 2 - BALL_RADIUS));
		if (Random::Range(0, 1))
			ball.setVelocity(Vector2f(-BALL_SPEED, 0.25f)); // serve to left
		else ball.setVelocity(Vector2f(BALL_SPEED, 0.25f)); // serve to right
	}
	if (ball.collide(rightWall.getCollider())) {
		// Mark point
		p1Score++;
		p1Text.setString(std::to_string(p1Score));

		// reset game
		ball.setPosition(Vector2f(
			GAME_WIDTH / 2 - BALL_RADIUS, GAME_HEIGHT / 2 - BALL_RADIUS));
		if (Random::Range(0, 1))
			ball.setVelocity(Vector2f(-BALL_SPEED, 0.25f)); // serve to left
		else ball.setVelocity(Vector2f(BALL_SPEED, 0.25f)); // serve to right
	}

	p1.update(window);
	p2.update(window);
	if (isGameStart) {
		ball.update(window);
	}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	window.draw(p1Text);
	window.draw(p2Text);
	if (!isGameStart)
		window.draw(winnerText);

	p1.render(window);
	p2.render(window);
	ball.render(window);

	leftWall.render(window);
	rightWall.render(window);
	ceiling.render(window);
	floor.render(window);

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}