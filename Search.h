//
//  Search.hpp
//  
//
//  Created by Ian Richardson on 11/8/22.
//

#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <unordered_map>
#include "Grid.h"
#include "Node.h"

namespace gm {
    class Search
    {
    protected:
        Grid* grid;
        std::unordered_map<std::string, Node*> closedList;
    public:
        Search(Grid* grid);
        virtual Node* search(); // run whatever search we're running and return successors
        virtual Node* explore(Node* node);
        virtual Node* generateSuccessor(Node* parent, int row, int column); // assumption we are using a grid
        virtual bool inFrontier(int row, int column) const = 0;
        virtual bool isFrontierEmpty() const = 0;
        virtual void addNodeToFrontier(Node* node) = 0;
        virtual Node* getNextFrontier() = 0;    // managed by derived class
        virtual void addNodeToClosed(Node* node);
        bool inClosed(int row, int column) const;
        virtual ~Search(); // we know we are using inheritance
    };
}

#endif /* Search_h */
