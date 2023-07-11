#include "mainMenuState.h"

/// <summary>
/// Le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
/// </summary>
/// <param name="data"></param>
mainMenuState::mainMenuState(gameDataRef data) : _data(data)
{
}

/// <summary>
/// Load les sprites à l’aide du assetManager ds _data et la set au Sprite
/// </summary>
void mainMenuState::init()
{
	// Background
	_data->assets.loadTexture("main menu background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.getTexture("main menu background"));

	// Play button
	_data->assets.loadTexture("main menu button", PLAY_BUTTON_FILEPATH);
	_playButton.setTexture(_data->assets.getTexture("main menu button"));

	_playButton.setPosition(((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2)), 
							((SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2)));

	// Title
	_data->assets.loadTexture("main menu title", GAME_TITLE_FILEPATH);
	_title.setTexture(_data->assets.getTexture("main menu title"));

	_title.setPosition(((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2)), 100);
}

/// <summary>
/// Fenêtre qui reste ouverte tant qu’elle n’est pas fermée
/// </summary>
void mainMenuState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();
		else if (_data->input.isSpriteClicked(_playButton, Mouse::Left, _data->window)) {
			// Create the new state main screen
			_data->machine.addState(stateRef(new gameState(_data)),true);
			cout << "go to main screen" << endl;
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void mainMenuState::update(float dt)
{
}

/// <summary>
/// Clear, dessine le background et display la fenêtre
/// </summary>
/// <param name="dt"></param>
void mainMenuState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_title);
	_data->window.draw(_playButton);
	_data->window.display();
}
