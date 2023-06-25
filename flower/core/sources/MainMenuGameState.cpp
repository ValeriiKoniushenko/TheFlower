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

#include "MainMenuGameState.h"

void MainMenuGameState::Prepare()
{
	GameStateBase::Prepare();

	BackgroundTexture_.loadFromFile("assets/images/main-menu-background.jpg");	  // TODO: add checking -> out to the log
	ButtonTexture_.loadFromFile("assets/images/button.png");					  // TODO: add checking -> out to the log

	StartButton_.setPosition(100.f, 100.f);
	StartButton_.setTexture(ButtonTexture_);
	StartButton_.setScale(.5f, .5f);
	StartButton_.GetText().setFont(MainFont_);
	StartButton_.GetText().setString("New game");
	StartButton_.GetText().setFillColor(sf::Color::Black);
	StartButton_.GetText().setCharacterSize(24);
	StartButton_.SetOnMouseLeftClickEventCallback([this](const Widget&) { CustomEvent_ = CustomEvent::StartNewGame; });

	ContinueButton_.setPosition(100.f, 200.f);
	ContinueButton_.setTexture(ButtonTexture_);
	ContinueButton_.setScale(.5f, .5f);
	ContinueButton_.GetText().setFont(MainFont_);
	ContinueButton_.GetText().setString("Continue");
	ContinueButton_.GetText().setFillColor(sf::Color::Black);
	ContinueButton_.GetText().setCharacterSize(24);
	ContinueButton_.SetOnMouseLeftClickEventCallback([this](const Widget&) { CustomEvent_ = CustomEvent::ContinueGame; });

	BackgroundCanvas_.setTexture(BackgroundTexture_);
}

void MainMenuGameState::Draw(sf::RenderWindow& Window)
{
	Window.clear(sf::Color::White);

	Window.draw(BackgroundCanvas_);
	StartButton_.Draw(Window);
	ContinueButton_.Draw(Window);

	Window.display();
}

void MainMenuGameState::UpdateUi(sf::RenderWindow& Window)
{
	StartButton_.Update(Window);
	ContinueButton_.Update(Window);
}
