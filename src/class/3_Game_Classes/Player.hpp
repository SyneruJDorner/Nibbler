#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>

class Player
{
	public:
		Player();
		Player(Player &obj);
		virtual ~Player();
		Player &operator=(Player const &other);
		static Player *instance;
};

#endif