#ifndef RENDERENGINE_HPP
# define RENDERENGINE_HPP

# include <string>
#include "../../../resources/Graphic_Libraries/libGLFW/LibGLFW.hpp"
#include "../../../resources/Graphic_Libraries/libSDL2/LibSDL2.hpp"
#include "../../../resources/Graphic_Libraries/libSFML/LibSFML.hpp"
#include "../../structs/Exceptions/RenderEngineExceptions.hpp"
#include <dlfcn.h>

class RenderEngine
{
	private:
		std::string libDirectories[3];
		void *graphicLib;
		const char* dlsym_error;
		createLib_t *createLib;
		destroyLib_t *destroyLib;
		IGraphicsLib *activeLib;
		int width;
		int height;
		int activeLibNum;

	public:
		RenderEngine(std::string *dir, int width, int height, int activeLib);
		RenderEngine(RenderEngine const &obj);
		~RenderEngine();
		RenderEngine &operator=(RenderEngine const &other);
		
		IGraphicsLib &getGraphicLib();
		void setGraphicLib(int libNumber);
		void resetGraphicLib();
		void changeGraphicLib(int libNumber);
};

#endif