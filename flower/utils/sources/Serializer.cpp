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

#include "Serializer.h"

#include <utility>

Serializer::Serializer(std::string SaveFileName) : SaveFileName_(std::move(SaveFileName))
{
}

void Serializer::Serialize()
{
	if (!std::filesystem::exists(SaveDirectory))
	{
		std::filesystem::create_directory(SaveDirectory);
	}

	boost::property_tree::write_json(GetSavePath().string(), PTree_);
}

void Serializer::Deserialize()
{
	try
	{
		boost::property_tree::read_json(GetSavePath().string(), PTree_);
	}
	catch (...)
	{
	}
}

std::filesystem::path Serializer::GetSavePath() const
{
	return SaveDirectory.string() + "/" + SaveFileName_;
}

void Serializer::AddToSerialize(const std::string& Key, const boost::property_tree::ptree& PTree)
{
	PTree_.put_child(Key, PTree);
}

boost::property_tree::ptree::iterator Serializer::Begin()
{
	return PTree_.begin();
}

boost::property_tree::ptree::iterator Serializer::End()
{
	return PTree_.end();
}
