#ifndef INPUT_HPP
# define INPUT_HPP

# include <string>
# include <iostream>
# include <termios.h>
# include "../../../resources/Graphic_Libraries/IGraphicsLib.hpp"

enum KeyCode
{
	NUL = 0,
	A = 97,B = 98,C = 99,D = 100,E = 101,F = 102,G = 103,
	H = 104,I = 105,J = 106,K = 107,L = 108,M = 109,N = 110,
	O = 111,P = 112,Q = 113,R = 114,S = 115,T = 116,U = 117,
	V = 118,W = 119,X = 120,Y = 121,Z = 122
};

class Input
{
	public:
		Input();
		Input(const Input &obj);
		virtual ~Input();
		Input &operator=(const Input &other);
		static Input *instance;
		KeyCode DetermineInputs(e_GraphicLibInput output);
		void ResetInput();
		void SetKeycode(char c);
		KeyCode GetPressedKey();

	private:
		KeyCode keyCode;
};

#endif