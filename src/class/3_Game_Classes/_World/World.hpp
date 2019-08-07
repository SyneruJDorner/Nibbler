#ifndef WORLD_HPP
# define WORLD_HPP

# include <string>
# include "../Transformation/Transform.hpp" 

class World
{
	public:
		World();
		World(World &obj);
		virtual ~World();
		World &operator=(World const &other);
		static World *instance;
		void SetupGrid(int width, int height);
        Vector2 GetMinGrid();
        Vector2 GetMaxGrid();

	private:
        Vector2 GridMinCoords;
        Vector2 GridMaxCoords;
		Vector2 GridCoords[];
};

#endif