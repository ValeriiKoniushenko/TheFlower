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

#include "Snake.h"

#include "UMath.h"

#include <iostream>

Snake::Snake(__int32 StartSize) : generator(time(nullptr))
{
	Sprites_.resize(StartSize);
}

void Snake::Draw(sf::RenderWindow& Window)
{
	for (sf::Sprite& Sprite : Sprites_)
	{
		Window.draw(Sprite);
	}
}

void Snake::SetTexture(sf::Texture& Texture)
{
	TextureP_ = &Texture;
	for (sf::Sprite& Sprite : Sprites_)
	{
		Sprite.setTexture(*TextureP_);
	}
}

boost::property_tree::ptree Snake::ToJSON() const
{
	boost::property_tree::ptree PTree;
	if (Sprites_.begin() != Sprites_.end())
	{
		PTree.put("x", Sprites_.begin()->getPosition().x);
		PTree.put("y", Sprites_.begin()->getPosition().y);
	}

	return PTree;
}

void Snake::SetPosition(sf::Vector2f NewPosition)
{
	sf::Vector2f LastPosition = NewPosition;
	for (sf::Sprite& Sprite : Sprites_)
	{
		Sprite.setPosition(LastPosition);
		LastPosition.x += GapBetweenNodes;
	}
}

void Snake::Update(sf::Window& Window)
{
	if (Size() == 0)
	{
		return;
	}

	if (clock() - LastUpdate < UpdateFrequency)
	{
		return;
	}

	if (!Sprites_.empty())
	{
		if (MoveToPoint.x == 0 && MoveToPoint.y == 0 || Math::IsNearlyToPoint(MoveToPoint, Sprites_.begin()->getPosition()))
		{
			std::uniform_real_distribution<float> distributionByWidth(0.f, static_cast<float>(Window.getSize().x));
			std::uniform_real_distribution<float> distributionByHeight(0.f, static_cast<float>(Window.getSize().y));

			MoveToPoint.x = distributionByWidth(generator);
			MoveToPoint.y = distributionByHeight(generator);
			Direction = Math::Normalize((MoveToPoint - Sprites_.begin()->getPosition()));
		}
	}

	for (auto It = Sprites_.begin(); It != Sprites_.end(); ++It)
	{
		if (It == Sprites_.begin())
		{
			It->move(Direction * Speed);
		}
		else
		{
			auto TempDirection = Math::Normalize((It - 1)->getPosition() - It->getPosition());
			if (Math::Vector2Distance(It->getPosition(), (It - 1)->getPosition()) >= GapBetweenNodes)
			{
				It->move(TempDirection * Speed);
			}
		}
	}

	LastUpdate = clock();
}

void Snake::Bobtail()
{
	Sprites_.pop_back();
}

std::size_t Snake::Size() const
{
	return Sprites_.size();
}

bool Snake::Contains(sf::Vector2f Point) const
{
	return std::any_of(
		Sprites_.cbegin(), Sprites_.cend(), [&](const sf::Sprite& Sprite) { return Sprite.getGlobalBounds().contains(Point); });
}

void Snake::Increase(__int32 MaxSize)
{
	if (Sprites_.size() < MaxSize)
	{
		Sprites_.resize(Sprites_.size() + 1);
		if (Sprites_.size() >= 1 && TextureP_)
		{
			(Sprites_.end() - 1)->setTexture(*TextureP_);
		}
		if (Sprites_.size() >= 2)
		{
			(Sprites_.end() - 1)->setPosition((Sprites_.end() - 2)->getPosition());
		}
	}
}

bool Snake::InteractWithSprite(const sf::Sprite& Sprite) const
{
	return std::any_of(Sprites_.cbegin(), Sprites_.cend(),
		[&](const sf::Sprite& S) { return S.getGlobalBounds().intersects(Sprite.getGlobalBounds()); });
}

void Snake::SetSpeedMultiplier(float Multiplier)
{
	Speed = Multiplier;
}
