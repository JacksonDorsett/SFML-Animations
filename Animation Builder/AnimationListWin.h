#pragma once
#include <map>

#include "SFML/Graphics/Image.hpp"
#include <string>
#include "imgui.h"
#include "SFML/Graphics/Texture.hpp"
#include "imgui-SFML.h"
#include "FrameCollector.h"
#include "SFML/Graphics/Sprite.hpp"
#include "Animation.h"

class AnimationListWin
{
	Animation MakeAnimation(std::vector < sf::IntRect> rects, float duration)
	{ 
		return Animation(rects, duration);
	};
public:
	AnimationListWin(std::map<const char*, Animation>, sf::Image& img);
	
	~AnimationListWin();

	void show();
private:
	std::map<const char*, Animation> mAnimations;
	sf::Image & rImage;
	bool mVisible;
	std::string mSelected;
	bool *mNewAnimWinVisible;
	std::vector<sf::IntRect> mFrames;
	sf::Texture mTexture;
	sf::Sprite mSprite;

	std::vector<sf::IntRect> animationStack;
};

