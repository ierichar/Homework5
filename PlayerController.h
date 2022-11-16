#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include "Paddle.h"

namespace gm {
	class PlayerController
	{
	private:
		Paddle* paddle;
		// include key codes for multiple players
	public:
		PlayerController(Paddle* paddle);
		void handleInput(sf::Event event);
		void update();
		~PlayerController();
	};
}

#endif
