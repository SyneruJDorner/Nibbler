#ifndef GAMEMANAGER_HPP
# define GAMEMANAGER_HPP

# include <string>

class GameManager
{
	public:
		GameManager();
		GameManager(GameManager &obj);
		virtual ~GameManager();
		GameManager &operator=(GameManager const &other);
		static GameManager *instance;
};

#endif