#include "BulletManager.h"

BulletManager::BulletManager()
{
	gameFont.loadFromFile("font/arial.ttf");

	if (!gameFont.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error Loading File - Font";
	}

	numBalls.setFillColor(sf::Color::Black);
	numBalls.setFont(gameFont);
	numBalls.setPosition(900 - numBalls.getGlobalBounds().width, 0);

	//std::cout << player.getPosition().x << " , " << player.getPosition().y << std::endl;
	spawnPoint = sf::Vector2f(0,0);
	texture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 20; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(30, 30));
	}
}
BulletManager::~BulletManager()
{
}

void BulletManager::update(float dt)
{
	// call update on all ALIVE balls
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}
	deathCheck();
	numBalls.setString(std::to_string(amount));
}


// Spawn new ball
// Find a dead ball, make alive, move to spawn point, give random velocity
void BulletManager::spawn(sf::Vector2f spawnPosition)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(100, 0);
			balls[i].setPosition(spawnPosition);
			amount++;
			return;
		}

	}
}

void BulletManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().x > 1125)
			{
				balls[i].setAlive(false);
				amount--;
			}
		}
	}
}

// Render all alive balls
void BulletManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
			window->draw(numBalls);
		}
	}
}
