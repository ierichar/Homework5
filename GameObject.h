#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#define SPEED_MAX 10.f

// Use our gm namespace for all our defined classes
namespace gm {
	// Our abstract GameObject class that defines the interface for all objects that appear in our games
	class GameObject
	{
	private:
	// Protected accessibility allows direct access for deriving classes
	protected:
		// All GameObjects should have a position
		sf::Vector2f position;
		// All GameObjects should have a collider
		sf::FloatRect collider;
	public:
		// Default constructor
		GameObject();

		// Overloaded constructor that takes a position
		GameObject(const sf::Vector2f& position, const sf::Vector2f& size);

		// Our update interface, NOTE it is a pure virtual function
		virtual void update(sf::RenderWindow& window) = 0;

		// Our render interface, NOTE it is a pure virtual function
		virtual void render(sf::RenderWindow& window) = 0;

		// Our position getter, NOTE the const reference return and marking the method itself const
		virtual const sf::Vector2f& getPosition() const;

		// Our position setter, NOTE the pass by const reference
		virtual void setPosition(const sf::Vector2f& position);

		// Our collision getter, NOTE the const reference return and marking the method itself const
		virtual const sf::FloatRect& getCollider() const;

		virtual bool collide(const sf::Vector2f& point) const;

		virtual bool collide(const sf::Vector2i& point) const;

		virtual bool collide(const sf::FloatRect& rect) const;

		// Apply vector force to move gameobject
		virtual void move(const sf::Vector2f& force) = 0;
	};
}

#endif