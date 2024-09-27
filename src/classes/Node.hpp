#ifndef NODE_HPP
#define NODE_HPP

#include "math/vector/Vector2.hpp"

namespace gengine {
    class Node {
        private:
            float x, y;
            float w, h;
        
        public:
            Node();
            Node(double x, double y);
            Node(double x, double y, double w, double h);
            Node(Vector2 pos);
            Node(Vector2 pos, Vector2 size);

            Vector2 getPosition();
            Vector2 getScale();
    };
}

#endif // NODE_HPP