/********************************************************************************************
* Auteur	: Justine Dauphinais															*
* Nom		: assetManager.cpp																*
* Date		: 02/12/2022																	*
* Description : Maps de textures et de fonts												*
*********************************************************************************************/

#pragma once

#include <map>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class assetManager
{
private:
	map<string, Texture> _textures;		// Combine le nom de la texture à la Texture sfml
	map<string, Font> _fonts;			// Combine le nom de la font à la Font sfml

public:
	void loadTexture(string name, string fileName);
	Texture& getTexture(string name);	// Pas de const pour ce getteur, car setteur aussi
	void loadFont(string name, string fileName);
	Font& getFont(string name);			// Pas de const pour ce getteur, car setteur aussi
};