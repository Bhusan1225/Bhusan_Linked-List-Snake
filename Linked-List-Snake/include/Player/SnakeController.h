#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/SingleLinkedList.h"



namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};
	
	enum class InputState
	{
		WAITING,
		PROCESSING
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		LinkedList::SingleLinkedList* single_linked_list;
		const float movement_frame_duration = 0.1f;
		SnakeState current_snake_state;
		Direction current_snake_direction;
		float elapsed_duration;
		float restart_counter;
		const float restart_duration = 3.f;
		InputState current_input_state;
		void processPlayerInput();

		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void reset();
		void destroy();
		void createLinkedList();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		//std::vector<sf::Vector2i> getCurrentSnakePositionList();
		SnakeState getSnakeState();
		void delayedUpdate();
	};
}