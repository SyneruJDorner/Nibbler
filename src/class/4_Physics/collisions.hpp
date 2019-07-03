#ifndef COLLISIONS_HPP
# define COLLISIONS_HPP

# include <string>

class Collisions
{
	public:
		Collisions();
		Collisions(Collisions &obj);
		virtual ~Collisions();
		Collisions &operator=(Collisions const &other);
};

#endif