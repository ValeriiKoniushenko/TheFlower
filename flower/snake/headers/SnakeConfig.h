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

#include "Serializer.h"

struct SnakeConfig : public Serializer
{
public:
	SnakeConfig();
	~SnakeConfig() override;
	SnakeConfig(const SnakeConfig&) = default;
	SnakeConfig(SnakeConfig&&) = default;
	SnakeConfig& operator=(const SnakeConfig&) = default;
	SnakeConfig& operator=(SnakeConfig&&) = default;

	void Serialize() override;
	void Deserialize() override;

	clock_t LastSpawnTime = 0;
	__int32 StartSize = 2;
	clock_t GrowthSpeed = 3;
	clock_t SpawnEveryXSeconds = 5;
	clock_t SpeedUpEffectLength = 5;
	float SpeedUpEffectStrength = 2.f;
	clock_t EraseFrequency = 100;
};