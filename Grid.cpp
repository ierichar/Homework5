#include "Grid.h"

using namespace sf;
using namespace gm;

Grid::Grid(int width, int height) : width(width), tilesInWidth(width/TileSize), height(height), tilesInHeight(height/TileSize), startPosition(PositionNotSet), goalPosition(PositionNotSet), drawMode(TileType::Obstacle) {
	// Create a new Tile* array that will hold the array for each tile
	tiles = new Tile* [tilesInHeight];

	// Go through each element of the outer array and create a tile array row
	for (int row = 0; row < tilesInHeight; row++) {
		tiles[row] = new Tile[tilesInWidth];
	
		// Now go through this row and setup each tile
		for (int col = 0; col < tilesInWidth; col++) {
			tiles[row][col].setPosition(Vector2f(col * TileSize, row * TileSize));
		}
	}
}

void Grid::handleInput(RenderWindow& window, const Event& event) {
	// Handle keyboard input to change the grid draw mode
	if (event.type == Event::KeyPressed) {
		switch (event.key.code) {
		case Keyboard::Num1:
			drawMode = TileType::Empty;
			break;
		case Keyboard::Num2:
			drawMode = TileType::Obstacle;
			break;
		case Keyboard::Num3:
			drawMode = TileType::Start;
			break;
		case Keyboard::Num4:
			drawMode = TileType::Goal;
			break;
		}
	}

	// Place a tile on left mouse click
	if(Mouse::isButtonPressed(Mouse::Left)){
		// Go through each tile and see if we clicked on it. If so, update type according to draw mode
		for (int row = 0; row < tilesInHeight; row++) {
			for (int col = 0; col < tilesInWidth; col++) {
				if (tiles[row][col].intersect(Mouse::getPosition(window))) {
					switch (drawMode) {
					case TileType::Start:
						// If the tile was previously the goal position, don't forget to reset that now that we are the start position instead
						if (tiles[row][col].getType() == TileType::Goal) {
							goalPosition = PositionNotSet;
						}
							
						// If the previous start position was already set then set that old tile to empty since we can only ever have one start position
						if (startPosition != PositionNotSet) {
							tiles[startPosition.y][startPosition.x].setType(Empty);
						}

						// Store the new start position
						startPosition.x = col;
						startPosition.y = row;

						break;
					case TileType::Goal:
						// If the tile was previously the start position, don't forget to reset that now that we are the goal position instead
						if (tiles[row][col].getType() == TileType::Start) {
							startPosition = PositionNotSet;
						}

						// If the previous goal position was already sent then set that old tile to empty since we can only ever have one goal position
						if (goalPosition != PositionNotSet) {
							tiles[goalPosition.y][goalPosition.x].setType(Empty);
						}

						// Store the new goal position
						goalPosition.x = col;
						goalPosition.y = row;

						break;
					default:
						// If the tile was previously the start or goal position, don't forget to reset that now that we are a different tile
						if (tiles[row][col].getType() == TileType::Start) {
							startPosition = PositionNotSet;
						}else if (tiles[row][col].getType() == TileType::Goal) {
							goalPosition = PositionNotSet;
						}
					}

					// Set the tile to our new type
					tiles[row][col].setType(drawMode);
				}
			}
		}
	}
}

void Grid::update(RenderWindow& window){
	// Go through each tile and update it
	for (int row = 0; row < tilesInHeight; row++) {
		for (int col = 0; col < tilesInWidth; col++) {
			tiles[row][col].update(window);
		}
	}
}

void Grid::render(RenderWindow& window) {
	// Go through each tile and render it
	for (int row = 0; row < tilesInHeight; row++) {
		for (int col = 0; col < tilesInWidth; col++) {
			tiles[row][col].render(window);
		}
	}
}

int Grid::getTilesInWidth() const {
	return tilesInWidth;
}

int Grid::getTilesInHeight() const {
	return tilesInHeight;
}
void Grid::setTileType(int row, int column, TileType type) {
	tiles[row][column].setType(type);
}

TileType Grid::getTileType(int row, int column) const {
	return tiles[row][column].getType();
}

const Vector2i& Grid::getStartPosition() const {
	return startPosition;
}

const Vector2i& Grid::getGoalPosition() const {
	return goalPosition;
}

void Grid::clearSearch() {
	for (int row = 0; row < tilesInHeight; row++) {
		for (int col = 0; col < tilesInWidth; col++) {
			if (getTileType(row, col) == TileType::Visited || getTileType(row, col) == TileType::Explored || getTileType(row, col) == TileType::Path) {
				setTileType(row, col, TileType::Empty);
			}
		}
	}
}

Grid::~Grid() {
	// Go through and delete each tile array row first
	for (int row = 0; row < tilesInHeight; row++) {
		delete[] tiles[row];
	}
	// Then delete the outer array holding all the rows
	delete[] tiles;
}