#pragma once
#include "Ball.h"
#include <math.h>
#include <string.h>
#include <vector>
#include <iostream>
//#include "Player.h"


class BulletManager
{
public:
	BulletManager();
	~BulletManager();
	void spawn(sf::Vector2f spawnPosition);
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
private:
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	sf::Font gameFont;
	sf::Text numBalls;
	int amount;
};

