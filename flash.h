#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

class flash
{
private:
	gameDataRef _data;
	RectangleShape _shape;
	bool _flashOn;
public:
	flash(gameDataRef data);
	void show(float dt);
	void draw();
};