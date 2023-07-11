#include "hud.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
hud::hud(gameDataRef data) :_data(data)
{
	_scoreText.setFont(_data->assets.getFont("flappy font"));
	_scoreText.setString("0");
	_scoreText.setCharacterSize(128);
	_scoreText.setFillColor(Color::White);
	_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, 
						 _scoreText.getGlobalBounds().height / 2);

	// L’image du texte sera centré sur l’écran grâce au point d’origine au milieu de l’image
	_scoreText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 5);
}

/// <summary>
/// 
/// </summary>
/// <param name="score"></param>
void hud::updateScore(int score)
{
	_scoreText.setString(to_string(score));
}

/// <summary>
/// 
/// </summary>
void hud::draw() const
{
	_data->window.draw(_scoreText);
}