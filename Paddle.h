#ifndef PADDLE_H
#define PADDLE_H

#include "GameObject.h"

#define PADDLE_SPEED 500.0f

namespace gm {
	class Paddle :
		public GameObject
	{
	private:
		sf::RectangleShape body;
	public:
		Paddle(const sf::Vector2f& position, const sf::Vector2f& size);

		// Our update interface, NOTE it is a pure virtual function
		virtual void update(sf::RenderWindow& window);

		// Our render interface, NOTE it is a pure virtual function
		virtual void render(sf::RenderWindow& window);

		virtual void move(const sf::Vector2f& force) override;

		~Paddle();
	};
}

#endif // Paddle.h