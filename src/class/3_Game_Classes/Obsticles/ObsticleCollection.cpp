#include "ObsticleCollection.hpp"

//Create a singolton access point.
//You can easily access anything though the following.
//ObsticleCollection::instance->WHAT_YOU_WANT();
ObsticleCollection *ObsticleCollection::instance = new ObsticleCollection();

ObsticleCollection::ObsticleCollection()
{
    return ;
}

ObsticleCollection::ObsticleCollection(const ObsticleCollection &obj)
{
    *this = obj;
}

ObsticleCollection::~ObsticleCollection()
{
    return ;
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

ObsticleCollection &ObsticleCollection::operator=(const ObsticleCollection &other)
{
    ObsticleCollection *obsticleCollection = new ObsticleCollection();
    obsticleCollection->BonusCollectablesList = other.BonusCollectablesList;
    obsticleCollection->CollectablesList = other.CollectablesList;
    obsticleCollection->instance = other.instance;
    obsticleCollection->ObsticlesList = other.ObsticlesList;
    return *obsticleCollection;
}