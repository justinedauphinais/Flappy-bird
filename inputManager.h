#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class inputManager
{
public:
	bool isSpriteClicked(const Sprite& object, Mouse::Button button, RenderWindow& window);
	Vector2i getMousePosition(RenderWindow& window) const;
};