#pragma once
#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Player/SnakeController.h"

namespace Player
{
	class SnakeController;

	class PlayerService
	{
	private:
		SnakeController* snake_controller;

		void createController();
		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();
		//int getSnakeSize();
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		void spawnPlayer();
	};
}


