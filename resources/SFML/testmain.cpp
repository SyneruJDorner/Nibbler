#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

bool exit = false;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
        while (!exit)
        {
            window.clear();
            sf::Event ev;
            window.pollEvent(ev);
            if (ev.type == sf::Event::KeyPressed) {
                switch (ev.key.code) {
                
                    case sf::Keyboard::Escape:
                        exit = !exit;
                        break;                
                    default:
                        break;
                }
            }
            window.display();
        }

    return 0;
}