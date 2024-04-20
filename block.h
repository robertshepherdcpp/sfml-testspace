#pragma once

#include<SFML/Graphics.hpp>

#include<random>

struct block
{
	block();

	auto display(sf::RenderWindow& w) -> void;
	auto moveForwards() -> void;
	auto die() -> void;

	sf::RectangleShape s{ sf::Vector2f(50, 50) };

	bool is_dead = false;
};