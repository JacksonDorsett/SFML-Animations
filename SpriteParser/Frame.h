#pragma once
#include "SFML/Graphics/Rect.hpp"
struct Frame
{
	Frame(sf::IntRect rect, double duration) : frame(rect), duration(duration) {};
	double duration;
	sf::IntRect frame;
};