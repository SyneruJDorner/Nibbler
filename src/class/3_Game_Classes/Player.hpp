#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
#include "../2_Game_Control/Input.hpp"
#include "Transformation/Transform.hpp"

class Player
{
	public:
		Player();
		Player(Player &obj);
		virtual ~Player();
		Player &operator=(Player const &other);
		static Player *instance;
		void PlayerMovement(KeyCode keycode);

	private:
		Transform transform;
};

#endif