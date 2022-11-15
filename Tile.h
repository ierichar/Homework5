#ifndef TILE_H
#define TILE_H

#include "GameObject.h"

namespace gm {
    const int TileSize = 32;
    const int TilePadding = 4;

    // All enum values will be of type uint
    // We will use the uint to representaion of a sf Color
    // That way we can both keep track of what tile an object is and color it accordingly
    // Set the r, g, b values individually using bit shifting
    enum TileType : unsigned int {
        Start = (255 << 16) + 255,                                  // Green with 255 alpha
        Goal = (255 << 24) + 255,                                   // Red with 255 alpha
        Empty = (255 << 24) + (255 << 16) + (255 << 8) + 255,       // White with 255 alpha
        Obstacle = (127 << 24) + (127 << 16) + (127 << 8) + 255,    // Gray with 255 alpha
        Visited = (173 << 24) + (216 << 16) + (230 << 8) + 255,     // Light Blue with 255 alpha
        Explored = (255 << 8) + 255,                                // Blue with 255 alpha
        Path = (255 << 24) + (255 << 16) + 255                      // Yellow with 255 alpha
    };

    class Tile :
        public GameObject
    {
    protected:
        TileType type;
        sf::RectangleShape shape;
    public:
        Tile();
        Tile(const sf::Vector2f& position, TileType type = TileType::Empty);
        virtual void handleInput(sf::RenderWindow& window, const sf::Event& event);
        virtual void update(sf::RenderWindow& window) override;
        virtual void render(sf::RenderWindow& window) override;
        virtual void setPosition(const sf::Vector2f& position) override;
        virtual TileType getType() const;
        virtual bool intersect(const sf::Vector2i& point) const;
        void setType(TileType);
        ~Tile();
    };

}

#endif