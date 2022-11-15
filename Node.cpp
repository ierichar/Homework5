#include "Node.h"

using namespace gm;
using namespace sf;
using namespace std;

Node::Node(int row, int column) : row(row), column(column), id(to_string(row) + "|" + to_string(column)), path(nullptr) {

}

const string& Node::getID() const {
	return id;
}

bool Node::intersect(const Vector2i& point) const {
	return point.x == column && point.y == row;
}


Node::~Node() {

}
