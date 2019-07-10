#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(int ac, char **av)
{

    (void)av;
    (void)ac;
    sf::RenderWindow d;
    d.create(sf::VideoMode(900, 600), "Snake SFML");
    // sf::RenderWindow window(sf::VideoMode(200,200), "Hello World");
    // sf::CircleShape shape(100.f);
    // shape.setPointCount(128);
    // shape.setFillColor(sf::Color::Green);

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }
    while (1)
    {
    }
    
    d.close();
}