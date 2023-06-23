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

#include <cstdio>

#include "gtest/gtest.h"

#if GTEST_OS_ESP8266 || GTEST_OS_ESP32
// Arduino-like platforms: program entry points are setup/loop instead of main.

#if GTEST_OS_ESP8266
extern "C" {
#endif

	void setup() { testing::InitGoogleTest(); }

	void loop() { RUN_ALL_TESTS(); }

#if GTEST_OS_ESP8266
}
#endif

#elif GTEST_OS_QURT
// QuRT: program entry point is main, but argc/argv are unusable.

GTEST_API_ int main() {
	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
#else
// Normal platforms: program entry point is main, argc/argv are initialized.

GTEST_API_ int main(int argc, char **argv) {
	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
#endif
