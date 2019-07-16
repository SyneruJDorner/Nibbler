#ifndef SDL_INPUT_HPP
# define SDL_INPUT_HPP

# include <string>
# include <iostream>
# include "../input.hpp"

class SDL_Input
{
	public:
		SDL_Input();
		SDL_Input(SDL_Input &obj);
		virtual ~SDL_Input();
		SDL_Input &operator=(SDL_Input const &other);
		static SDL_Input *instance;
};

#endif