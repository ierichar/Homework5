#include "Tile.h"
#include <iostream>

using namespace sf;
using namespace gm;

// Default constructor, calls the main constructor in the initializer list with required default values filled in
Tile::Tile() : Tile::Tile(Vector2f()) {}

Tile::Tile(const Vector2f& position, TileType type)
	: type(type) {
	// Create our shape with the size adjusted to incorporate padding
	shape = RectangleShape(Vector2f(TileSize - TilePadding, TileSize - TilePadding));

	// Turn our type enum into it's corresponding color and set the shape to that color
	shape.setFillColor(Color(type));

	// Set the position of both the tile and the shape using our setPosition function 
	setPosition(position);
}

void Tile::handleInput(sf::RenderWindow& window, const sf::Event& event) {

}

void Tile::update(sf::RenderWindow& window) {

}

void Tile::render(sf::RenderWindow& window) {
	window.draw(shape);
}

void Tile::setPosition(const Vector2f& position) {
	// Set both the tile position and the shape position to the new position
	GameObject::setPosition(position);
	// Note that the shape position needs to account for the TilePadding
	shape.setPosition(Vector2f(position.x + TilePadding / 2, position.y + TilePadding / 2));
}

TileType Tile::getType() const {
	return type;
}

void Tile::setType(TileType type) {
	this->type = type;
	shape.setFillColor(Color(type));
}

bool Tile::intersect(const sf::Vector2i& point) const {
	return point.x >= position.x
		&& point.x <= position.x + shape.getSize().x
		&& point.y >= position.y
		&& point.y <= position.y + shape.getSize().y;
}


Tile::~Tile() {

}