#ifndef TRANSFORM_HPP
# define TRANSFORM_HPP

# include <string>
#include "./Vectors/Vector2.hpp"
#include "./Direction/Direction.hpp"

struct Transform
{
	Vector2 Position;
	Direction Direction;
};

#endif