#ifndef GAMEMANAGER_HPP
# define GAMEMANAGER_HPP

# include <string>
# include "../3_Game_Classes/_World/World.hpp"
# include "../5_Render_Engine/RenderEngine.hpp"
# include "../6_PassInfo/PassInfo.hpp"

class GameManager
{
	private:
		RenderEngine * renderEngine;
		World *world;

	public:
		GameManager();
		GameManager(std::string libsDir[], int width, int height);
		GameManager(GameManager &obj);
		virtual ~GameManager();
		GameManager &operator=(GameManager const &other);
		static GameManager *instance;

		RenderEngine *getRenderEngine();
		World *GetWorld();
};

#endif