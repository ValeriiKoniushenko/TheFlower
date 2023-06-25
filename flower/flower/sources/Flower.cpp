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

#include "Flower.h"

sf::Sprite& Flower::GetMainSprite()
{
	return MainSprite_;
}

const sf::Sprite& Flower::GetMainSprite() const
{
	return MainSprite_;
}

void Flower::Draw(sf::RenderWindow& Window)
{
	Window.draw(MainSprite_);
	ClockAnimation_.Play(Window);
}

boost::property_tree::ptree Flower::ToJSON() const
{
	boost::property_tree::ptree PTree;
	PTree.put("x", MainSprite_.getPosition().x);
	PTree.put("y", MainSprite_.getPosition().y);

	return PTree;
}

void Flower::SetPosition(const sf::Vector2f& Position)
{
	MainSprite_.setPosition(Position);
}

void Flower::SetClockTexture(sf::Texture& Texture)
{
	ClockAnimation_.SetTexture(Texture);
}

void Flower::AlignClock(float OffsetX, float OffsetY)
{
	sf::Vector2f NewPosition = MainSprite_.getPosition();
	NewPosition.x += static_cast<float>(MainSprite_.getGlobalBounds().width - ClockAnimation_.GetTextureWidth()) / 2.f + OffsetX;
	NewPosition.y += -static_cast<float>(ClockAnimation_.GetTextureHeight()) + OffsetY;

	ClockAnimation_.SetPosition(NewPosition);
}

void Flower::Prepare()
{
	ClockAnimation_.SetMode(Animation::Mode::Infinity);
	ClockAnimation_.SetFrameCount(18);
	ClockAnimation_.SetStartRect({0, 0, 32, 32});
	ClockAnimation_.SetDelayBetweenFrames(166);
	ClockAnimation_.SetDirection({32, 0});
}
