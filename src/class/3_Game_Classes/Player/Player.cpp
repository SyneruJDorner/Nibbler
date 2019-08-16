#include "Player.hpp"
#include "../_World/World.hpp"

//Create a singolton access point.
//You can easily access anything though the following.
//Player::instance->WHAT_YOU_WANT();
Player *Player::instance = new Player();

Player::Player()
{
    //Set up the snakes head
    this->snakeBody.Head.Position.x = 32;
    this->snakeBody.Head.Position.y = 24;
    this->snakeBody.Head.Direction = Up;
    this->snakeBody.Head.Color.SetColour(1.0, 1.0, 1.0, 1.0);

    //Set up the snakes body
    for (size_t i = 0; i < 5; i++)
    {
        Transform_t bodyPart;
        bodyPart.Position.x = 32 - i;
        bodyPart.Position.y = 24;
        bodyPart.Direction = DIR_NUL;
        bodyPart.Color.SetColour(1.0, 0.0, 0.0, 1.0);
        this->snakeBody.Body.push_back(bodyPart);
    }
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

//This will handle all the general position of the snake in a Vector2 World
void Player::UpdateSnakeBody()
{
    this->snakeBody.Body[this->snakeBody.Body.size() - 1].Position.x = this->snakeBody.Head.Position.x;
    this->snakeBody.Body[this->snakeBody.Body.size() - 1].Position.y = this->snakeBody.Head.Position.y;
    std::rotate(this->snakeBody.Body.rbegin(), this->snakeBody.Body.rbegin() + 1, this->snakeBody.Body.rend());
}

e_CollisionType Player::DetermineCollisions()
{
    /*
    //Determine if the head touches any of the following:
    //-It's body
    //-It's tail
    //-An Obsticle
    //-Edge of world
    //-A fruit/collectable item

    Vector2 headPos = this->snakeBody.Head;

    //Body Collision
    for(size_t i = 0; i < this->snakeBody.Body.size(); i++)
    {
        if (headPos.x == this->snakeBody.Body[i].x &&
            headPos.y == this->snakeBody.Body[i].y)
            return (e_CollisionType)Body;
    }

    //Tail Collision
    if (headPos.x == this->snakeBody.Tail.x &&
        headPos.y == this->snakeBody.Tail.y)
        return (e_CollisionType)Tail;
    */

    //Obsticle
    /*
    for ()
    if (headPos == this->snakeBody.Tail)
        return (e_CollisionType)Tail;
    */


    /*
    //Edge of world
    if (headPos.x <= World::instance->GetMinGrid().x || 
        headPos.x >= World::instance->GetMaxGrid().x ||
        headPos.y <= World::instance->GetMinGrid().y || 
        headPos.y >= World::instance->GetMaxGrid().y)
        return (e_CollisionType)Obsticle;
    */
    return (e_CollisionType)None;
}

SnakeBody Player::GetSanke()
{
    return (this->snakeBody);
}