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

#include "gtest/gtest.h"

#include "Serializer.h"
#include <filesystem>

TEST(Serializer, CheckSerializeMethod)
{
	const std::string FileName = "test.file";
	Serializer Saver(FileName);
	Saver.AddToSerialize("Hello", "World");
	Saver.Serialize();

	EXPECT_EQ(true, std::filesystem::exists(Serializer::SaveDirectory.string() + "/" + FileName));
}

TEST(Serializer, CheckDestruction)
{
	const std::string FileName = "test.file";

	{
		Serializer Saver(FileName);
		Saver.AddToSerialize("Hello", "World");
	}

	EXPECT_EQ(true, std::filesystem::exists(Serializer::SaveDirectory.string() + "/" + FileName));
}

TEST(Serializer, SettingInt)
{
	Serializer Saver("test.file");
	EXPECT_NO_THROW(Saver.AddToSerialize("Hello", 1));
}

TEST(Serializer, SettingFloat)
{
	Serializer Saver("test.file");
	EXPECT_NO_THROW(Saver.AddToSerialize("Hello", 1.5f));
}

TEST(Serializer, SettingDouble)
{
	Serializer Saver("test.file");
	EXPECT_NO_THROW(Saver.AddToSerialize("Hello", 1.5));
}

TEST(Serializer, TryToGetSerializedData)
{
	const std::string FileName = "test.file";

	Serializer Saver(FileName);
	EXPECT_NO_THROW(Saver.AddToSerialize("Width", 1.5));
	EXPECT_NO_THROW(Saver.AddToSerialize("Height", 10));
	EXPECT_NO_THROW(Saver.AddToSerialize("Hello", "World"));
	Saver.Serialize();

	Serializer Loader(FileName);
	Loader.Deserialize();
	EXPECT_EQ(1.5, Loader.GetFromSerializer<double>("Width"));
	EXPECT_EQ(10, Loader.GetFromSerializer<int>("Height"));
	EXPECT_EQ(std::string("World"), Loader.GetFromSerializer<std::string>("Hello"));
}