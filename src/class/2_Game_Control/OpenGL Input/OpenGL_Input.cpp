#include "OpenGL_Input.hpp"
#include <GLFW/glfw3.h>

//Create a singolton access point.
//You can easily access anything therogh the following.
//Input::instance->WHAT_YOU_WANT();
OpenGL_Input *OpenGL_Input::instance = new OpenGL_Input();

OpenGL_Input::OpenGL_Input()
{

}

OpenGL_Input::OpenGL_Input(OpenGL_Input &obj)
{
    (void)obj;
}

OpenGL_Input::~OpenGL_Input()
{

}

/*
OpenGL_Input &OpenGL_Input::operator=(OpenGL_Input const &other)
{

}
*/

int OpenGL_Input::DetermineInput() //Returns int for GLFW (example: GLFW_KEY_E)
{
    switch (Input::instance->GetPressedKey())
    {
        case (A):
            return GLFW_KEY_A;
        case (B):
            return GLFW_KEY_B;
        case (C):
            return GLFW_KEY_C;
        case (D):
            return GLFW_KEY_D;
        case (E):
            return GLFW_KEY_E;
        case (F):
            return GLFW_KEY_F;
        case (G):
            return GLFW_KEY_G;
        case (H):
            return GLFW_KEY_H;
        case (I):
            return GLFW_KEY_I;
        case (J):
            return GLFW_KEY_J;
        case (K):
            return GLFW_KEY_K;
        case (L):
            return GLFW_KEY_L;
        case (M):
            return GLFW_KEY_M;
        case (N):
            return GLFW_KEY_N;
        case (O):
            return GLFW_KEY_O;
        case (P):
            return GLFW_KEY_P;
        case (Q):
            return GLFW_KEY_Q;
        case (R):
            return GLFW_KEY_R;
        case (S):
            return GLFW_KEY_S;
        case (T):
            return GLFW_KEY_T;
        case (U):
            return GLFW_KEY_U;
        case (V):
            return GLFW_KEY_V;
        case (W):
            return GLFW_KEY_W;
        case (X):
            return GLFW_KEY_X;
        case (Y):
            return GLFW_KEY_Y;
        case (Z):
            return GLFW_KEY_Z;
        default:
            return -1;
    }
}