#include "GameManager.hpp"

//Create a singolton access point.
//You can easily access anything though the following.
//GameManager::instance->WHAT_YOU_WANT();
GameManager *GameManager::instance = new GameManager();

GameManager::GameManager()
{
    this->renderEngine = NULL;
}

GameManager::GameManager(std::string libsDir[], int width, int height)
{
    this->renderEngine = new RenderEngine(libsDir, width, height, 1);
}

GameManager::GameManager(GameManager &obj)
{
    RenderEngine *engine = new RenderEngine(
        obj.renderEngine->getLibDirectories(),
        obj.renderEngine->getWidth(),
        obj.renderEngine->getWidth(),
        obj.renderEngine->getActiveLibNum()
    );

    this->renderEngine = engine;
}

GameManager::~GameManager()
{
    delete this->renderEngine;
}

GameManager &GameManager::operator=(GameManager const &other)
{
    RenderEngine *engine = new RenderEngine(
            other.renderEngine->getLibDirectories(),
            other.renderEngine->getWidth(),
            other.renderEngine->getWidth(),
            other.renderEngine->getActiveLibNum()
        );

    this->renderEngine = engine;
    return *this;
}

RenderEngine *GameManager::getRenderEngine()
{
    return this->renderEngine;
}