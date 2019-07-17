#include "../resources/Graphic_Libraries/libGLFW/LibGLFW.hpp"
#include "../resources/Graphic_Libraries/libSDL2/LibSDL2.hpp"
#include "../resources/Graphic_Libraries/libSFML/LibSFML.hpp"
#include <dlfcn.h>

int main(int ac, char** av)
{
    const char * libs[] = { "../Libraries/libGLFW.so",
                            "../Libraries/libSDL2.so",
                            "../Libraries/libSFML.so"};
    if (ac > 1)
    {
        // load the triangle library
        void* graphicLib = dlopen(libs[std::stoi(av[1])], RTLD_LAZY);
        if (!graphicLib) {
            std::cerr << "Cannot load library: " << dlerror() << '\n';
            return 1;
        }

        // reset errors
        dlerror();
        
        // load the symbols
        createLib_t* create_Lib = (createLib_t*) dlsym(graphicLib, "createLib");
        const char* dlsym_error = dlerror();
        if (dlsym_error) {
            std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
            return 1;
        }
        
        destroyLib_t* destroy_Lib = (destroyLib_t*) dlsym(graphicLib, "destroyLib");
        dlsym_error = dlerror();
        if (dlsym_error) {
            std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
            return 1;
        }

        // create an instance of the class
        IGraphicsLib* lib = create_Lib();

        // use the class
        lib->init(800, 600);

        while (1)
        {
            lib->events();
        }
        
        // destroy the class
        destroy_Lib(lib);

        // unload the triangle library
        dlclose(graphicLib);
    }
    
}