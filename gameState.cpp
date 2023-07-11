#include "gameState.h"

/// <summary>
/// Le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
/// </summary>
/// <param name="data"></param>
gameState::gameState(gameDataRef data) : _data(data)
{
	_pipe = nullptr;
	_land = nullptr;
	_bird = nullptr;
	_flash = nullptr;
	_hud = nullptr;

	_gameState = gameStates::ready;
}

/// <summary>
/// 
/// </summary>
gameState::~gameState()
{
	delete _pipe;
	delete _land;
	delete _bird;
	delete _flash;
	delete _hud;
}

/// <summary>
/// Load les sprites à l’aide du assetManager ds _data et la set au Sprite
/// </summary>
void gameState::init()
{
	// Background
	_data->assets.loadTexture("game background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.getTexture("game background"));

	// Pipe
	_data->assets.loadTexture("pipe up", PIPE_UP_FILEPATH);
	_data->assets.loadTexture("pipe bottom", PIPE_DOWN_FILEPATH);

	// Land
	_data->assets.loadTexture("land", LAND_FILEPATH);

	// Bird
	_data->assets.loadTexture("bird frame1", BIRD_FRAME_1_FILEPATH);
	_data->assets.loadTexture("bird frame2", BIRD_FRAME_2_FILEPATH);
	_data->assets.loadTexture("bird frame3", BIRD_FRAME_3_FILEPATH);
	_data->assets.loadTexture("bird frame4", BIRD_FRAME_4_FILEPATH);

	// Font
	_data->assets.loadTexture("scoring pipe", SCORING_PIPE_FILEPATH);
	_data->assets.loadFont("flappy font", FLAPPY_FONT_FILEPATH);

	// Sons
	if (!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH)) {
		cout << "erreur loading sound effect" << endl;
	}
	if (!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH)) {
		cout << "erreur loading sound effect" << endl;
	}
	if (!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH)) {
		cout << "erreur loading sound effect" << endl;
	}
	_hitSound.setBuffer(_hitSoundBuffer);
	_pointSound.setBuffer(_pointSoundBuffer);
	_wingSound.setBuffer(_wingSoundBuffer);

	// Pointeurs
	_pipe = new pipe(_data);
	_land = new land(_data);
	_bird = new bird(_data);
	_flash = new flash(_data);
	_hud = new hud(_data);
}

/// <summary>
/// Fenêtre qui reste ouverte tant qu’elle n’est pas fermée
/// </summary>
void gameState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();
		else if (_data->input.isSpriteClicked(_background, Mouse::Left, _data->window)) {
			// Si ce n’est pas gameOver, on devient playing
			if (_gameState != gameStates::gameOver) {
				_gameState = gameStates::playing;
				_bird->tap();
				_wingSound.play();
			}
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void gameState::update(float dt)
{
	// Si ce n’est pas gameOver, on bouge le bird et le land
	if (_gameState != gameStates::gameOver) {
		_bird->animate(dt);
		_land->moveLand(dt);
	}

	// Si c’est playing, on a cliqué, donc on joue. Ajoute movePipe, la clock
	// pour la création des pipes et l’update du bird. Ensuite viennent les collisions
	if (_gameState == gameStates::playing) {
		_pipe->movePipes(dt);
		if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
			_pipe->randomisePipeOffset();
			_pipe->spawnBottomPipe();
			_pipe->spawnTopPipe();
			_pipe->spawnScoringPipe();
			_clock.restart();
		}
		_bird->update(dt);

		// Après le mouvement du bird, on check les collisions avec les lands
		for (int i = 0; i < _land->getSprites().size(); i++)
			if (_collision.checkSpriteCollision(_bird->getSprite(), 0.625f, _land->getSprites().at(i), 1.0f)) {
				_gameState = gameStates::gameOver;
				_hitSound.play();
				_clock.restart();
			}

		list<Sprite> lst = _pipe->getSprites();

		// On check les collisions avec les pipes
		for (list<Sprite>::iterator it = lst.begin(); it != lst.end(); it++)
			if (_collision.checkSpriteCollision(_bird->getSprite(), 0.625f, *it, 1.0f)) {
				_gameState = gameStates::gameOver;
				_hitSound.play();
				_clock.restart();
			}

		// Collisions avec les scorings pipes pour compter les points
		list<Sprite>::iterator it = _pipe->getScoringSprites().begin();
		while (it != _pipe->getScoringSprites().end()) {
			if (_collision.checkSpriteCollision(_bird->getSprite(), 0.625f, *it, 1.0f)) {
				_score++;
				_hud->updateScore(_score);
				it = _pipe->getScoringSprites().erase(it);
				_pointSound.play();
			}
			else
				it++;
		}
	}

	if (_gameState == gameStates::gameOver) {
		_flash->show(dt);

		if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS) {
			_data->machine.addState(stateRef(new gameOverState(_data, _score)), true);
		}
	}
}

/// <summary>
/// Clear, dessine le background et display la fenêtre
/// </summary>
/// <param name="dt"></param>
void gameState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_pipe->draw();
	_land->draw();
	_bird->draw();
	_flash->draw();
	_hud->draw();
	_data->window.display();
}
