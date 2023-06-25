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

#include "SFML/Graphics.hpp"

class Animation
{
public:
	enum class Mode : __int8
	{
		Finite,
		Infinity
	};

	void SetTexture(sf::Texture& Texture);
	void Play(sf::RenderWindow& Window);
	void SetStartRect(const sf::IntRect& Rect);
	void SetDirection(const sf::Vector2i& Direction);
	void SetDelayBetweenFrames(clock_t Delay);
	void SetMode(Mode NewMode);
	void SetFrameCount(__int8 Count);
	_NODISCARD Mode GetMode() const;
	_NODISCARD float GetTextureWidth() const;
	_NODISCARD float GetTextureHeight() const;
	void SetPosition(const sf::Vector2f& Position);

private:
	void Update(sf::RenderWindow& Window);

private:
	sf::Sprite Sprite_;
	Mode Mode_ = Mode::Finite;
	clock_t DelayBetweenFrames_ = 0;
	sf::Vector2i Direction_;
	sf::IntRect StartRect_;
	__int8 FramesCount_ = 0;
	__int8 CurrentFrame_ = 0;
	clock_t LastDraw_ = 0;
	bool IsEnd = false;
};