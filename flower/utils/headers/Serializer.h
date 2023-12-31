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

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <filesystem>
#include <string>

/**
 * @brief You can use this class if you want to serialize your own data to a file. For an example you can use to store all amount of
 * your money.
 */
class Serializer
{
public:
	explicit Serializer(std::string SaveFileName);
	virtual ~Serializer() = default;
	Serializer(const Serializer&) = default;
	Serializer(Serializer&&) = default;
	Serializer& operator=(const Serializer&) = default;
	Serializer& operator=(Serializer&&) = default;

	/**
	 * @brief Add this method in the overrided Serialize function to serialize custom data
	 */
	template <class T>
	void AddToSerialize(const std::string& Key, const T& Value);

	/**
	 * @brief Add this method in the overrided Serialize function to serialize custom data
	 */
	void AddToSerialize(const std::string& Key, const boost::property_tree::ptree& PTree);

	template <class T>
	T GetFromSerializer(const std::string& Key);

	/**
	 * @brief call this function using 'super' AFTER your code
	 */
	virtual void Serialize();

	/**
	 * @brief call this function using 'super' BEFORE your code
	 */
	virtual void Deserialize();

	/**
	 * @brief use this method if you want to get the first element from a PTree
	 */
	_NODISCARD boost::property_tree::ptree::iterator Begin();

	/**
	 * @brief use this method if you want to get the last element from a PTree
	 */
	_NODISCARD boost::property_tree::ptree::iterator End();

	// TODO: add config directory
	inline static const std::filesystem::path SaveDirectory = "save";

protected:
	/**
	 * @brief getting a path for saving data, e.g. 'save/General.json'
	 */
	_NODISCARD std::filesystem::path GetSavePath() const;

private:
	std::string SaveFileName_;
	boost::property_tree::ptree PTree_;
};

template <class T>
void Serializer::AddToSerialize(const std::string& Key, const T& Value)
{
	PTree_.put(Key, Value);
}

template <class T>
T Serializer::GetFromSerializer(const std::string& Key)
{
	return PTree_.get<T>(Key);
}