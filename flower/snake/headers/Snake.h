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

#include "SceneObject.h"

#include <random>

class Snake : public SceneObject
{
public:
	explicit Snake(__int32 StartSize = 2);
	~Snake() override = default;
	Snake(const Snake&) = default;
	Snake(Snake&&) = default;
	Snake& operator=(const Snake&) = default;
	Snake& operator=(Snake&&) = default;

	void Draw(sf::RenderWindow& Window) override;
	_NODISCARD boost::property_tree::ptree ToJSON() const override;

	void SetTexture(sf::Texture& Texture);
	void SetPosition(sf::Vector2f NewPosition);

	_NODISCARD std::size_t Size() const;

	void Update(sf::Window& Window);
	bool Contains(sf::Vector2f Point) const;

	inline static constexpr float GapBetweenNodes = 50;	   // px

	void Bobtail();
	void Increase(__int32 MaxSize);
	void SetSpeedMultiplier(float Multiplier);

	_NODISCARD bool InteractWithSprite(const sf::Sprite& Sprite) const;

private:
	sf::Texture* TextureP_ = nullptr;
	std::vector<sf::Sprite> Sprites_;
	sf::Vector2f MoveToPoint;
	sf::Vector2f Direction;
	clock_t LastUpdate = 0;
	clock_t UpdateFrequency = 8;	// 1000ms / 120FPS = 8
	std::default_random_engine generator;
	float Speed = 1.f;
};
