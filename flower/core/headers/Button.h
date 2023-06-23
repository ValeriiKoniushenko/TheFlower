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

#include "Widget.h"

// TODO: Move it to UI lib

class Button : public Widget
{
public:
	~Button() override = default;

	_NODISCARD sf::Text& GetText();
	_NODISCARD const sf::Text& GetText() const;
	void Update(sf::RenderWindow& Window) override;

	void Draw(sf::RenderWindow& window);
	void SetTextVerticalAlign(TextAlign Align);
	_NODISCARD TextAlign GetTextVerticalAlign() const;

	void SetTextHorizontalAlign(TextAlign Align);
	_NODISCARD TextAlign GetTextHorizontalAlign() const;

private:
	sf::Text Text_;
	TextAlign VerticalAlign_ = TextAlign::Center;
	TextAlign HorizontalAlign_ = TextAlign::Center;
};