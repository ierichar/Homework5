#ifndef GRID_H
#define GRID_H

#include "Tile.h"

namespace gm {
	const sf::Vector2i PositionNotSet(-1, -1);

	class Grid
	{
	private:
		int width;
		int tilesInWidth;
		int height;
		int tilesInHeight;
		sf::Vector2i startPosition;
		sf::Vector2i goalPosition;
		TileType drawMode;
		Tile** tiles;
	public:
		Grid(int width, int height);
		void handleInput(sf::RenderWindow& window, const sf::Event& event);
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		int getTilesInWidth() const;
		int getTilesInHeight() const;
		void setTileType(int row, int column, TileType type);
		TileType getTileType(int row, int column) const;
		const sf::Vector2i& getStartPosition() const;
		const sf::Vector2i& getGoalPosition() const;
		void clearSearch();
		~Grid();
	};
}
#endif