#pragma once
#include "Level/LevelNumber.h"

namespace Level
{
	class LevelController;
	class LevelService
	{

        LevelController* level_controller;

        LevelNumber current_level;

        void createLevelController();
        void destroy();

    public:
        LevelService();
        ~LevelService();

        void initialize();
        void update();
        void render();
        void spawnPlayer();
        void createLevel(LevelNumber level_to_load);

        float getCellWidth();

        float getCellHeight();

	};

}
