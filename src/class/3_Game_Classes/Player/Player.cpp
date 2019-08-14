#include "Player.hpp"
#include "../_World/World.hpp"

//Create a singolton access point.
//You can easily access anything though the following.
//Player::instance->WHAT_YOU_WANT();
Player *Player::instance = new Player();

Player::Player()
{
    this->transform.Position.x = 32;
    this->transform.Position.y = 24;
    this->transform.Direction = DIR_NUL;
    this->transform.Color.SetColour(1.0, 0.5, 0.5, 1.0);
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
    if (keycode == W &&
        this->transform.Direction != Down)
        this->transform.Direction = Up;

    if (keycode == A &&
        this->transform.Direction != Right)
        this->transform.Direction = Left;

    if (keycode == S &&
        this->transform.Direction != Up)
        this->transform.Direction = Down;

    if (keycode == D &&
        this->transform.Direction != Left)
        this->transform.Direction = Right;

    if (this->transform.Direction == Up)
        this->transform.Position.y -= 1;
    if (this->transform.Direction == Down)
        this->transform.Position.y += 1;
    if (this->transform.Direction == Left)
        this->transform.Position.x -= 1;
    if (this->transform.Direction == Right)
        this->transform.Position.x += 1;
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
    this->snakeBody.Head.x += MovementVector.x;
    this->snakeBody.Head.y += MovementVector.y;

    //Move the last joint of the snakes body to the first point
    //Still need to figure out a nice way to
    //Update the coord on the body
    //Vector2 Joint = this->snakeBody.Body[this->snakeBody.Body.size() - 1];
    //Vector2 jointPreviousPos = Joint;
    //Joint = HeadPreviousPos; //This will set the last body part of the snake to the heads previous position
    
    Vector2 LastBodyPos = this->snakeBody.Body.back();
    this->snakeBody.Body.insert(this->snakeBody.Body.begin(), this->snakeBody.Body.back());
    this->snakeBody.Body.pop_back();
    this->snakeBody.Body[0] = HeadPreviousPos;

    //Update the tails position based on the updated
    //Joint above we use its previous pos
    this->snakeBody.Tail = LastBodyPos;
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
    return (e_CollisionType)None;
}

Transform_t Player::GetTranform()
{
    return (this->transform);
}