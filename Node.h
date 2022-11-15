#ifndef NODE_H
#define NODE_H

#include <string>
#include <SFML/Graphics.hpp>

namespace gm {
	class Node
	{
	public:
		int row;
		int column;
		std::string id;
		Node* path;

		Node(int row = 0, int column = 0);

		const std::string& getID() const;
		
		bool intersect(const sf::Vector2i& point) const;

		~Node();
	};
}

#endif