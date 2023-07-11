#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <vector>
#include "game.h"

using namespace sf;

class land {
private:
	gameDataRef _data;
	vector<Sprite> _landSprites;

public:
	land(gameDataRef data);

	vector<Sprite> getSprites() const;

	void moveLand(float dt);

	void draw() const;
};