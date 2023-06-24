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

#include "SnakeConfig.h"

SnakeConfig::SnakeConfig() : Serializer("SnakeConfig.json")
{
}

SnakeConfig::~SnakeConfig()
{
	Serialize();
}

void SnakeConfig::Serialize()
{
	AddToSerialize("StartSize", StartSize);
	AddToSerialize("GrowthSpeed", GrowthSpeed);
	AddToSerialize("SpawnEveryXSeconds", SpawnEveryXSeconds);
	AddToSerialize("SpeedUpEffectLength", SpeedUpEffectLength);
	AddToSerialize("SpeedUpEffectStrength", SpeedUpEffectStrength);
	AddToSerialize("EraseFrequency", EraseFrequency);
	AddToSerialize("GrowthFrequency", GrowthFrequency);
	AddToSerialize("MaxSize", MaxSize);

	Serializer::Serialize();
}

void SnakeConfig::Deserialize()
{
	Serializer::Deserialize();

	LastSpawnTime = 0;
	StartSize = GetFromSerializer<decltype(StartSize)>("StartSize");
	GrowthSpeed = GetFromSerializer<decltype(GrowthSpeed)>("GrowthSpeed");
	SpawnEveryXSeconds = GetFromSerializer<decltype(SpawnEveryXSeconds)>("SpawnEveryXSeconds");
	SpeedUpEffectLength = GetFromSerializer<decltype(SpeedUpEffectLength)>("SpeedUpEffectLength");
	SpeedUpEffectStrength = GetFromSerializer<decltype(SpeedUpEffectStrength)>("SpeedUpEffectStrength");
	EraseFrequency = GetFromSerializer<decltype(EraseFrequency)>("EraseFrequency");
	GrowthFrequency = GetFromSerializer<decltype(GrowthFrequency)>("GrowthFrequency");
	LastGrowth = 0;
	MaxSize = GetFromSerializer<decltype(MaxSize)>("MaxSize");
}
