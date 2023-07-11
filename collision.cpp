#include "collision.h"

/// <summary>
/// Où le sprite 1 sera le bird et le sprite 2 soit un land ou un pipe
/// </summary>
/// <param name="sprite1"></param>
/// <param name="sprite2"></param>
/// <returns></returns>
bool collision::checkSpriteCollision(Sprite sprite1, Sprite sprite2) const
{
	Rect<float> rect1 = sprite1.getGlobalBounds();	// On crée un rectangle des
	Rect<float> rect2 = sprite2.getGlobalBounds();	// Dimensions des sprites reçus
	return rect1.intersects(rect2);					// True, ils entrent en contact, false sinon
}

/// <summary>
/// 
/// </summary>
/// <param name="sprite1"></param>
/// <param name="scale1"></param>
/// <param name="sprite2"></param>
/// <param name="scale2"></param>
/// <returns></returns>
bool collision::checkSpriteCollision(Sprite sprite1, float scale1, Sprite sprite2, float scale2) const
{
	sprite1.setScale(scale1, scale1);
	sprite2.setScale(scale2, scale2);
	Rect<float> rect1 = sprite1.getGlobalBounds();
	Rect<float> rect2 = sprite2.getGlobalBounds();
	return rect1.intersects(rect2);
}