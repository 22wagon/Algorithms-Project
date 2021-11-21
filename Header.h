#pragma once

#ifdef  WIN32
#define NOMINMAX
#define WIN32_LEAN_LEAN_AND_MEAN
#include <Windows.h>
#include <time.h>
#endif //  WIN32

#ifdef  WIN32
#define CLOCK_REALTIME 0
#define MS_PER_SEC 1000ULL
#define US_PER_MS 1000ULL
#define HNS_PER_US 10ULL
#define NS_PER_US 1000ULL

#define HNS_PER_SEC (MS_PER_SEC * US_PER_MS * HNS_PER_US)
#define NS_PER_HNS (100ULL)
#define NS_PER_SEC (MS_PER_SEC *US_PER_MS * NS_PER_US)

int clock_gettime_monotonic(struct timespec *tv) {
	static LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER ticks;
	double seconds;
	if (!ticksPerSec.QuadPart) {
		QueryPerformanceFrequency(&ticksPerSec);
		if (!ticksPerSec.QuadPart) {
			errno = ENOTSUP;
			return -1;
		}
	}
	QueryPerformanceCounter(&ticks);
	seconds = (double)ticks.QuadPart / (double)ticksPerSec.QuadPart;
	tv->tv_sec = (time_t)seconds;
	tv->tv_nsec = (long)((ULONGLONG)(seconds * NS_PER_SEC) % NS_PER_SEC);
	return 0;
}

#endif //  WIN32


