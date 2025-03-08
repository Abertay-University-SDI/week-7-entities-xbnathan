#include "Player.h"

Player::Player()
{
	setFillColor(sf::Color::Black);
	setSize(sf::Vector2f(100, 100));
	setPosition(600, 335);

	velocity = sf::Vector2f(150, 150);
	bulletManager = new BulletManager();
}

Player::~Player()
{
}

void Player::shoot()
{
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x = 100;
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x = -100;
	}
	if (input->isKeyDown(sf::Keyboard::W))
	{
		velocity.y = -100;
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		velocity.y = 100;
	}
	if (input->isKeyDown(sf::Keyboard::R))
	{
		velocity = sf::Vector2f(0,0);
		setPosition(600, 335);
	}
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		bulletManager->spawn(getPosition());
		input->setKeyUp(sf::Keyboard::Space);
	}
}

void Player::update(float dt)
{
	move(velocity.x * dt, velocity.y * dt);
	bulletManager->update(dt);
	bulletManager->deathCheck();
}

void Player::render(sf::RenderWindow* window)
{
	bulletManager->render(window);
	//window->draw(player);
}
