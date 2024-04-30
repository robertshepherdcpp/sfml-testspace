#include<SFML/Graphics.hpp>

#include<chrono>
#include<iostream>

#include "block_manager.h"

using namespace std::chrono_literals;

auto block_manager::display(sf::RenderWindow& w) -> void
{
	if (!dead)
	{
		for (auto& x : blocks)
		{
			x.display(w);
		}
	}
}

auto block_manager::update() -> void
{
	if (blocks.size() == 1 && (std::chrono::system_clock::now() - last) >= 1s)
	{
		blocks.push_back(block{});
	}

	if ((std::chrono::system_clock::now() - last) >= 0.002s)
	{
		for (auto& x : blocks)
		{
			if (x.s.getPosition().x < 0 && !x.is_dead)
			{
				x.die();
				if (!dead)
				{
					playerScore += 1;
				}
				blocks.push_back(block{});

				std::cout << "Player score: " << playerScore << "\n";
			}

			x.moveForwards();
		}
		last = std::chrono::system_clock::now();
	}
}

auto block_manager::checkCollision(const sf::CircleShape& circle, const sf::RectangleShape& rectangle) -> bool
{
	// Get the center of the circle
	sf::Vector2f circleCenter = circle.getPosition() + sf::Vector2f(circle.getRadius(), circle.getRadius());

	// Get the center of the rectangle
	sf::Vector2f rectangleCenter = rectangle.getPosition() + 0.5f * rectangle.getSize();

	// Calculate the distance between the centers of the circle and the rectangle
	float dx = std::abs(circleCenter.x - rectangleCenter.x);
	float dy = std::abs(circleCenter.y - rectangleCenter.y);

	// Calculate the maximum distance between the centers for a possible collision
	float maxDistX = circle.getRadius() + 0.5f * rectangle.getSize().x;
	float maxDistY = circle.getRadius() + 0.5f * rectangle.getSize().y;

	// If the distance between the centers is less than or equal to the maximum distance for both axes,
	// then they might intersect
	return (dx <= maxDistX) && (dy <= maxDistY);
}

auto block_manager::hasHit(sf::CircleShape x) -> bool
{
	for (auto& y : blocks)
	{
		if (checkCollision(x, y.s))
		{
			return true;
		}
	}

	return false;
}