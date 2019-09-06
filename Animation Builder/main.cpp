#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "Application.h"
#include "AnimationListWin.h"
#include "FrameCollector.h"
int main()
{
	/*Application app;
	app.Run();
	delete &app;*/
	
	sf::Image img;
	img.loadFromFile("C:/Users/JacksonThe/source/repos/SpriteParser/SpriteParser/Mario.png");
	
	FrameCollector fc(img);
	std::vector<sf::IntRect> rects = fc.get();

	std::map<const char*, Animation> anims;
	anims["anim one"] = Animation(rects, .4,false);

	AnimationListWin win(anims, img);
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	window.setFramerateLimit(60);
	ImGui::SFML::Init(window);
	//
	sf::Clock deltaClock;
	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		ImGui::SFML::Update(window, deltaClock.restart());
		// clear the window with black color
		window.clear(sf::Color::Black);
		win.show();

		ImGui::ShowDemoWindow();
		ImGui::SFML::Render(window);
		// draw everything here...
		// window.draw(...);

		// end the current frame
		window.display();
	}
	ImGui::SFML::Shutdown();
	return 0;
}