#ifndef GAMEMANAGER_HPP
# define GAMEMANAGER_HPP

# include <string>
#include "../5_Render_Engine/RenderEngine.hpp"

class GameManager
{
	private:
		RenderEngine * renderEngine;
	public:
		GameManager();
		GameManager(std::string libsDir[], int width, int height);
		GameManager(GameManager &obj);
		virtual ~GameManager();
		GameManager &operator=(GameManager const &other);
		static GameManager *instance;

		RenderEngine *getRenderEngine();
};

#endif