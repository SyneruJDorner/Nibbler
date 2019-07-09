#include "Player.hpp"
#include "../_World/World.hpp"

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

    //Move the head into the desired position
    Vector2 HeadPreviousPos = this->snakeBody.Head;
    this->snakeBody.Head += MovementVector;

    //Move the last joint of the snakes body to the first point
    //Still need to figure out a nice way to
    //Update the coord on the body
    Vector2 Joint = this->snakeBody.Body[this->snakeBody.Body.size() - 1];
    jointPreviousPos = Joint;
    joint = HeadPreviousPos; //This will set the last body part of the snake to the heads previous position
    this->snakeBody.Body.pop_back();
    this->snakeBody.Body.push_front(&Joint);

    //Update the tails position based on the updated
    //Joint above we use its previous pos
    this->snakeBody.Tail += jointPreviousPos;
}

e_CollisionType Player::DetermineCollisions()
{
    //Determine if the head touches any of the following:
    //-It's body
    //-It's tail
    //-An Obsticle
    //-Edge of world
    //-A fruit/collectable item

    Vector2 headPos = this->snakeBody.Head;

    //Body Collision
    for (std::list<Vector2>::iterator it = this->snakeBody.Body.begin(); it != this->snakeBody.Body.end(); ++it)
    {
        if (headPos == this->snakeBody.Body[it])
            return (e_CollisionType)Body;
    }

    //Tail Collision
    if (headPos == this->snakeBody.Tail)
        return (e_CollisionType)Tail;

    //Obsticle
    /*
    for ()
    if (headPos == this->snakeBody.Tail)
        return (e_CollisionType)Tail;
    */

    //Edge of world
    if (headPos.x <= World::instance->GetMinGrid().x || 
        headPos.x >= World::instance->GetMaxGrid().x ||
        headPos.y <= World::instance->GetMinGrid().y || 
        headPos.y >= World::instance->GetMaxGrid().y)
        return (e_CollisionType)Obsticle;
}