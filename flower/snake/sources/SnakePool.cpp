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

#include "SnakePool.h"

SnakePool::SnakePool() : Serializer("SnakePool.json")
{
}

SnakePool::~SnakePool()
{
	Serialize();
}

void SnakePool::Serialize()
{
	boost::property_tree::ptree Array;
	for (Snake& Snake_ : Snakes_)
	{
		Array.push_back(std::make_pair("", Snake_.ToJSON()));
	}

	AddToSerialize("Snakes", Array);

	Serializer::Serialize();
}

void SnakePool::Deserialize()
{
	Serializer::Deserialize();

	auto SnakeKey = Begin()->second;
	for (auto It = SnakeKey.begin(); It != SnakeKey.end(); ++It)
	{
		Snake Temp;
		Temp.SetPosition({It->second.get<float>("x"), It->second.get<float>("y")});
		Snakes_.push_back(Temp);
	}
}

void SnakePool::Push(const Snake& NewFlower)
{
	Snakes_.emplace_back(NewFlower);
}

std::size_t SnakePool::Size() const
{
	return Snakes_.size();
}

std::vector<Snake>::iterator SnakePool::begin()
{
	return Snakes_.begin();
}

std::vector<Snake>::iterator SnakePool::end()
{
	return Snakes_.end();
}

void SnakePool::SetSnakeTexture(sf::Texture& Texture)
{
	TextureP_ = &Texture;
	for (Snake& Snake_ : Snakes_)
	{
		Snake_.SetTexture(*TextureP_);
	}
}
