
#include "./class/5_Render_Engine/RenderEngine.hpp"

// int main()
// {
//     std::string libs[] = {
//         "../libraries/libGLFW.so",
//         "../libraries/libSDL2.so",
//         "../libraries/libSFML.so"
//     };

//     RenderEngine * engine = new RenderEngine(libs, 800, 600, 2);

//     std::string command;
//     while (1)
//     {
//         engine->getGraphicLib()->events();

//         if (std::getline(std::cin, command))
//         {
//             engine->changeGraphicLib(std::stoi(command));
//         }
//     }
// }