#include "collisions.hpp"

Collisions::Collisions()
{

}

Collisions::Collisions(const Collisions &obj)
{
    (void)obj;
}

Collisions::~Collisions()
{

}

Collisions &Collisions::operator=(const Collisions &other)
{
    Collisions *collisions = new Collisions;
    (void)other;
    return *collisions;
}