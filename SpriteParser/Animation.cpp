#include "Animation.h"
#ifdef _DEBUG
#include <iostream>
#define LOG(x) std::cout << x << std::endl;
#elif !_DEBUG
#define LOG(x) //
#endif

Animation::Animation(std::vector<Frame> animationFrames, bool isLooping) : mFrames(animationFrames), mLooping(isLooping),isPlaying(true)
{
	currentFrame = 0;
	timer = 0;
}
Animation::Animation(std::vector<sf::IntRect> rect, float duration, bool isLooping) : mLooping(isLooping), isPlaying(true)
{
	
	currentFrame = 0;
	timer = 0;
	for (int i = 0; i < rect.size(); i++)
	{
		mFrames.push_back(Frame(rect[0], duration));
	}
}

Animation::~Animation()
{
}

void Animation::Update(float deltaTime)
{
	if (isPlaying) {
		timer += deltaTime;
		updateFrame();
	}

}
//resets the animation to the initial state
void Animation::Reset(bool isLooping)
{

}

bool Animation::isLooping()
{
	return mLooping;
}
void Animation::setLoop(bool isLooping)
{
	mLooping = isLooping;
}

void Animation::updateFrame() {
	if (timer > mFrames[currentFrame].duration)
	{
		timer = 0;
		++currentFrame;
		LOG(currentFrame);
		if (currentFrame == mFrames.size())
		{
			if (mLooping)
			{
				currentFrame = 0;
			}
			else
			{
				isPlaying = false;
			}
		}
	}
}
void Animation::Play(bool isLooping = false)
{
	mLooping = isLooping;
	isPlaying = true;
}
void Animation::Stop()
{
	isPlaying = false;
}