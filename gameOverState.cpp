#include "gameOverState.h"

/// <summary>
/// Le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
/// </summary>
/// <param name="data"></param>
gameOverState::gameOverState(gameDataRef data, int score) : _data(data), _score(score)
{
}

/// <summary>
/// Load les sprites à l’aide du assetManager ds _data et la set au Sprite
/// </summary>
void gameOverState::init()
{
	float centerWindowX = _data->window.getSize().x / 2;
	float centerWindowY = _data->window.getSize().y / 2;

	// Background
	_data->assets.loadTexture("game over background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.getTexture("game over background"));

	// Container
	_data->assets.loadTexture("game over body", GAME_OVER_BODY_FILEPATH);
	_gameOverContainer.setTexture(_data->assets.getTexture("game over body"));
	_gameOverContainer.setPosition(centerWindowX - _gameOverContainer.getGlobalBounds().width / 2,
								   centerWindowY - _gameOverContainer.getGlobalBounds().height / 2);

	// Titre
	_data->assets.loadTexture("game over title", GAME_OVER_TITLE_FILEPATH);
	_gameOverTitle.setTexture(_data->assets.getTexture("game over title"));
	_gameOverTitle.setPosition(centerWindowX - _gameOverTitle.getGlobalBounds().width / 2,
							   centerWindowY - _gameOverContainer.getGlobalBounds().height * 1.2);

	// Retry button
	_retryButton.setTexture(_data->assets.getTexture("main menu button"));
	_retryButton.setPosition(centerWindowX - _retryButton.getGlobalBounds().width / 2,
							 _gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height +
							 _retryButton.getGlobalBounds().height * 0.2);

	// Score text
	_scoreText.setFont(_data->assets.getFont("flappy font"));
	_scoreText.setString(to_string(_score));
	_scoreText.setCharacterSize(56);
	_scoreText.setFillColor(Color::White);
	_scoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 2.15);
	_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2,
						 _scoreText.getGlobalBounds().height / 2);

	// High score text
	ifstream myfile;
	myfile.open("Resources/highScore.txt");
	myfile >> _highScore;
	myfile.close();

	if (_score > _highScore) {
		ofstream myfile;
		myfile.open("Resources/highScore.txt");
		myfile << _score;
		_highScore = _score;
		myfile.close();
	}

	// Medaille
	if (_score < SILVER_MEDAL_SCORE) {
		_data->assets.loadTexture("medaille bronze", BRONZE_MEDAL_FILEPATH);
		_medaille.setTexture(_data->assets.getTexture("medaille bronze"));
	}
	else if (_score < GOLD_MEDAL_SCORE) {
		_data->assets.loadTexture("medaille argent", SILVER_MEDAL_FILEPATH);
		_medaille.setTexture(_data->assets.getTexture("medaille argent"));
	}
	else if (_score < PLATINUM_MEDAL_SCORE) {
		_data->assets.loadTexture("medaille or", GOLD_MEDAL_FILEPATH);
		_medaille.setTexture(_data->assets.getTexture("medaille or"));
	}
	else {
		_data->assets.loadTexture("medaille platinum", PLATINUM_MEDAL_FILEPATH);
		_medaille.setTexture(_data->assets.getTexture("medaille platinum"));
	}

	_medaille.setPosition(175, 465);

	_highScoreText.setFont(_data->assets.getFont("flappy font"));
	_highScoreText.setString(to_string(_highScore));
	_highScoreText.setCharacterSize(56);
	_highScoreText.setFillColor(Color::White);
	_highScoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 1.78);
	_highScoreText.setOrigin(_scoreText.getGlobalBounds().width / 2,
							 _scoreText.getGlobalBounds().height / 2);
}

/// <summary>
/// Fenêtre qui reste ouverte tant qu’elle n’est pas fermée
/// </summary>
void gameOverState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();
		else if (_data->input.isSpriteClicked(_retryButton, Mouse::Left, _data->window))
			_data->machine.addState(stateRef(new gameState(_data)), true);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void gameOverState::update(float dt)
{
}

/// <summary>
/// Clear, dessine le background et display la fenêtre
/// </summary>
/// <param name="dt"></param>
void gameOverState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_gameOverContainer);
	_data->window.draw(_gameOverTitle);
	_data->window.draw(_retryButton);
	_data->window.draw(_scoreText);
	_data->window.draw(_highScoreText);
	_data->window.draw(_medaille);
	_data->window.display();
}
