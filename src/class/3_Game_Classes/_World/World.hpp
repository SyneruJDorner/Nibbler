#ifndef WORLD_HPP
# define WORLD_HPP

# include <string>

class World
{
	public:
		World();
		World(World &obj);
		virtual ~World();
		World &operator=(World const &other);
		static World *instance;
		void SetupGrid(int width, int height);

	private:
		int width;
        int height;
};

#endif