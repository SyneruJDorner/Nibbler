#include "GameManager.hpp"

//Create a singolton access point.
//You can easily access anything though the following.
//GameManager::instance->WHAT_YOU_WANT();
GameManager *GameManager::instance = new GameManager();

GameManager::GameManager()
{

}

GameManager::GameManager(GameManager &obj)
{
    (void)obj;
}

GameManager::~GameManager()
{

}

/*
GameManager &GameManager::operator=(GameManager const &other)
{

}
*/