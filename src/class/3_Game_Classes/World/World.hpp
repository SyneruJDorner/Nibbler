#ifndef WORLD_HPP
# define WORLD_HPP

# include <string>
# include "../Transformation/Transform.hpp" 
# include "../Grid/Grid.hpp" 

class World
{
	public:
		World();
		World(int screenWidth, int screenHeight, int gridSize);
		World(const World &obj);
		virtual ~World();
		World &operator=(const World &other);
		static World *instance;
		void SetupGrid(int screenWidth, int screenHeight, int gridSize);
        Vector2 GetMinGrid() const;
        Vector2 GetMaxGrid() const;
		int GetGridSize() const;
		int getWidth() const;
		int getHeight() const;

	private:
        Vector2 GridMinCoords;
        Vector2 GridMaxCoords;
		Grid_t **worldGrids;
		int grdiSize;
		int width;
		int height;
};

#endif