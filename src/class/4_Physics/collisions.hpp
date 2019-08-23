#ifndef COLLISIONS_HPP
# define COLLISIONS_HPP

# include <string>

class Collisions
{
	public:
		Collisions();
		Collisions(const Collisions &obj);
		virtual ~Collisions();
		Collisions &operator=(const Collisions &other);
};

#endif