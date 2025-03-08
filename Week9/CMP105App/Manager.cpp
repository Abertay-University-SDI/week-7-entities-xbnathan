#include "Manager.h"
Manager::Manager()
{
	gameFont.loadFromFile("font/arial.ttf");

	if (!gameFont.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error Loading File - Font";
	}

	numBalls.setFillColor(sf::Color::Black);
	numBalls.setFont(gameFont);
	numBalls.setPosition(200 - numBalls.getGlobalBounds().width, 0);

	spawnPoint = sf::Vector2f(rand() % 200 - 100, 0);

	texture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 40; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setOutlineColor(sf::Color::Yellow);
		balls[i].setOutlineThickness(10.f);
		balls[i].setFillColor(sf::Color::Cyan);
		//balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(50, 50));
	}
}
Manager::~Manager()
{
}

void Manager::update(float dt)
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
	spawnPoint = sf::Vector2f(rand() % 1200, 0);
	/*std::cout << spawnPoint.x << " , " << spawnPoint.y << std::endl;*/
}


// Spawn new ball
// Find a dead ball, make alive, move to spawn point, give random velocity
void Manager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(0, rand() % 175 + 25);
			balls[i].setPosition(spawnPoint);
			amount++;
			return;
		}

	}
	/*balls.push_back(Ball());
	balls[balls.size() - 1].setAlive(true);
	balls[balls.size() - 1].setTexture(&texture);
	balls[balls.size() - 1].setSize(sf::Vector2f(100, 100));
	balls[balls.size() - 1].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
	balls[balls.size() - 1].setPosition(spawnPoint);
	amount++;*/
}

void Manager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().y > 775)
			{
				balls[i].setAlive(false);
				amount--;
			}
		}
	}
}

// Render all alive balls
void Manager::render(sf::RenderWindow* window)
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
