#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	player = new Player();
	player->setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player->handleInput(dt);
	if (input->isPressed(sf::Keyboard::Delete))
	{
		manager.spawn();
	}
	if (input->isPressed(sf::Keyboard::G))
	{
		manager2.spawn();
	}
	/*if (input->isLeftMousePressed())
	{
		bullets.spawn();
	}*/
}

// Update game objects
void Level::update(float dt)
{
	manager.update(dt);
	manager2.update(dt);
	player->update(dt);
	bullets.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	manager.render(window);
	manager2.render(window);
	window->draw(*player);
	player->render(window);
	bullets.render(window);

	endDraw();
}
