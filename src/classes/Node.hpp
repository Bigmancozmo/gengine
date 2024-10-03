#ifndef NODE_HPP
#define NODE_HPP

#include "math/vector/Vector2.hpp"

namespace gengine {
    class Node {
        private:
            float x, y;
            float w, h;
        
        public:
            Node() : x(0), y(0), w(0), h(0) {};
            Node(double x, double y) : x(x), y(y), w(0), h(0) {};
            Node(double x, double y, double w, double h) : x(x), y(y), w(w), h(h) {};
            Node(Vector2 pos) : x(pos.x), y(pos.y), w(0), h(0) {};
            Node(Vector2 pos, Vector2 size) : x(pos.x), y(pos.y), w(size.x), h(size.y) {};

            Vector2 getPosition();
            Vector2 getScale();
    };
}

#endif // NODE_HPP