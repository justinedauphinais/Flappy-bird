#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include "pipe.h"
#include "land.h"
#include "bird.h"
#include "flash.h"
#include "hud.h"
#include "gameOverState.h"
#include "collision.h"
#include <iostream>

using namespace sf;
using namespace std;

// Chaque state représentera une vraie fenêtre et hérite de state, car on implémentera
// un init, update, draw et handleInput différent pour chaque fenêtre.
class gameState : public state
{
private:
	gameDataRef _data;		// Chaque state recevra le pointeur sur la gameData qui
							// donne accès au stateMachine, au RenderWindow, au
							// assertManager et au inputManager
	gameStates _gameState;

	collision _collision;	// Collision

	Clock _clock;

	Sprite _background;		// Le sprite pour la background
	pipe* _pipe;			// Un pointeur de pipe
	land* _land;			// Un pointeur de land
	bird* _bird;			// Un pointeur de bird
	flash* _flash;			// Un pointeur sur le flash
	hud* _hud;				// Un pointeur sur le hud
	
	int _score;

	SoundBuffer _hitSoundBuffer;
	SoundBuffer _pointSoundBuffer;
	SoundBuffer _wingSoundBuffer;

	Sound _hitSound;
	Sound _pointSound;
	Sound _wingSound;

public:
	gameState(gameDataRef data);
	~gameState();

	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt) const;
};