#ifndef OBSTICLECOLLECTION_HPP
# define OBSTICLECOLLECTION_HPP

# include <string>
# include <vector>
# include "Obsticle.hpp"

class ObsticleCollection
{
	public:
		ObsticleCollection();
		ObsticleCollection(ObsticleCollection &obj);
		virtual ~ObsticleCollection();
		ObsticleCollection &operator=(ObsticleCollection const &other);
		static ObsticleCollection *instance;

		std::vector<Obsticle> *getObsticleList();
		std::vector<Obsticle> *getCollectablesList();
    
    private:
		//Holds a list of all the obsticles in the world
        std::vector<Obsticle> ObsticlesList;
		std::vector<Obsticle> CollectablesList;
};

#endif