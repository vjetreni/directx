#include "FrameTimer.h"

using namespace std;
using std::chrono::steady_clock;

FrameTimer::FrameTimer()
{
	last = steady_clock::now();
}

float FrameTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const std::chrono::duration<float> runTime = last - old;
	return runTime.count();

}
