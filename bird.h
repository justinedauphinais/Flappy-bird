#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

class bird
{
private:
	gameDataRef _data;

	Sprite _birdSprite;		// On n’a qu’un Sprite qui sera modifié selon l’animation

	vector<Texture> _animationFrames;
	int _animationIterator;

	Clock _clock;

	Clock _mouvementClock;	// Une autre clock pour le temps de mouvement
	int _birdState;			// Le bird state
	float _rotation;

public:
	bird(gameDataRef data);

	Sprite getSprite() const;

	void animate(float dt);
	void update(float dt);

	void tap();

	void draw()const;
};