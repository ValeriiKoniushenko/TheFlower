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

#include "Animation.h"

#include <iostream>

Animation::Mode Animation::GetMode() const
{
	return Mode_;
}

void Animation::SetMode(Animation::Mode NewMode)
{
	Mode_ = NewMode;
}

void Animation::SetDelayBetweenFrames(clock_t Delay)
{
	DelayBetweenFrames_ = Delay;
}

void Animation::SetDirection(const sf::Vector2i& Direction)
{
	Direction_ = Direction;
}

void Animation::SetStartRect(const sf::IntRect& Rect)
{
	StartRect_ = Rect;
}

void Animation::Play(sf::RenderWindow& Window)
{
	if (!IsEnd && (LastDraw_ == 0 || clock() - LastDraw_ >= DelayBetweenFrames_))	 // TODO: replace to a class Timer(and impl it)
	{
		sf::IntRect TempRect = StartRect_;
		TempRect.left += Direction_.x * CurrentFrame_;
		TempRect.top += Direction_.y * CurrentFrame_;

		Sprite_.setTextureRect(TempRect);

		if (Mode_ == Mode::Infinity)
		{
			++CurrentFrame_;
			if (CurrentFrame_ >= FramesCount_)
			{
				CurrentFrame_ = 0;
			}
		}
		else if (Mode_ == Mode::Finite)
		{
			if (CurrentFrame_ < FramesCount_)
			{
				++CurrentFrame_;
			}

			if (CurrentFrame_ >= FramesCount_)
			{
				IsEnd = true;
				--CurrentFrame_;
			}
		}

		LastDraw_ = clock();
	}

	Window.draw(Sprite_);
	Update(Window);
}

void Animation::Update(sf::RenderWindow& Window)
{
}

void Animation::SetTexture(sf::Texture& Texture)
{
	Sprite_.setTexture(Texture);
}

void Animation::SetFrameCount(__int8 Count)
{
	FramesCount_ = Count;
}

void Animation::SetPosition(const sf::Vector2f& Position)
{
	Sprite_.setPosition(Position);
}

float Animation::GetTextureWidth() const
{
	return StartRect_.width;
}

float Animation::GetTextureHeight() const
{
	return StartRect_.height;
}
