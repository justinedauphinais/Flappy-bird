#include "inputManager.h"

/// <summary>
/// Vérifie si on a cliqué sur le sprite de la fenêtre reçus en paramètre
/// </summary>
/// <param name="object"></param>
/// <param name="button"></param>
/// <param name="window"></param>
/// <returns></returns>
bool inputManager::isSpriteClicked(const Sprite& object, Mouse::Button button, RenderWindow& window)
{
	if (Mouse::isButtonPressed(button))
	{
		IntRect tempRect(object.getPosition().x, object.getPosition().y,
			object.getGlobalBounds().width, object.getGlobalBounds().height);
		if (tempRect.contains(Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}

/// <summary>
/// Retourne la position de la souris de la fenêtre reçue en paramètre
/// </summary>
/// <param name="window"></param>
/// <returns></returns>
Vector2i inputManager::getMousePosition(RenderWindow& window) const
{
	return Mouse::getPosition(window);
}