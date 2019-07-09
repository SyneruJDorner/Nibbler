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
    //We going update the snake movement
    //every frame based on the direction
    //they are assigned to
    if (keycode == W)
    {
        std::cout << "Up" << std::endl;
        //this->transform.Position.y += 1;
        this->transform.Direction = Up;
    }

    if (keycode == A)
    {
        std::cout << "Left" << std::endl;
        //this->transform.Position.x -= 1;
        this->transform.Direction = Left;
    }

    if (keycode == S)
    {
        std::cout << "Down" << std::endl;
        //this->transform.Position.y -= 1;
        this->transform.Direction = Down;
    }

    if (keycode == D)
    {
        std::cout << "Right" << std::endl;
        //this->transform.Position.x += 1;
        this->transform.Direction = Right;
    }
}

//This will handle all the general
//position of the snake in a Vector2
//World
void Player::UpdateSnakeBody()
{
    Vector2 MovementVector;

    switch (this->transform.Direction)
    {
        case Up:
            MovementVector.y += 1;
            break;
        case Down:
            MovementVector.y -= 1;
            break;
        case Right:
            MovementVector.x += 1;
            break;
        case Left:
            MovementVector.x -= 1;
            break;
        
        default:
            MovementVector.x = 0;
            MovementVector.y = 0;
            break;
    }

    this->snakeBody.Head += MovementVector;
    for (std::list<Vector2>::iterator it = this->snakeBody.Body.begin(); it != this->snakeBody.Body.end(); ++it)
    {
        this->snakeBody.Body[it] += MovementVector;
    }
    this->snakeBody.Tail += MovementVector;
}

void Player::DetermineCollisions()
{
    //Determine if the head touches any of the following:
    //-It's body
    //-It's tail
    //-An Obsticle
    //-Edge of world
    //-A fruit/collectable item
}