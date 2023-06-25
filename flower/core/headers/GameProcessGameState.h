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
#include "FlowerPool.h"
#include "GameStateBase.h"
#include "Map.h"
#include "Player.h"
#include "SFML/Audio.hpp"
#include "Snake.h"
#include "SnakeConfig.h"
#include "SnakePool.h"

#include <random>

class GameProcessGameState : public GameStateBase
{
public:
	void Prepare() override;
	void Draw(sf::RenderWindow& Window) override;
	void UpdateUi(sf::RenderWindow& Window) override;

	static void ResetUserData();

private:
	bool HaveToPlant(sf::RenderWindow& Window);
	void PlantAt(const sf::Vector2i& PositionAtWindow, sf::RenderWindow& Window);
	void SpawnFlowerAt(const sf::Vector2i& PositionAtWindow);
	void SpawnSnakeAtRandomPosition(sf::RenderWindow& Window);

	void AddMoneyEveryXSeconds();
	void UpdateSnakes(sf::RenderWindow& Window);
	void DecreaseSnakeLengthIfClicked(sf::RenderWindow& Window);
	void SnakeAutoGrowth();
	void SpawnNewSnakeEveryXSeconds(sf::RenderWindow& Window);
	void CheckInteractWithFlower();
	void DecreaseSpawnSpeedEveryXSeconds();
	void SpeedUpAllSnakes();
	void SpeedDownAllSnakes();
	void WorkingWithSpeedUpEffect();

	void CheckForDefeat();

private:
	sf::Texture MapBackgroundTexture_;
	sf::Texture FlowerTexture_;
	sf::Texture SnakeTexture_;

	// TODO: move to a common widget
	sf::Texture CoinTexture_;
	sf::Sprite Coin_;
	sf::Text CoinCount_;

	SnakeConfig SnakeConfig_;
	SnakePool SnakePool_;

	FlowerConfig FlowerConfig_;
	clock_t LastIncome = 0;

	FlowerPool FlowerPool_;
	Player Player_;
	Map Map_;

	sf::Music BackgroundMusic_;
	sf::SoundBuffer PlantSoundBuffer_;
	sf::SoundBuffer SnakeSpawnSoundBuffer_;
	sf::Sound PlantSound_;
	sf::Sound SnakeSpawnSound_;

	std::default_random_engine generator;
};