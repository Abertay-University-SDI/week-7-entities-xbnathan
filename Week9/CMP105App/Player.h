#pragma once
#include "Framework/GameObject.h"
#include "BulletManager.h"
#include <iostream>

class Player : public GameObject
{
public:

	Player();
	~Player();
	void shoot();
	void handleInput(float dt) override;
	void update(float dt) override;
	void render(sf::RenderWindow* window);

private:

	BulletManager* bulletManager;
	sf::Vector2f velocity;
	sf::RectangleShape player;
};

