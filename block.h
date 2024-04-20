#pragma once

#include<SFML/Graphics.hpp>

struct block
{
	auto display(sf::RenderWindow& w) -> void;

	sf::Texture t;
	sf::Sprite s;
};