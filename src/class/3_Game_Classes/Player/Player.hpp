#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include <list>
# include "../../2_Game_Control/Input.hpp"
# include "../Transformation/Transform.hpp"

struct SnakeBody
{
	Vector2 Head;
	std::list <Vector2> Body;//can call Body.push_back() or Body.push_back()
	Vector2 Tail;
}

class Player
{
	public:
		Player();
		Player(Player &obj);
		virtual ~Player();
		Player &operator=(Player const &other);
		static Player *instance;
		void PlayerMovement(KeyCode keycode);
		void DetermineCollisions();

	private:
		void UpdateSnakeBody();
		Transform transform;
		SnakeBody snakeBody;
};

#endif