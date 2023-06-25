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

#include "FlowerPool.h"

FlowerPool::FlowerPool() : Serializer("FlowerPool.json")
{
}

FlowerPool::~FlowerPool()
{
	Serialize();
}

void FlowerPool::Serialize()
{
	boost::property_tree::ptree Array;
	for (Flower& Flower_ : Flowers_)
	{
		Array.push_back(std::make_pair("", Flower_.ToJSON()));
	}

	AddToSerialize("Flowers", Array);

	Serializer::Serialize();
}

void FlowerPool::Deserialize()
{
	Serializer::Deserialize();

	if (Begin() != End())
	{
		auto FlowerKey = Begin()->second;
		for (auto It = FlowerKey.begin(); It != FlowerKey.end(); ++It)
		{
			Flower Temp;
			Temp.SetPosition({It->second.get<float>("x"), It->second.get<float>("y")});
			Flowers_.push_back(Temp);
		}
	}
}

std::size_t FlowerPool::Size() const
{
	return Flowers_.size();
}

void FlowerPool::Push(const Flower& NewFlower)
{
	Flowers_.push_back(NewFlower);
}

std::vector<Flower>::iterator FlowerPool::begin()
{
	return Flowers_.begin();
}

std::vector<Flower>::iterator FlowerPool::end()
{
	return Flowers_.end();
}

std::vector<Flower>::iterator FlowerPool::Erase(const std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Flower>>>& It)
{
	return Flowers_.erase(It);
}
