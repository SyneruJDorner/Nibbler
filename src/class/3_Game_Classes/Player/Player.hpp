#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include <vector>
# include "../../2_Game_Control/Input.hpp"
# include "../Transformation/Transform.hpp"

struct SnakeBody
{
	Vector2 Head;
	std::vector<Vector2> Body;//can call Body.push_back() or Body.push_back()
	Vector2 Tail;
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

	private:
		void UpdateSnakeBody();
		Transform_t transform;
		SnakeBody snakeBody;
};

#endif