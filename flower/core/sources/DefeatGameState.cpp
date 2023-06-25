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

#include "DefeatGameState.h"

void DefeatGameState::Prepare()
{
	GameStateBase::Prepare();

	DefeatText_.setFont(MainFont_);
	DefeatText_.setCharacterSize(48);
	DefeatText_.setString("DEFEAT");
	DefeatText_.setLetterSpacing(5.f);

	BackgroundTexture_.loadFromFile("assets/images/main-menu-background.jpg");	  // TODO: add checking -> out to the log
	ButtonTexture_.loadFromFile("assets/images/button.png");					  // TODO: add checking -> out to the log

	GoToMainMenuButton_.setTexture(ButtonTexture_);
	GoToMainMenuButton_.setScale(.5f, .5f);
	GoToMainMenuButton_.GetText().setFont(MainFont_);
	GoToMainMenuButton_.GetText().setString("Go to main menu");
	GoToMainMenuButton_.GetText().setFillColor(sf::Color::Black);
	GoToMainMenuButton_.GetText().setCharacterSize(24);
	GoToMainMenuButton_.SetOnMouseLeftClickEventCallback([this](const Widget&) { CustomEvent_ = CustomEvent::GoToMainMenu; });

	BackgroundCanvas_.setTexture(BackgroundTexture_);
}

void DefeatGameState::Draw(sf::RenderWindow& Window)
{
	Window.clear(sf::Color::White);

	Window.draw(BackgroundCanvas_);
	Window.draw(DefeatText_);
	GoToMainMenuButton_.Draw(Window);

	Window.display();
}

void DefeatGameState::UpdateUi(sf::RenderWindow& Window)
{
	// TODO: move to the button's align-settings
	// setting position by center of the window
	sf::Vector2f NewButtonPosition(static_cast<float>(Window.getSize().x), static_cast<float>(Window.getSize().y));
	NewButtonPosition.x -= GoToMainMenuButton_.getGlobalBounds().width;
	NewButtonPosition.y -= GoToMainMenuButton_.getGlobalBounds().height;
	NewButtonPosition /= 2.f;

	GoToMainMenuButton_.setPosition(NewButtonPosition);
	GoToMainMenuButton_.Update(Window);

	// TODO: move to the text's align-settings
	sf::Vector2f NewTextPosition(static_cast<float>(Window.getSize().x), static_cast<float>(Window.getSize().y));
	NewTextPosition.x -= DefeatText_.getGlobalBounds().width;
	NewTextPosition.y -= DefeatText_.getGlobalBounds().height;
	NewTextPosition /= 2.f;
	DefeatText_.setPosition(NewTextPosition);
}
