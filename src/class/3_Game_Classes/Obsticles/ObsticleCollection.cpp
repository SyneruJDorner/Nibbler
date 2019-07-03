#include "ObsticleCollection.hpp"

//Create a singolton access point.
//You can easily access anything though the following.
//ObsticleCollection::instance->WHAT_YOU_WANT();
ObsticleCollection *ObsticleCollection::instance = new ObsticleCollection();

ObsticleCollection::ObsticleCollection()
{

}

ObsticleCollection::ObsticleCollection(ObsticleCollection &obj)
{

}

ObsticleCollection::~ObsticleCollection()
{

}

ObsticleCollection &ObsticleCollection::operator=(ObsticleCollection const &other)
{

}