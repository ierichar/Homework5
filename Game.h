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
#include "PlayerController.h"
#include "Paddle.h"
#include "SquareBall.h"

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	const int GAME_WIDTH = 640;
	const int GAME_HEIGHT = 640;
	const int PADDLE_WIDTH = 20;
	const int PADDLE_HEIGHT = 100;
	const int BALL_RADIUS = 20;

	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	private:
		sf::RenderWindow window;	// Game window
		PlayerController pController;	// Player controller

		Paddle p1;
		Paddle p2;
		SquareBall ball;
		bool isGameStart;
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