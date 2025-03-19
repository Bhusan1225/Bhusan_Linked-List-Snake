#pragma once
#include <SFML/System/Vector2.hpp>
#include "Food/FoodType.h" // I added due to getting error in the food type in .cpp file 
#include <random>

#include <vector>

namespace Food
{
	//enum class FoodType; // earlier it was the forward declaration 
	class FoodItem;

	class FoodService
	{
	private:
		FoodItem* current_food_item;

		float cell_width;
		float cell_height;

		FoodItem* createFood(sf::Vector2i position, FoodType type);
		void spawnFood();
		sf::Vector2i getRandomPosition();
		void destroyFood();
		std::default_random_engine random_engine;
		std::random_device random_device;
		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		
	public:
		FoodService();
		~FoodService();
		
		void initialize();
		void update();
		void render();
		sf::Vector2i getValidSpawnPosition();
		FoodType getRandomFoodType();
		
		void startFoodSpawning();
	};
}
