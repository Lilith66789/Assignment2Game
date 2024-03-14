#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, World* w)
{
	window = hwnd;
	input = in;
	gameState = gs;
	world = w;
	// initialise game objects
	p1.setPosition(100, 100);
	p1.setInput(input);

	e1.setPosition(500, 100);
	world->AddGameObject(p1);
	world->AddGameObject(e1);
	world->AddGameObject(ground);

	tileManager.setInput(input);
	tileManager.setWindow(window);
	tileManager.setWorld(world);

	if (!tileManager.loadTiles())
	{
		std::cout << "Tiles not found\n";
	}
	else
	{
		std::cout << "Tiles loaded\n";
	}

	//Background
	backgroundTex[0].loadFromFile("Assets/TileSets/1 Backgrounds/1/Day/1.png");
	backgroundTex[1].loadFromFile("Assets/TileSets/1 Backgrounds/1/Day/2.png");
	backgroundTex[2].loadFromFile("Assets/TileSets/1 Backgrounds/1/Day/3.png");
	backgroundTex[3].loadFromFile("Assets/TileSets/1 Backgrounds/1/Day/5.png");

	for (size_t i = 0; i < 4; i++)
	{
		bg[i].setTexture(&backgroundTex[i]);
		bg[i].setSize(sf::Vector2f(1920, 1080));
		bg[i].setPosition(sf::Vector2f(0, 0));
		bg[i].setInput(input);
		bg[i].setWindow(window);
	}

	for (size_t i = 0; i < 4; i++)
	{
		bg1[i].setTexture(&backgroundTex[i]);
		bg1[i].setSize(sf::Vector2f(1920, 1080));
		bg1[i].setPosition(sf::Vector2f(1920, 0));
		bg1[i].setInput(input);
		bg1[i].setWindow(window);
	}
	for (size_t i = 0; i < 4; i++)
	{
		bg2[i].setTexture(&backgroundTex[i]);
		bg2[i].setSize(sf::Vector2f(1920, 1080));
		bg2[i].setPosition(sf::Vector2f(3840, 0));
		bg2[i].setInput(input);
		bg2[i].setWindow(window);
	}
	for (size_t i = 0; i < 4; i++)
	{
		bg3[i].setTexture(&backgroundTex[i]);
		bg3[i].setSize(sf::Vector2f(1920, 1080));
		bg3[i].setPosition(sf::Vector2f(5760, 0));
		bg3[i].setInput(input);
		bg3[i].setWindow(window);
	}

	window->setView(view);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}
	p1.handleInput(dt);

	tileManager.handleInput(dt);
	for (int i = 0; i < 4; i++)
	{
		bg[i].handleInput(dt);
		bg1[i].handleInput(dt);
		bg2[i].handleInput(dt);
		bg3[i].handleInput(dt);
	}
}

// Update game objects
void Level::update(float dt)
{
	if(p1.CollisionWithTag("Enemy"))
	{ 
		
	}

	tileManager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	for (int i = 0; i < 4; i++)
	{
		window->draw(bg[i]);
		window->draw(bg1[i]);
		window->draw(bg2[i]);
		window->draw(bg3[i]);

	}
	window->draw(p1);
	window->draw(p1.getDebugCollisionBox());


	window->draw(e1);
	window->draw(e1.getDebugCollisionBox());


	window->draw(ground.getDebugCollisionBox());


	tileManager.render();
	endDraw();
}
