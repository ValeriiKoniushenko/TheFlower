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

#include "GameProcessGameState.h"

void GameProcessGameState::Prepare()
{
	GameStateBase::Prepare();

	FlowerConfig_.Deserialize();
	Player_.Deserialize();
	Map_.Deserialize();

	MapBackgroundTexture_.loadFromFile("assets/images/grass.jpg");
	MapBackgroundTexture_.setRepeated(true);

	CoinTexture_.loadFromFile("assets/images/coin.png");
	Coin_.setTexture(CoinTexture_);
	Coin_.setScale(0.05f, 0.05f);
	Coin_.setPosition(20.f, 20.f);

	CoinCount_.setFont(MainFont_);
	CoinCount_.setFillColor(sf::Color::White);
	CoinCount_.setString(std::to_string(Player_.GetMoney()) + "$");
	CoinCount_.setCharacterSize(36);
	CoinCount_.setPosition(120.f, 35.f);	// TODO: make auto align

	FlowerTexture_.loadFromFile("assets/images/flower.png");

	Map_.GetMapBackground().setTexture(MapBackgroundTexture_);
}

void GameProcessGameState::Draw(sf::RenderWindow& Window)
{
	Window.clear(sf::Color::White);

	Map_.Draw(Window);
	for (Flower& Flower_ : FlowerPool_)
	{
		Flower_.Draw(Window);
	}
	Window.draw(Coin_);
	Window.draw(CoinCount_);

	Window.display();
}

void GameProcessGameState::UpdateUi(sf::RenderWindow& Window)
{
	if (HaveToPlant(Window))
	{
		sf::Mouse Mouse;
		PlantAt(Mouse.getPosition(Window));
	}

	if (clock() - LastIncome > FlowerConfig_.IncomeFrequency)	 // TODO: change to Timer
	{
		Player_.AddMoney(FlowerPool_.Size() * FlowerConfig_.IncomeAmount);
		CoinCount_.setString(
			std::to_string(Player_.GetMoney()) + "$");	  // TODO: create Delegate system and change it using a delegate
		LastIncome = clock();
	}
}

bool GameProcessGameState::HaveToPlant(sf::RenderWindow& Window)
{
	sf::Mouse Mouse;
	sf::Vector2i MousePosition = Mouse.getPosition(Window);
	if (MousePosition.x > 0 && MousePosition.y > 0 && MousePosition.x < Window.getSize().x && MousePosition.y < Window.getSize().y)
	{
		if (Mouse.isButtonPressed(sf::Mouse::Button::Right))	// TODO: move\create to InputMapping : public Serializer
		{
			return true;
		}
	}

	return false;
}

void GameProcessGameState::PlantAt(const sf::Vector2i& PositionAtWindow)
{
	if (clock() - FlowerConfig_.LastPlant >= FlowerConfig_.PlantFrequency)	  // TODO: added timer system
	{
		if (Player_.CanApproveTransaction(FlowerConfig_.PlantCosts))
		{
			Flower Flower_;
			Flower_.GetMainSprite().setTexture(FlowerTexture_);
			Flower_.SetPosition({static_cast<float>(PositionAtWindow.x) - Flower_.GetMainSprite().getTextureRect().width / 2.f,
				static_cast<float>(PositionAtWindow.y) - Flower_.GetMainSprite().getTextureRect().height / 2.f});

			FlowerPool_.Push(Flower_);
			Player_.AddMoney(-FlowerConfig_.PlantCosts);
			CoinCount_.setString(
				std::to_string(Player_.GetMoney()) + "$");	  // TODO: create Delegate system and change it using a delegate
		}
		FlowerConfig_.LastPlant = clock();
	}
}
