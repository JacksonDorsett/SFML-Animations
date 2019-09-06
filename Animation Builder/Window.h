#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include "imgui-SFML.h"
#include "imgui.h"
class Window
{
public:
	Window();
	~Window();

	void HandleEvents();
	void OnUpdate();
	void Render();

	sf::RenderWindow & getContext() { return mWindow; };
	
private:
	sf::RenderWindow mWindow;
	sf::Clock internalClock;
	void initWindow();
	void initImGui();
	
};

