#include "LibSFML.hpp"

extern "C" IGraphicsLib *createLib()
{
    return new LibSFML;
}

extern "C" void destroyLib(IGraphicsLib* instance)
{
    instance->terminateWindow();
    delete instance;
}

LibSFML::LibSFML(void)
{
    return ;
}

LibSFML::~LibSFML(void)
{
    return ;
}

LibSFML::LibSFML(const LibSFML &other)
{
    *this = other;
}

LibSFML *LibSFML::operator=(const LibSFML &other)
{
    (void)other;
    return this;
}

void LibSFML::init(int width, int height, std::string title)
{
    this->window = new sf::RenderWindow();
    this->window->create(sf::VideoMode(width, height), title.c_str());
}

e_GraphicLibInput LibSFML::events()
{
    sf::Event event;
    if (this->window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
        {
            this->window->close();
            return ESCAPE;
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::F1:
                    return GLFW;
                case sf::Keyboard::F2:
                    return SDL2;
                case sf::Keyboard::F3:
                    return SFML;
                case sf::Keyboard::W:
                    std::cout << "Event SFML key W" << std::endl;
                    return UP;
                    break;
                case sf::Keyboard::S:
                    std::cout << "Event SFML key S" << std::endl;
                    return DOWN;
                    break;
                case sf::Keyboard::A:
                    std::cout << "Event SFML key A" << std::endl;
                    return LEFT;
                    break;
                case sf::Keyboard::D:
                    std::cout << "Event SFML key D" << std::endl;
                    return RIGHT;
                    break;
                default:
                    break;
            }
        }
    }

    return STD;
}

void LibSFML::updateDisplay()
{
    this->window->clear();
    this->window->display();
    return ;
}

void LibSFML::draw(Vector2 point)
{
    (void)point;
    return ;
}

void LibSFML::terminateWindow()
{
    this->window->close();
    delete this->window;
    return ;
}
