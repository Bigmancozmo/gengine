#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../classes/math/vector/Vector2.hpp"
#include "../classes/data/Color.hpp"
#include "../classes/Logger.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace gengine {
    class Window {
        private:
            GLFWwindow* window;
            Logger* logger;
            void createWinHelper(std::string title, int width, int height);
    
        public:
            Window(std::string title);
            Window(std::string title, Vector2 size);
            Window(Vector2 size);

            bool shouldClose();
            void update();

            Vector2 getPosition();
            Vector2 getScale();

            GLFWwindow* get();

            void setBackgroundColor(Color col);

            ~Window();
    };
}

#endif // WINDOW_HPP