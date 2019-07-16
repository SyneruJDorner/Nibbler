#ifndef SFML_INPUT_HPP
# define SFML_INPUT_HPP

# include <string>
# include <iostream>
# include "../input.hpp"

class SFML_Input
{
	public:
		SFML_Input();
		SFML_Input(SFML_Input &obj);
		virtual ~SFML_Input();
		SFML_Input &operator=(SFML_Input const &other);
		static SFML_Input *instance;
};

#endif