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
	Snake(__int32 StartSize = 2);
	~Snake() = default;
	Snake(const Snake&) = default;
	Snake(Snake&&) = default;
	Snake& operator=(const Snake&) = default;
	Snake& operator=(Snake&&) = default;

	void Draw(sf::RenderWindow& Window) override;
	boost::property_tree::ptree ToJSON() const override;

	void SetTexture(sf::Texture& Texture);
	void SetPosition(sf::Vector2f NewPosition);

	void Update(sf::Window& Window);

	inline static constexpr float GapBetweenNodes = 50;	   // px
private:
	bool IsNearlyToPoint(const sf::Vector2f& P1, const sf::Vector2f& P2) const;
	sf::Vector2f Normalize(const sf::Vector2f& source) const;

	template <typename T>
	T Vector2Distance(const sf::Vector2<T>& A, const sf::Vector2<T>& B)
	{
		return (fabs(sqrt(((A.x - B.x) * (A.x - B.x)) + ((A.y - B.y) * (A.y - B.y)))));
	}

private:
	sf::Texture* TextureP_ = nullptr;
	std::vector<sf::Sprite> Sprites_;
	sf::Vector2f MoveToPoint;
	sf::Vector2f Direction;
	clock_t LastUpdate = 0;
	clock_t UpdateFrequency = 8;	// 1000ms / 120FPS = 8
	std::default_random_engine generator;
};
