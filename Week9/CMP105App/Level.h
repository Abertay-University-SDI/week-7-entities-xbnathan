#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "BeachBallManager.h"
#include "Manager.h"
#include "Player.h"
#include "BulletManager.h"


class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();


private:
	// Default variables for level class.
	BeachBallManager manager;
	Manager manager2;
	
	Player* player;
	BulletManager bullets;
};