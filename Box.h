#ifndef BOX_H
#define BOX_H

#include "GameObject.h"

namespace gm {
	class Box :
		public GameObject
	{
	private:
		sf::RectangleShape body;
	public:
		Box(const sf::Vector2f& position, const sf::Vector2f& size);

		// Our update interface, NOTE it is a pure virtual function
		virtual void update(sf::RenderWindow& window);

		// Our render interface, NOTE it is a pure virtual function
		virtual void render(sf::RenderWindow& window);
	};
}

#endif // Box.h