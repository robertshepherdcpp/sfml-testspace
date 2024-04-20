#pragma once

#include<SFML/Graphics.hpp>

struct Bird
{
	Bird();

	auto display(sf::RenderWindow& w) -> void;
	auto flap() -> void;
	auto update() -> void;

	sf::CircleShape bird;

	float gravity = 0.7;
	float lift = -12;
	float velocity = 0;
	float y = 300;
	float x = 200;

	static constexpr float height = 600;
};