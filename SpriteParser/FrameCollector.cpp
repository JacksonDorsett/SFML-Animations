#include "FrameCollector.h"
#include "SpriteFrameParser.h"


FrameCollector::FrameCollector(const char * imagePath)
{
	if (mSpritesheetImg.loadFromFile(imagePath))
	{
		CollectFrames();
	}
	
}


FrameCollector::FrameCollector(sf::Image &imgRef) : mSpritesheetImg(imgRef)
{
	CollectFrames();
}

FrameCollector::~FrameCollector()
{

}

void FrameCollector::CollectFrames()
{
	for (int y = 0; y < mSpritesheetImg.getSize().y; y += 4)
	{
		for (int x = 0; x < mSpritesheetImg.getSize().x; x += 4)
		{
			if (mSpritesheetImg.getPixel(x, y).a && !isCollected(x, y, x))
			{
				frameList.push_back(SpriteFrameParser(x,y, mSpritesheetImg).getSpriteBox());
			}
		}
	}
	//filter bad frames
	CleanupFrames();
}
void FrameCollector::CleanupFrames()
{
	
	for (int i = 0; i < frameList.size(); i++)
	{
		if (frameList[i].width < 4 || frameList[i].height < 4)
		{
			frameList.erase(frameList.begin() + i);
			--i;
		}
	}
	
}

bool FrameCollector::isCollected(unsigned int x, unsigned int y, int &scanPosition)
{
	for (int i = 0; i < frameList.size(); i++)
	{
		if (frameList[i].contains(x, y))
		{	
			scanPosition += frameList[i].width;
			return true;
		}
	}
	return false;
}
