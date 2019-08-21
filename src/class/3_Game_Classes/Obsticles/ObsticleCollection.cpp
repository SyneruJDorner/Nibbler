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
    (void)obj;
}

ObsticleCollection::~ObsticleCollection()
{
    
}

std::vector<Obsticle> *ObsticleCollection::getObsticleList()
{
    return &this->ObsticlesList;
}

std::vector<Obsticle> *ObsticleCollection::getCollectablesList()
{
    return &this->CollectablesList;
}

std::vector<Obsticle> *ObsticleCollection::getBonusCollectablesList()
{
    return &this->BonusCollectablesList;
}

/*
ObsticleCollection &ObsticleCollection::operator=(ObsticleCollection const &other)
{

}
*/