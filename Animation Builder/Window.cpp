#include "Window.h"
#include "SFML/Window/Event.hpp"
#include "AnimationListWin.h"

Window::Window()
{
	initWindow();
	initImGui();
}


Window::~Window()
{
	ImGui::SFML::Shutdown();
}

void Window::OnUpdate()
{
	
	//process events
	
	ImGui::SFML::Update(mWindow, internalClock.restart());

	

	
}
void Window::Render()
{
	mWindow.clear();

	ImGui::SFML::Render(mWindow);

	mWindow.display();
}

void Window::HandleEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		ImGui::SFML::ProcessEvent(event);
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}
void Window::initWindow()
{
	mWindow.create(sf::VideoMode(800, 600), "Animation Builder");
	mWindow.setFramerateLimit(60);
	ImGui::SFML::Init(mWindow);
	//mDeltaClock.restart();
}

void Window::initImGui()
{
	mWindow.resetGLStates();
	
}