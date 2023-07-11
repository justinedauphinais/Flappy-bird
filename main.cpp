/********************************************************************************************
* Auteur	: Justine Dauphinais															*
* Nom		: main.cpp																		*
* Date		: 02/12/2022																	*
*********************************************************************************************/

#include "game.h"

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

int main()
{
	game flappy(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
	return EXIT_SUCCESS;
}