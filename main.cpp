#include<chrono>

#include <SFML/Graphics.hpp>

#include "Bird.h"

#include "block_manager.h"

using namespace std::chrono_literals;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    Bird b{};

    block_manager bm{};

    auto last = std::chrono::system_clock::now();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    b.flap();
                }
            }
        }

        if ((std::chrono::system_clock::now() - last) >= 0.05s)
        {
            b.update();
            last = std::chrono::system_clock::now();
        }

        bm.update();

        window.clear();
        b.display(window);
        bm.display(window);
        window.display();
    }

    return 0;
} 