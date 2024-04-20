#include "Bird.h"

Bird::Bird()
{
	bird.setFillColor(sf::Color::Yellow);
	bird.setRadius(15.f);
	bird.setPosition(sf::Vector2f(200, 300)); // total dimensions of screen: 800 X 600
}

auto Bird::display(sf::RenderWindow& w) -> void
{
	w.draw(bird);
}

auto Bird::flap() -> void
{
	velocity += lift;
}

auto Bird::update() -> void
{
    velocity += gravity;

    y += velocity;

    if (y > height) {
        y = height;
        velocity = 0;
    }

    if (y < 0) {
        y = 0;
        velocity = 0;
    }

    bird.setPosition(sf::Vector2f(x, y));
}