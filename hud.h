#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

class hud
{
private:
	gameDataRef _data;
	Text _scoreText;
public:
	hud(gameDataRef data);
	void updateScore(int score);
	void draw()const;
};