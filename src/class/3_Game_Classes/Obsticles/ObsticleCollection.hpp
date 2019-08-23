#ifndef OBSTICLECOLLECTION_HPP
# define OBSTICLECOLLECTION_HPP

# include <string>
# include <vector>
# include "Obsticle.hpp"

class ObsticleCollection
{
	public:
		ObsticleCollection();
		ObsticleCollection(const ObsticleCollection &obj);
		virtual ~ObsticleCollection();
		ObsticleCollection &operator=(const ObsticleCollection &other);
		static ObsticleCollection *instance;

		std::vector<Obsticle> *getObsticleList();
		std::vector<Obsticle> *getCollectablesList();
		std::vector<Obsticle> *getBonusCollectablesList();

    private:
		//Holds a list of all the obsticles in the world
        std::vector<Obsticle> ObsticlesList;
		std::vector<Obsticle> CollectablesList;
		std::vector<Obsticle> BonusCollectablesList;
};

#endif