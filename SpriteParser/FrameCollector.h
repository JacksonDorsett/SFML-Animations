#pragma once
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Image.hpp"
#include <vector>
/*
TO-DO:
1) allow for checking for entities near the frames that might be attched.
2) support non-png formats
*/


//retrieves a list of sprite frames from the image file by sweeping through the image
class FrameCollector
{
public:
	FrameCollector(const char * imagePath);
	
	/*
	preconditions: image must be successfully opened from file
	*/
	FrameCollector(sf::Image &imgRef);
	~FrameCollector();

	std::vector<sf::IntRect> get() { return frameList; };
private:
	sf::Image mSpritesheetImg;
	std::vector<sf::IntRect> frameList;

	//private functions
	void CollectFrames();
	void CleanupFrames();
	///conditionals when checking pixel
	bool isCollected(unsigned int x, unsigned int y, int &scanPosition);

};

