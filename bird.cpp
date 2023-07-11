#include "bird.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
bird::bird(gameDataRef data) : _data(data)
{
	_animationFrames.push_back(_data->assets.getTexture("bird frame1"));
	_animationFrames.push_back(_data->assets.getTexture("bird frame2"));
	_animationFrames.push_back(_data->assets.getTexture("bird frame3"));
	_animationFrames.push_back(_data->assets.getTexture("bird frame4"));

	_animationIterator = 0;
	_birdState = BIRD_STATE_STILL;

	_birdSprite.setTexture(_animationFrames.at(_animationIterator));

	_birdSprite.setPosition((_data->window.getSize().x / 4) - _birdSprite.getGlobalBounds().width / 2,
							(_data->window.getSize().y / 2) - _birdSprite.getGlobalBounds().height / 2);

	_rotation = 0;
	_birdSprite.setOrigin(Vector2f(_birdSprite.getGlobalBounds().width / 2,
								   _birdSprite.getGlobalBounds().height / 2));
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
Sprite bird::getSprite() const
{
	return _birdSprite;
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void bird::animate(float dt)
{
	//si on veut que l’animation dure .4 seconde et qu’on a 4 images, chaque image
	//durera .1 seconde. D’où la division par la taille du vecteur de frame
	if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
	{
		_animationIterator++;
		if (_animationIterator >= _animationFrames.size()) //après 4 images, on revient à 0
			_animationIterator = 0;
		_birdSprite.setTexture(_animationFrames.at(_animationIterator));
		_clock.restart();
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void bird::update(float dt)
{
	if (_birdState == BIRD_STATE_FALLING)		// Si on tombe, on move le sprite
	{											// par en bas à l’aide de la gravité
		_birdSprite.move(0, GRAVITY * dt);

		_rotation += ROTATION_SPEED * dt;		// Modifie la rotation avec le dt reçu
		if (_rotation > 25.0f)					// sans le laisser dépasser l’angle 25 degré
			_rotation = 25.0f;
		_birdSprite.setRotation(_rotation);		// Applique la rotation au sprite du bird
	}
	else if (_birdState == BIRD_STATE_FLYING)	// Si on vole, on move le sprite
	{											// par en haut à l’aide du flying speed
		_birdSprite.move(0, -FLYING_SPEED * dt);

		_rotation -= ROTATION_SPEED * dt;		// Modifie la rotation avec le dt reçu
		if (_rotation < -25.0f)					// sans le laisser dépasser l’angle 25 degré
			_rotation = -25.0f;
		_birdSprite.setRotation(_rotation);		// Applique la rotation au spr
	}
	
	// À l’aide de la 2e clock, on change le state du bird après le temps de vol à fall
	if (_mouvementClock.getElapsedTime().asSeconds() > FLYING_DURATION) {
		_birdState = BIRD_STATE_FALLING;
		_mouvementClock.restart();
	}
}

/// <summary>
/// 
/// </summary>
void bird::tap()
{
	_mouvementClock.restart(); //si on click, on call tap qui reset la clock
	_birdState = BIRD_STATE_FLYING; //et met le state à FLYING
}

/// <summary>
/// 
/// </summary>
void bird::draw() const
{
	_data->window.draw(_birdSprite);
}