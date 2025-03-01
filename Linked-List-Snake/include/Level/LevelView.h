#pragma once
#include <SFML/Graphics.hpp>
#include "UI/UIElement/RectangleShapeView.h"

namespace Level
{
	
	class LevelView
	{
	private:
		float grid_width;
		float grid_height;

		const sf::Color background_color = sf::Color(180, 200, 160);
		UI::UIElement::RectangleShapeView* background_rectangle;
		UI::UIElement::RectangleShapeView* border_rectangle;
		sf::Color border_color = sf::Color::Black;
	public:
		static const int border_thickness = 10;
		static const int border_offset_left = 40;
		static const int border_offset_top = 40;


	public:
		LevelView();

		void initialize();
		void initializeBackground();

		float getGridWidth();
		float getGridHeight();
		void calculateGridExtents();

	};


}