#ifndef RENDERENGINE_HPP
# define RENDERENGINE_HPP

# include <string>
#include <dlfcn.h>
# include "../../../resources/Graphic_Libraries/IGraphicsLib.hpp" 
# include "../../../resources/Graphic_Libraries/utils/Exceptions/GraphicLibraryExceptions.hpp"
# include "../../structs/Exceptions/RenderEngineExceptions.hpp"

class RenderEngine
{
	private:
		int width;
		int height;
		char* dlsym_error;
		createLib_t* createLib;
		destroyLib_t* destroyLib;
		std::string* libDirectories;
		void* graphicLib;
		IGraphicsLib* activeLib;
		int activeLibNum;

	public:
		RenderEngine(std::string *libDir, int width, int height, int activeLib);
		RenderEngine(RenderEngine const &obj);
		virtual ~RenderEngine();
		RenderEngine &operator=(RenderEngine const &other);

		IGraphicsLib *getGraphicLib() const;
		void setGraphicLib(int libNumber);
		void resetGraphicLib();
		void changeGraphicLib(int libNumber);

		int getWidth() const;
		int getHeight() const;
		int getActiveLibNum() const;
		void setLibDirectories(std::string libDir[]);
		std::string *getLibDirectories() const;
};

#endif