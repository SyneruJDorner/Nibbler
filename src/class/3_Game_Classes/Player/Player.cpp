#include "Player.hpp"
#include "../_World/World.hpp"

//Create a singolton access point.
//You can easily access anything though the following.
//Player::instance->WHAT_YOU_WANT();
Player *Player::instance = new Player();

Player::Player()
{

}

Player::Player(const Player &obj)
{
    (void)obj;
}

Player::~Player()
{

}

Player &Player::operator=(const Player &other)
{
    Player *player = new Player();
    player->instance = other.instance;
    player->snakeBody = other.snakeBody;
    return *player;
}

void Player::PlayerMovement(KeyCode keycode)
{
    //We going update the snake movement every frame based on the direction they are assigned to
    if (keycode == W &&
        this->snakeBody.Head.Direction != Down)
        this->snakeBody.Head.Direction = Up;

    if (keycode == A &&
        this->snakeBody.Head.Direction != Right)
        this->snakeBody.Head.Direction = Left;

    if (keycode == S &&
        this->snakeBody.Head.Direction != Up)
        this->snakeBody.Head.Direction = Down;

    if (keycode == D &&
        this->snakeBody.Head.Direction != Left)
        this->snakeBody.Head.Direction = Right;

    if (this->snakeBody.Head.Direction != DIR_NUL)
        UpdateSnakeBody();

    switch (this->snakeBody.Head.Direction)
    {
        case (Up):
            this->snakeBody.Head.Position.y -= 1;
            break;
        case (Down):
           this->snakeBody.Head.Position.y += 1;
            break;
        case (Left):
            this->snakeBody.Head.Position.x -= 1;
            break;
        case (Right):
            this->snakeBody.Head.Position.x += 1;
            break;
        default:
            break;
    }
    
}

void Player::SetupSnake(int maxX, int maxY)
{
    //Set up the snakes head
    this->snakeBody.Head.Position.x = maxX/2;
    this->snakeBody.Head.Position.y = maxY/2;
    this->snakeBody.Head.Direction = Up;
    this->snakeBody.Head.Color.SetColour(1.0, 1.0, 1.0, 1.0);

    //Set up the snakes body
    for (size_t i = 1; i <= 4 ; i++)
    {
        Transform_t bodyPart;
        bodyPart.Position.x = maxX/2 - i;
        bodyPart.Position.y = maxY/2;
        bodyPart.Direction = DIR_NUL;
        bodyPart.Color.SetColour(1.0, 0.0, 0.0, 1.0);
        this->snakeBody.Body.push_back(bodyPart);
    }
}

//This will handle all the general position of the snake in a Vector2 World
void Player::UpdateSnakeBody()
{
    this->snakeBody.Body[this->snakeBody.Body.size() - 1].Position.x = this->snakeBody.Head.Position.x;
    this->snakeBody.Body[this->snakeBody.Body.size() - 1].Position.y = this->snakeBody.Head.Position.y;
    std::rotate(this->snakeBody.Body.rbegin(), this->snakeBody.Body.rbegin() + 1, this->snakeBody.Body.rend());
}

e_CollisionType Player::DetermineCollisions()
{
    return (e_CollisionType)None;
}

SnakeBody *Player::getSnake()
{
    return (&this->snakeBody);
}