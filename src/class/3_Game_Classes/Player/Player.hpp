#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include <vector>
# include "../../2_Game_Control/Input.hpp"
# include "../Transformation/Transform.hpp"

struct SnakeBody
{
	Transform_t Head;
	std::vector<Transform_t> Body;
	Transform_t Tail;
};

enum e_CollisionType
{
	None,
	Body,
	Tail,
	Obsticle,
	Pickup
};

class Player
{
	public:
		Player();
		Player(Player &obj);
		virtual ~Player();
		Player &operator=(Player const &other);
		static Player *instance;
		void PlayerMovement(KeyCode keycode);
		e_CollisionType DetermineCollisions();
		SnakeBody GetSanke();
		
	private:
		void UpdateSnakeBody();
		SnakeBody snakeBody;
};

#endif