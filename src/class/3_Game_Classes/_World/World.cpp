#include "World.hpp"

//Create a singolton access point.
//You can easily access anything though the following.
//Player::instance->WHAT_YOU_WANT();
World *World::instance = new World();

World::World()
{

}

World::World(int screenWidth, int screenHeight, int gridSize)
{
    SetupGrid(screenWidth, screenHeight, gridSize);
}

World::World(World &obj)
{
    (void)obj;
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

/*
Player &Player::operator=(Player const &other)
{
    (void)other;
}
*/

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

Vector2 World::GetMinGrid()
{
    return GridMinCoords;
}

Vector2 World::GetMaxGrid()
{
    return GridMaxCoords;
}

int World::GetGridSize()
{
    return (this->grdiSize);
}