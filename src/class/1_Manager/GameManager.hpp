#ifndef GAMEMANAGER_HPP
# define GAMEMANAGER_HPP

# include <string>
# include "../3_Game_Classes/_World/World.hpp"
# include "../5_Render_Engine/RenderEngine.hpp"
# include "../6_PassInfo/PassInfo.hpp"

# include "../3_Game_Classes/Player/Player.hpp"

#include "../3_Game_Classes/Obsticles/ObsticleCollection.hpp"

class GameManager
{
	private:
		RenderEngine * renderEngine;
		World *world;
		int cellSize;
		int timeScale;
		int bonusFoodCnt;
		int bonusSpawnAmt;
		bool rainbowMode;

	public:
		GameManager();
		GameManager(std::string libsDir[], int width, int height);
		GameManager(const GameManager &obj);
		virtual ~GameManager();
		GameManager &operator=(const GameManager &other);
		static GameManager *instance;
		void SetupManagerForInstance(std::string libsDir[], int width, int height);

		RenderEngine *getRenderEngine();
		World *GetWorld();
		void passPlayer(KeyCode keycode);
		bool Collisions();
		int GetTimeScale();
		void IncrementTimeScale(int amt);
		void GeneralFood();
		void BonusFood();
		int randomRange(int min, int max);
		void EnableRainbowMode();
};

#endif