// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef GAME_H
#define GAME_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

 /* Our Includes */
#include "Random.h"
#include "PlayerController.h"
#include "Paddle.h"
#include "SquareBall.h"

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	const short GAME_WIDTH = 825;
	const short GAME_HEIGHT = 825;
	const short PADDING = 20;

	const short PADDLE_WIDTH = 20;
	const short PADDLE_HEIGHT = 100;

	const short BALL_RADIUS = 20;

	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	private:
		sf::RenderWindow window;	// Game window

		PlayerController pController;	// Player controller

		Paddle p1, p2, leftWall, rightWall, ceiling, floor;
		SquareBall ball;
		bool isGameStart;
		short p1Score = 0, p2Score = 0;

		sf::Font font;
		sf::Text p1Text, p2Text, winnerText;

		sf::SoundBuffer paddleBounce, wallBounce, score, victory;
		sf::Sound sound;
	public:
		/* Protoypes */
		// Constructor
		Game();
		// Will start and manage the game loop programming pattern
		void run();
		// Game Loop Programming Pattern Methods
		void handleInput();
		void update();
		void render();
		// Destructor
		~Game();
	};
}

#endif