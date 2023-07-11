/********************************************************************************************
* Auteur	: Justine Dauphinais															*
* Nom		: assetManager.cpp																*
* Date		: 02/12/2022																	*
*********************************************************************************************/

#include "assetManager.h"

/// <summary>
/// Load la texture et la met dans la map
/// </summary>
/// <param name="name"></param>
/// <param name="fileName"></param>
void assetManager::loadTexture(string name, string fileName)
{
	Texture tex;
	if (tex.loadFromFile(fileName)) {
		_textures[name] = tex;
	}
}

/// <summary>
/// Retourne la texture de la map correspondant au nom reçu
/// </summary>
/// <param name="name"></param>
/// <returns></returns>
Texture& assetManager::getTexture(string name)
{
	return _textures.at(name);
}

/// <summary>
/// 
/// </summary>
/// <param name="name"></param>
/// <param name="fileName"></param>
void assetManager::loadFont(string name, string fileName)
{
	Font font;
	if (font.loadFromFile(fileName)) {
		_fonts[name] = font;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="name"></param>
/// <returns></returns>
Font& assetManager::getFont(string name)
{
	return _fonts[name];
}