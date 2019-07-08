#include "Player.hpp"

//Create a singolton access point.
//You can easily access anything though the following.
//Player::instance->WHAT_YOU_WANT();
Player *Player::instance = new Player();

Player::Player()
{

}

Player::Player(Player &obj)
{
    (void)obj;
}

Player::~Player()
{

}

/*
Player &Player::operator=(Player const &other)
{
    (void)other;
}
*/

void Player::PlayerMovement(KeyCode keycode)
{
    if (keycode == W)
        std::cout << "Up" << std::endl;

    if (keycode == A)
        std::cout << "Left" << std::endl;

    if (keycode == S)
        std::cout << "Down" << std::endl;

    if (keycode == D)
        std::cout << "Right" << std::endl;
}