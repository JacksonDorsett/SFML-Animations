#include "SFML/Graphics.hpp"
#include "SpriteFrameParser.h"
#include "FrameCollector.h"
#include "Animation.h"
#include <iostream>
int main()
{


	sf::Image img;
	img.loadFromFile("trump.png");
	FrameCollector frameColl(img);
	sizeof(frameColl);
	std::vector<sf::IntRect> frames = frameColl.get();
	Animation anim(frames, .5);
	int currentFrame = 0;
	sf::Texture text;
	
	text.loadFromImage(img);
	sf::Sprite sprt(text, frames[0]);
	//sprt.setScale(,20);

	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	float dTime = 0;
	float tTime = 0;
	sf::Clock clock;
	// run the program as long as the window is open
	while (window.isOpen())
	{
		
		
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		tTime += dTime;
		if (tTime >= .2)
		{
			tTime -= .2;
			currentFrame = (currentFrame + 1) % frames.size();
			sprt.setTextureRect(frames[currentFrame]);
		}

		window.clear();
		anim.Update(dTime);
		// draw everything here...
		 window.draw(sprt);

		// end the current frame
		window.display();
		dTime = clock.restart().asSeconds();
	}

	return 0;
}