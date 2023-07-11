#include "pipe.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
pipe::pipe(gameDataRef data) : _data(data)
{}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
list<Sprite> pipe::getSprites() const
{
	return _pipeSprites;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
list<Sprite>& pipe::getScoringSprites()
{
	return _scoringPipes;
}

/// <summary>
/// 
/// </summary>
void pipe::spawnTopPipe()
{
	Sprite sprite(_data->assets.getTexture("pipe up"));
	sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset);
	_pipeSprites.push_back(sprite);
}

/// <summary>
/// 
/// </summary>
void pipe::spawnBottomPipe()
{
	Sprite sprite(_data->assets.getTexture("pipe bottom"));
	sprite.setPosition(_data->window.getSize().x, 0 - _pipeSpawnYOffset);
	_pipeSprites.push_back(sprite);
}

/// <summary>
/// 
/// </summary>
void pipe::spawnScoringPipe()
{
	Sprite sprite(_data->assets.getTexture("scoring pipe"));
	sprite.setPosition(_data->window.getSize().x, 0);
	_scoringPipes.push_back(sprite);
}

/// <summary>
/// 
/// </summary>
void pipe::randomisePipeOffset()
{
	_pipeSpawnYOffset = rand() % (MAX_PIPE_HEIGHT + 1);
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void pipe::movePipes(float dt)
{
	list<Sprite>::iterator it = _pipeSprites.begin();

	while (it != _pipeSprites.end()) {
		// Si la position des pipes sont inférieurs à 0, on soustrait la largeur d’un pipe
		if (it->getPosition().x < 0 - it->getGlobalBounds().width) {
			it = _pipeSprites.erase(it);
		}
		else {
			float movement = PIPE_MOVEMENT_SPEED * dt;
			it->move(-movement, 0);			// On se déplace vers la gauche -x
			it++;
		}
	}

	list<Sprite>::iterator itScore = _scoringPipes.begin();

	while (itScore != _scoringPipes.end()) {
		// Si la position des pipes sont inférieurs à 0, on soustrait la largeur d’un pipe
		if (itScore->getPosition().x < 0 - itScore->getGlobalBounds().width) {
			itScore = _scoringPipes.erase(itScore);
		}
		else {
			float movement = PIPE_MOVEMENT_SPEED * dt;
			itScore->move(-movement, 0);			// On se déplace vers la gauche -x
			itScore++;
		}
	}
}

/// <summary>
/// 
/// </summary>
void pipe::draw()
{
	for (list<Sprite>::iterator it = _pipeSprites.begin(); it != _pipeSprites.end(); it++)
		_data->window.draw(*it);
}