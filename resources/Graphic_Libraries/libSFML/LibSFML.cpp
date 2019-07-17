#include "LibSFML.hpp"

extern "C" IGraphicsLib *createLib()
{
    return new LibSFML;
}

extern "C" void destroyLib(IGraphicsLib* instance)
{
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

void LibSFML::init(int width, int height)
{
    this->window.create(sf::VideoMode(width, height), "SFML works!");
}

void LibSFML::events()
{
    this->window.clear();
    sf::Event ev;
    this->window.pollEvent(ev);
    if (ev.type == sf::Event::KeyPressed) {
        switch (ev.key.code) {
        
            case sf::Keyboard::Escape:
                this->window.close();
                break;                
            default:
                break;
        }
    }
    this->window.display();
}

void LibSFML::updateDisplay()
{
    return ;
}

void LibSFML::draw(Vector2 point)
{
    (void)point;
    return ;
}
