#include "AnimationListWin.h"
//#include <iterator>


AnimationListWin::AnimationListWin(std::map<const char*, Animation> anims, sf::Image& img) : rImage(img)
{
	mAnimations = anims;
	
	this->mNewAnimWinVisible = new bool(false);
	mFrames = FrameCollector(rImage).get();
	mTexture.loadFromImage(rImage);
	mSprite.setTexture(mTexture);
}


AnimationListWin::~AnimationListWin()
{
}

void AnimationListWin::show()
{
	if(ImGui::Begin("Animation List", &mVisible))
	{
		if (ImGui::Button("New Animation"))
		{
			*mNewAnimWinVisible = true;
		}

		if (ImGui::BeginCombo("", "Selected Animation"))
		{
			std::map<const char*, Animation>::iterator it = mAnimations.begin();
			for (std::pair<const char *, Animation> element : mAnimations)
			{
				if (ImGui::Selectable(element.first, true))
				{
					mSelected = element.first;
				}
			}
			
			ImGui::EndCombo();
		}
		
	}
	ImGui::End();
	
	if (*mNewAnimWinVisible)
	{
		if (ImGui::Begin("New Animation", NULL, ImGuiWindowFlags_NoCollapse ))
		{

			for (int i = 0; i < mFrames.size(); i++)
			{
				ImGui::PushID(i);
				if (i % 4 != 0) ImGui::SameLine();
				mSprite.setTextureRect(mFrames[i]);
				if (ImGui::ImageButton(mSprite))
				{
					animationStack.push_back(mFrames[i]);
				}

				ImGui::PopID();
			}
			


		}
		ImGui::End();
		
		if (ImGui::Begin("Animation", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize))
		{
			static char str[16] = {};
			static float duration = 0;
			ImGui::InputText("Animation Name: ", &str[0], IM_ARRAYSIZE(str));
			ImGui::InputFloat("Frame Duration", &duration);
			ImGui::NewLine();
			for (int i = 0; i < animationStack.size(); i++)
			{
				mSprite.setTextureRect(animationStack[i]);

				ImGui::SameLine();
				if(ImGui::ImageButton(mSprite))
				{

				}
				ImGui::NewLine();
				if (ImGui::Button("Create Animation"))
				{
					if (duration > 0 && strlen(str))
					{
						//Animation(animationStack, duration);
						mAnimations.insert(std::make_pair(str,MakeAnimation(animationStack,duration)));
						animationStack.clear();
						*mNewAnimWinVisible = false;
					}
				}
			}
		}
		ImGui::End();
	}
	
}

