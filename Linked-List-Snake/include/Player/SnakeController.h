#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"
#include "LinkedList/SingleLinkedList.h"
#include "Food/FoodType.h"



namespace Player
{
	enum class TimeComplexity
	{
		NONE,
		ONE,
		N,
	};

	enum class LinkedListOperations
	{
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
	};
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
		int player_score;
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

		TimeComplexity time_complexity;
		LinkedListOperations last_linked_list_operation;

		void processPlayerInput();

		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void reset();
		void destroy();
		void createLinkedList();
		void OnFoodCollected(Food::FoodType food_type);
	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		SnakeState getSnakeState();
		void delayedUpdate();
		void processBodyCollision();
		void processElementsCollision();
		void processFoodCollision();
		
		//getter
		int getPlayerScore();
		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();
		
	};
}