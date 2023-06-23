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

#include "Widget.h"

void Widget::SetName(const std::string& Name)
{
	Name_ = Name;
}

const std::string& Widget::GetName() const
{
	return Name_;
}

void Widget::SetOnMouseLeftClickEventCallback(std::function<void(const Widget&)> OnClick)
{
	OnLeftClick_ = OnClick;
}

void Widget::SetOnMouseRightClickEventCallback(std::function<void(const Widget&)> OnClick)
{
	OnRightClick_ = OnClick;
}

void Widget::Update(sf::RenderWindow& Window)
{
	const sf::Mouse Mouse;
	const sf::Vector2i MousePosition = Mouse.getPosition(Window);
	if (getGlobalBounds().contains(static_cast<float>(MousePosition.x), static_cast<float>(MousePosition.y)))
	{
		if (OnLeftClick_ && Mouse.isButtonPressed(sf::Mouse::Button::Left))
		{
			OnLeftClick_(*this);
		}

		if (OnRightClick_ && Mouse.isButtonPressed(sf::Mouse::Button::Right))
		{
			OnRightClick_(*this);
		}
	}
}