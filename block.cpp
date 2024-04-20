#include<SFML/Graphics.hpp>

#include"block.h"

#include<random>

block::block()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 400);

	s.setPosition(sf::Vector2f(400, dist6(rng)));
}

auto block::display(sf::RenderWindow& w) -> void
{
	if (!is_dead)
	{
		w.draw(s);
	}
}

auto block::die() -> void
{
	is_dead = true;
}

auto block::moveForwards() -> void
{
	s.move(-1, 0);
}