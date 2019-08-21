#ifndef OBSTICLE_HPP
# define OBSTICLE_HPP

# include <string>
# include "../Transformation/Vectors/Vector2.hpp"
# include "../Transformation/Transform.hpp"

struct Obsticle
{
    Transform_t trans;
    e_CollisionType type;
    double lifespan;
    //Vector3 rot
    //int width
    //int height
};

#endif