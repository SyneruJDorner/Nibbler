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



class Player
{
	public:
		Player();
		Player(const Player &obj);
		virtual ~Player();
		Player &operator=(const Player &other);
		static Player *instance;
		void PlayerMovement(KeyCode keycode);
		e_CollisionType DetermineCollisions();
		SnakeBody *getSnake();

		void SetupSnake(int maxX, int maxY);
		
		void UpdateSnakeBody();
	private:
		SnakeBody snakeBody;
};

#endif