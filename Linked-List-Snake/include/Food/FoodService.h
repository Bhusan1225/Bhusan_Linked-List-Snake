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

		void destroyFood();

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
	};
}
