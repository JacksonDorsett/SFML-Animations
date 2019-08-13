#include "SpriteFrameParser.h"



SpriteFrameParser::SpriteFrameParser(int iniX, int iniY, sf::Image &imgRef):mSpriteBox(iniX,iniY,0,0),ImageReference(imgRef)
{
	runAlgorithm();
}


SpriteFrameParser::~SpriteFrameParser()
{
}

sf::IntRect SpriteFrameParser::getSpriteBox()
{
	return mSpriteBox;
}

//private functions

void SpriteFrameParser::runAlgorithm()
{
	while (isExpandable())
	{
		while (scanUp())
		{
			expandUp();
		}
		while (scanDown())
		{
			expandDown();
		}
		while (scanLeft())
		{
			expandLeft();
		}
		while (scanRight())
		{
			expandRight();
		}
	}
}

void SpriteFrameParser::expandUp()
{
	--mSpriteBox.top;
	/*++mSpriteBox.height;*/
	expandDown();
}
void SpriteFrameParser::expandDown()
{
	++mSpriteBox.height;
}
void SpriteFrameParser::expandLeft()
{
	--mSpriteBox.left;
	expandRight();
}
void SpriteFrameParser::expandRight()
{
	++mSpriteBox.width;
}


bool SpriteFrameParser::scanUp()
{
	sf::IntRect rect = mSpriteBox;
	bool ret = false;
	int y = --rect.top;
	if (y >= 0)
	{
		for (int i = 0; i <= rect.width&&ret == false; i++)
		{
			int j = ImageReference.getPixel(rect.left + i, y).a;
			if (ImageReference.getPixel(rect.left + i, y).a)
			{
				ret = true;
			}
		}
	}
	return ret;
}
bool SpriteFrameParser::scanDown()
{
	sf::IntRect rect = mSpriteBox;
	bool ret = false;
	int y = (rect.top + rect.height++);
	if (y < ImageReference.getSize().y)
	{
		for (int i = 0; i <= rect.width&&ret == false; i++)
		{
			
			if (ImageReference.getPixel(rect.left + i, y).a)
			{
				ret = true;
			}
		}
	}
	return ret;
}

//vetical scans;
bool SpriteFrameParser::scanLeft()
{	
	sf::IntRect rect = mSpriteBox;

	bool ret = false;
	int x = --rect.left;
	if ( x >= 0)
	{
		for (int i = 0; i < rect.height && ret == false; i++)
		{
			if (ImageReference.getPixel(x, rect.top + i).a)
			{
				ret = true;
			}
		}
	}
		return ret;
}
bool SpriteFrameParser::scanRight()
{
	sf::IntRect rect = mSpriteBox;

	bool ret = false;
	int x = (rect.left + ++rect.width);
	if (x < ImageReference.getSize().x)
	{
		for (int i = 0; i < rect.height && ret == false; i++)
		{
			if (ImageReference.getPixel(x, rect.top + i).a)
			{
				ret = true;
			}
		}
	}
	return ret;
}

bool SpriteFrameParser::isExpandable()
{
	return scanUp() || scanDown() || scanLeft() || scanRight();
}
