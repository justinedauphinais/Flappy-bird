#include "land.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
land::land(gameDataRef data) : _data(data)
{
	Sprite sprite1(_data->assets.getTexture("land"));
	Sprite sprite2(_data->assets.getTexture("land"));

	//positionne à 0 en x et en bas de l’écran en y
	sprite1.setPosition(0, _data->window.getSize().y - sprite1.getGlobalBounds().height);

	//positionne à la fin du premier land en x et en bas de l’écran en y
	sprite2.setPosition(sprite1.getGlobalBounds().width,
		_data->window.getSize().y - sprite1.getGlobalBounds().height);
	_landSprites.push_back(sprite1);
	_landSprites.push_back(sprite2);
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
vector<Sprite> land::getSprites() const
{
	return _landSprites;
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void land::moveLand(float dt)
{
	for (int i = 0; i < _landSprites.size(); i++)
	{
		float movement = PIPE_MOVEMENT_SPEED * dt;
		_landSprites.at(i).move(-movement, 0); //on se déplace vers la gauche -x
		if (_landSprites.at(i).getPosition().x < 0 - _landSprites.at(i).getGlobalBounds().width)
		{
			//repositionne à droite de l’écran
			Vector2f position(_data->window.getSize().x, _landSprites.at(i).getPosition().y);
			_landSprites.at(i).setPosition(position);
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void land::draw() const
{
	for (int i = 0; i < _landSprites.size(); i++)
		_data->window.draw(_landSprites[i]);
}
