#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <list>
#include "game.h"

using namespace sf;

class pipe
{
private:
	gameDataRef _data;

	list<Sprite> _pipeSprites;
	list<Sprite> _scoringPipes;		// Position des pipes invisibles


	int _pipeSpawnYOffset;

public:
	pipe(gameDataRef data);

	list<Sprite> getSprites() const;
	list<Sprite>& getScoringSprites();

	void spawnTopPipe();
	void spawnBottomPipe();
	void spawnScoringPipe();

	void randomisePipeOffset();
	void movePipes(float dt);

	void draw();
};