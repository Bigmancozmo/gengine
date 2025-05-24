#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../classes/math/vector/Vector2.hpp"
#include "../classes/data/Color.hpp"
#include "../classes/Logger.hpp"
#include "../dll.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace gengine {
    /// @brief Simple wrapper for GLFWwindow
    class GENGINE_API Window {
        private:
            /// @brief The class's GLFWwindow*
            GLFWwindow* window;

            /// @brief Logger for debugging and output
            Logger* logger;

            /// @brief Window creation function called by constructors
            /// @details When used by constructors, unprovided values are just defaults.
            /// @param title The starting title of the window
            /// @param width The starting width in pixels of the window
            /// @param height The starting height in pixels of the window
            void createWinHelper(std::string title, int width, int height);
    
        public:
            /// @brief Create a Window from a title
            /// @param title The title of the window
            Window(std::string title);
            
            /// @brief Create a Window from a title and size
            /// @param title The title of the window
            /// @param size The size of the window
            Window(std::string title, Vector2 size);

            /// @brief Create a Window from just a size
            /// @param size The size of the window
            Window(Vector2 size);

            /// @brief Wrapper for glfwWindowShouldClose
            /// @return If this window should close
            bool shouldClose();

            /// @brief Called every frame to do necessary updates
            void update();

            /// @brief Get the position of the window
            /// @return The position of the window in pixels
            Vector2 getPosition();

            /// @brief Get the size of the window
            /// @return The size of the window in pixels
            Vector2 getScale();

            /// @brief Get the window's GLFWwindow
            /// @return The window's private GLFWwindow
            GLFWwindow* get();

            /// @brief Set the background color of the window
            /// @param col The Color to set the background to
            void setBackgroundColor(Color col);

            /// @brief Set the background color of the window
            /// @param col The ColorRGB to set the background to
            void setBackgroundColor(ColorRGB col);

            /// @brief Destroy and clean up the window
            ~Window();
        public:
            void polygonMode(GLenum face, GLenum mode) { glPolygonMode(face, mode); };
            void enable(GLenum cap) { glEnable(cap); };
    };
}

#endif // WINDOW_HPP