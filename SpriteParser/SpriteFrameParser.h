#pragma once
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Image.hpp"
class SpriteFrameParser
{
public:
	SpriteFrameParser(int iniX, int iniY, sf::Image &imgRef);
	~SpriteFrameParser();
	
	


	//getter
	//used for retrieving the final spritebox and returning it to the parser
	sf::IntRect getSpriteBox();

private:
	sf::IntRect mSpriteBox;
	sf::Image &ImageReference;

	void runAlgorithm();

	//private functions
	//expansion functions: Expands the rectangle in all four directions
	void expandUp();
	void expandDown();
	void expandLeft();
	void expandRight();
	//scan functions: checks if it is valid to expand in a given direction
	bool scanUp();
	bool scanDown();
	bool scanLeft();
	bool scanRight();


	bool isExpandable();
};

