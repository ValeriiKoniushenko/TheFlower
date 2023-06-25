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

#include "Button.h"

sf::Text& Button::GetText()
{
	return Text_;
}

const sf::Text& Button::GetText() const
{
	return Text_;
}

void Button::Update(sf::RenderWindow& Window)
{
	Widget::Update(Window);

	sf::Vector2f NewTextPosition = getPosition();
	switch (VerticalAlign_)
	{
		case TextAlign::Center:
			NewTextPosition.y += (getGlobalBounds().height - static_cast<float>(Text_.getCharacterSize())) / 2.f;
			break;
	}

	switch (HorizontalAlign_)
	{
		case TextAlign::Center:
			NewTextPosition.x += (getGlobalBounds().width - Text_.getGlobalBounds().width) / 2.f;
			break;
	}

	Text_.setPosition(NewTextPosition);
}

void Button::Draw(sf::RenderWindow& Window)
{
	Window.draw(*this);
	Window.draw(Text_);
}

void Button::SetTextVerticalAlign(Widget::TextAlign Align)
{
	VerticalAlign_ = Align;
}

void Button::SetTextHorizontalAlign(Widget::TextAlign Align)
{
	HorizontalAlign_ = Align;
}

Widget::TextAlign Button::GetTextVerticalAlign() const
{
	return VerticalAlign_;
}

Widget::TextAlign Button::GetTextHorizontalAlign() const
{
	return HorizontalAlign_;
}
