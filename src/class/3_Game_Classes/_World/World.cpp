#include "World.hpp"

//Create a singolton access point.
//You can easily access anything though the following.
//Player::instance->WHAT_YOU_WANT();
World *World::instance = new World();

World::World()
{

}

World::World(World &obj)
{
    (void)obj;
}

World::~World()
{

}

/*
Player &Player::operator=(Player const &other)
{
    (void)other;
}
*/

void World::SetupGrid(int width, int height)
{
    this->width = width;
    this->height = height;
}