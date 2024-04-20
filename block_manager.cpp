#include<SFML/Graphics.hpp>

#include<chrono>

#include "block_manager.h"

using namespace std::chrono_literals;

auto block_manager::display(sf::RenderWindow& w) -> void
{
	for (auto& x : blocks)
	{
		x.display(w);
	}
}

auto block_manager::update() -> void
{
	if ((std::chrono::system_clock::now() - last) <= 0.1s)
	{
		for (auto& x : blocks)
		{
			x.moveForwards();

			if (x.s.getPosition().x < 0)
			{
				x.die();
				blocks.push_back(block{});
			}
		}
	}
}