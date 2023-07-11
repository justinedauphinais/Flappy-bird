#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include "gameState.h"
#include <fstream>
#include <iostream>

using namespace sf;
using namespace std;
// Chaque state repr�sentera une vraie fen�tre et h�rite de state, car on impl�mentera
// un init, update, draw et handleInput diff�rent pour chaque fen�tre.
class gameOverState : public state
{
private:
	gameDataRef _data;		// Chaque state recevra le pointeur sur la gameData qui
	// donne acc�s au stateMachine, au RenderWindow, au
	// assertManager et au inputManager

	Sprite _background;		// Le sprite pour la background
	Sprite _gameOverTitle;
	Sprite _gameOverContainer;
	Sprite _retryButton;
	Sprite _medaille;

	Text _scoreText;
	Text _highScoreText;
	int _score;
	int _highScore;

public:
	gameOverState(gameDataRef data, int score);
	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt) const;
};