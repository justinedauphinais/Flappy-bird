#pragma once

class state
{
public:
	virtual void init() = 0;					// Init de state
	virtual void handleInput() = 0;				// Tous les input de la fenêtre
	virtual void update(float delta) = 0;		// Update la fenêtre après le input
	virtual void draw(float delta)const = 0;	// Draw la fenêtre après le update (delta est
												// la différence de temps avec le frame rate)
	virtual void pause() {}						// Pause et resume le state
	virtual void resume() {}
};