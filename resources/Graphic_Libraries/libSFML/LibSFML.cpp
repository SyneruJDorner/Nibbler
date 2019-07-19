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

void LibSFML::events()
{
    this->window->clear();
    sf::Event ev;
    this->window->pollEvent(ev);
    {
        if(ev.type == sf::Event::Closed || ev.key.code == sf::Keyboard::Escape)
            this->window->close();
    }
    this->window->display();
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

void LibSFML::terminateWindow()
{
    this->window->close();
    delete this->window;
    return ;
}
