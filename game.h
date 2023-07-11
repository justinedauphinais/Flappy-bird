#pragma once

#include <string>
#include <memory>
#include "stateMachine.h"
#include "assetManager.h"
#include "inputManager.h"
#include <SFML/Graphics.hpp>

using namespace sf;

struct gameData {
	stateMachine machine;
	RenderWindow window;
	assetManager assets;
	inputManager input;
};

typedef shared_ptr<gameData> gameDataRef;
class game
{
private:
	const float dt = 1.0f / 60.0f;		// Temps pour chaque frame (60 frames par sec.)
	Clock _clock;
	gameDataRef _data;					// Le pointeur sur la struct gameData

public:
	game(int width, int height, string title);
	void run();
};