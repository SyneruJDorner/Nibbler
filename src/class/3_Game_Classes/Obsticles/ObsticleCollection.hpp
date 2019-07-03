#ifndef OBSTICLESCOLLECTION_HPP
# define OBSTICLECOLLECTION_HPP

# include <string>
# include <list>
# include "Obsticle.hpp"
class ObsticleCollection
{
	public:
		ObsticleCollection();
		ObsticleCollection(ObsticleCollection &obj);
		virtual ~ObsticleCollection();
		ObsticleCollection &operator=(ObsticleCollection const &other);
		static ObsticleCollection *instance;
    
    private:
		//Holds a list of all the obsticles in the world
        std::list<Obsticle> ObsticlesList;
};

#endif