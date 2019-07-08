#ifndef TRANSFORM_HPP
# define TRANSFORM_HPP

# include <string>
#include "./Vectors/Vector2.hpp"
#include "./Direction/Direction.hpp"

class Transform
{
	public:
		Transform();
		Transform(Transform &obj);
		virtual ~Transform();
		Transform &operator=(Transform const &other);
    
	private:
		Vector2 Position;
		Direction Direction;
};

#endif