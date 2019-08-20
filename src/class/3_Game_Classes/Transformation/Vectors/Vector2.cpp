#include "Vector2.hpp"

bool Vector2::operator==(const Vector2 &other)
{
    if (other.x == this->x)
        if (other.y == this->y)
            return true;
    return false;
}