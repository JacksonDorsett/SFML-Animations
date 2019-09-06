#pragma once
#include <memory>
#include "Window.h"

class Application
{
public:
	Application();
	~Application();

	void Run();


	Window & getWindow() { return *mWindow; };
private:
	
	std::unique_ptr<Window> mWindow;

	bool isRunning;

private:
	static Application* s_Instance;
	
};

Application* createApplication();
