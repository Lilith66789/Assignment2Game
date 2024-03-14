#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameState.h"
#include "Framework/World.h"
#include "Framework/TileManager.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Ground.h"
#include "Background.h"

class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, World* w);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	// Default variables for level class.
	Player p1;
	Enemy e1;

	Ground ground;
	
	TileManager tileManager;

	//Background stuff
	Background bg[4];
	Background bg1[4];
	Background bg2[4];
	Background bg3[4];

	sf::Texture backgroundTex[4];



	sf::View view;

};