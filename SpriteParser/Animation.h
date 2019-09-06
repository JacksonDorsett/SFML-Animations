#pragma once
#include "Frame.h"
#include <vector>

class Animation
{

public:
	Animation();
	Animation(std::vector<Frame> animationFrames, bool isLooping = false);
	Animation(std::vector<sf::IntRect> rect, float duration, bool isLooping = false);
	virtual ~Animation();

	void Play(bool isLooping = false);
	void Stop();
	virtual void Update(float deltaTime);
	//resets the animation to the initial state
	virtual void Reset(bool isLooping = false);

	bool isLooping();
	void setLoop(bool isLooping);
private:
	std::vector<Frame> mFrames;
	bool mLooping;
	bool isPlaying;
	//internal Variables:
	int currentFrame; //tracks the current frame
	int timer;

	//private functions
	void updateFrame();
};

