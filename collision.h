#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

class collision
{
public:
	bool checkSpriteCollision(Sprite sprite1, Sprite sprite2)const;
	bool checkSpriteCollision(Sprite sprite1, float scale1, Sprite sprite2, float scale2) const;
};