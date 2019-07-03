#ifndef INPUT_HPP
# define INPUT_HPP

# include <string>

class Input
{
	public:
		Input();
		Input(Input &obj);
		virtual ~Input();
		Input &operator=(Input const &other);
		static Input *instance;
};

#endif