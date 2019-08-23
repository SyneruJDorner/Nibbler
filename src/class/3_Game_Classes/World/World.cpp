#include "World.hpp"

//Create a singolton access point.
//You can easily access anything though the following.
//Player::instance->WHAT_YOU_WANT();
World *World::instance = new World();

World::World()
{
    return ;
}

World::World(int screenWidth, int screenHeight, int gridSize)
{
    SetupGrid(screenWidth, screenHeight, gridSize);
    this->width = screenWidth;
    this->height = screenHeight;
}

World::World(const World &obj)
{
    *this = obj;
}

World::~World()
{
    int rows =  sizeof(this->worldGrids) / sizeof(this->worldGrids[0]); // 2 rows  

    for (int i = 0; i < rows; i++)
    {
        delete[] this->worldGrids[i];
    }

    delete[] this->worldGrids;
}

World &World::operator=(const World &other)
{
    World *world = new World();
    world->grdiSize = other.grdiSize;
    world->GridMaxCoords = other.GridMaxCoords;
    world->GridMinCoords = other.GridMinCoords;
    world->height = other.height;
    world->instance = other.instance;
    world->width = other.width;
    world->worldGrids = other.worldGrids;
    return *world;
}

void World::SetupGrid(int screenWidth, int screenHeight, int gridDimensions)
{
    GridMinCoords.x = 0;
    GridMinCoords.y = 0;
    GridMaxCoords.x = screenWidth;
    GridMaxCoords.y = screenHeight;

    this->grdiSize = gridDimensions;

    const int gridWidth = screenWidth / gridDimensions;
    const int gridHeight = screenHeight / gridDimensions;

    this->worldGrids = new Grid_t*[gridHeight];
    for(int i = 0; i < gridHeight; ++i)
        this->worldGrids[i] = new Grid_t[gridWidth];
}

Vector2 World::GetMinGrid() const
{
    return GridMinCoords;
}

Vector2 World::GetMaxGrid() const
{
    return GridMaxCoords;
}

int World::GetGridSize() const
{
    return (this->grdiSize);
}

int World::getHeight() const
{
    return (this->height);
}

int World::getWidth() const
{
    return (this->width);
}