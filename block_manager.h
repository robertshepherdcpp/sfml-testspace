#pragma once

#include<SFML/Graphics.hpp>

#include<vector>
#include<chrono>

#include"block.h"

using namespace std::chrono_literals;

struct block_manager
{
	std::vector<block> blocks{ block{} };
	std::chrono::system_clock::time_point last = std::chrono::system_clock::now();

	auto display(sf::RenderWindow& w) -> void;
	auto update() -> void;
	auto hasHit(sf::CircleShape x) -> bool;
	auto checkCollision(const sf::CircleShape& circle, const sf::RectangleShape& rectangle) -> bool;

	bool dead = false;
};