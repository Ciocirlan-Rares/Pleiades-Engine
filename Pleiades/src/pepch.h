#pragma once

// From C++ standard lib
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// Pleiades specific
#include "Pleiades/Core/Log.h"
#include "Pleiades/Debug/Instrumentor.h"

// Checking the current platform
#ifdef PE_PLATFORM_WINDOWS
	#include <Windows.h>
#endif