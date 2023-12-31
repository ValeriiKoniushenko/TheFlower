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

#include "SFML/Graphics.hpp"
#include "boost/property_tree/json_parser.hpp"
#include "boost/property_tree/ptree.hpp"

/**
 * @brief The base class for all objects on the scene
 */
class SceneObject
{
public:
	SceneObject() = default;
	virtual ~SceneObject() = default;
	SceneObject(const SceneObject&) = default;
	SceneObject(SceneObject&&) = default;
	SceneObject& operator=(const SceneObject&) = default;
	SceneObject& operator=(SceneObject&&) = default;

	/**
	 * @brief override this function to Draw anything on the scene
	 */
	virtual void Draw(sf::RenderWindow& Window) = 0;

	/**
	 * @brief override this function to get an ability cast your scene object to JSON format. It can be needed for a mechanism of
	 * serialization.
	 */
	_NODISCARD virtual boost::property_tree::ptree ToJSON() const = 0;
};