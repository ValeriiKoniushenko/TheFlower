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

#include <SFML/Graphics.hpp>
#include <functional>

/**
 * @brief the main class for UI elements. Inherit from this class if you want to create new UI element.
 */
class Widget : public sf::Sprite
{
public:
	/**
	 * @brief it serves for us to get more control over the Text in a widget
	 */
	enum class TextAlign : __int8
	{
		Center	  // TODO: add 'left' 'right'
	};

public:
	~Widget() override = default;

	/**
	 * @brief you can set custom UI-object name. Use this function to do it
	 */
	void SetName(const std::string& Name);

	/**
	 * @brief you can get custom UI-object name
	 */
	_NODISCARD const std::string& GetName() const;

	void SetOnMouseLeftClickEventCallback(std::function<void(const Widget&)> OnClick);
	void SetOnMouseRightClickEventCallback(std::function<void(const Widget&)> OnClick);

	/**
	 * @brief call it every frame to update UI data. Also, you may know this function by name 'Tick"
	 */
	virtual void Update(sf::RenderWindow& Window);

protected:
	Widget() = default;

protected:
	std::function<void(const Widget&)> OnLeftClick_;
	std::function<void(const Widget&)> OnRightClick_;
	std::string Name_;
};