#ifndef TRANSFORM_HPP
# define TRANSFORM_HPP

# include <string>
#include "./Vectors/Vector2.hpp"

enum e_direction
{
	DIR_NUL = -1,
    Up = 0,
    Left = 1,
    Down = 2,
    Right = 3
};

struct Transform_t
{
	Vector2 Position;
	e_direction Direction = DIR_NUL;
};

#endif