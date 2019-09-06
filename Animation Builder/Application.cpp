#include "Application.h"
#include <assert.h>
#include <imgui.h>
Application* Application::s_Instance = nullptr;

Application::Application()
{
	//initializes App Window
	assert(!s_Instance);
	s_Instance = this;
	this->isRunning = true;

	mWindow = std::unique_ptr<Window>(new Window);
	

}


Application::~Application()
{
}

void Application::Run()
{
	while (isRunning)
	{
		mWindow->HandleEvents();
		
		mWindow->OnUpdate();
		//update layers
		ImGui::ShowDemoWindow();
		//animation selection window

		if (ImGui::BeginCombo("", "Selected Animation"))
		{
			if (ImGui::Selectable("Anim 1", true))
			{ 
				  
			}
			ImGui::EndCombo();
		}

		//end updates
		mWindow->Render();
		
	}

	
}