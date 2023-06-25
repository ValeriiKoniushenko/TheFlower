// MIT License
//
// Copyright (c) 2023 Valerii Koniushenko
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "Program.h"

#include "DefeatGameState.h"
#include "GameProcessGameState.h"
#include "GameStateBase.h"
#include "MainMenuGameState.h"

Program::Program() : Serializer("General.json")
{
}

void Program::Run()
{
	Deserialize();

	CreateWindow();

	GameState_ = std::make_unique<MainMenuGameState>();
	if (!GameState_)
	{
		return;	   // TODO: add logging
	}
	GameState_->Prepare();

	while (Window_.isOpen())
	{
		sf::Event Event{};
		if (Window_.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				Window_.close();
			}
		}
		LifeCycle();
	}
}

void Program::Serialize()
{
	AddToSerialize("Window-Width", Window_.getSize().x);
	AddToSerialize("Window-Height", Window_.getSize().y);

	Serializer::Serialize();
}

Program::~Program()
{
	Serialize();
}

void Program::CreateWindow()
{
	Window_.create(sf::VideoMode(GetFromSerializer<float>("Window-Width"), GetFromSerializer<float>("Window-Height")),
		GetFromSerializer<std::string>("Window-Title"));
}

void Program::LifeCycle()
{
	GameState_->Draw(Window_);
	GameState_->UpdateUi(Window_);

	ProcessCustomEvent();
}

void Program::ProcessCustomEvent()
{
	GameStateBase::CustomEvent Event = GameState_->PollEvent();
	if (Event != GameStateBase::CustomEvent::None)
	{
		GameState_.reset();

		if (Event == GameStateBase::CustomEvent::ContinueGame)
		{
			GameState_ = std::make_unique<GameProcessGameState>();
		}
		else if (Event == GameStateBase::CustomEvent::StartNewGame)
		{
			GameState_ = std::make_unique<GameProcessGameState>();
			if (GameProcessGameState* GameState = dynamic_cast<GameProcessGameState*>(GameState_.get()))
			{
				GameState->ResetUserData();
			}
		}
		else if (Event == GameStateBase::CustomEvent::GoToMainMenu)
		{
			GameState_ = std::make_unique<MainMenuGameState>();
		}
		else if (Event == GameStateBase::CustomEvent::DefeatMenu)
		{
			GameState_ = std::make_unique<DefeatGameState>();
		}

		GameState_->Prepare();
	}
}
