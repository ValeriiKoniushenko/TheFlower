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

#pragma once

#include "Flower.h"
#include "FlowerConfig.h"
#include "GameStateBase.h"
#include "Map.h"
#include "Player.h"

class GameProcessGameState : public GameStateBase
{
public:
	void Prepare() override;
	void Draw(sf::RenderWindow& Window) override;
	void UpdateUi(sf::RenderWindow& Window) override;

private:
	bool HaveToPlant(sf::RenderWindow& Window);
	void PlantAt(const sf::Vector2i& PositionAtWindow);

private:
	sf::Texture MapBackgroundTexture_;
	sf::Texture FlowerTexture_;

	// TODO: move to a common widget
	sf::Texture CoinTexture_;
	sf::Sprite Coin_;
	sf::Text CoinCount_;

	FlowerConfig FlowerConfig_;
	clock_t LastIncome = 0;

	std::vector<Flower> Flowers_;
	Player Player_;
	Map Map_;
};