#pragma once

#include <stdint.h>
#include <vector>
#include <string>

/// For cstr memory allocations when zero byte is needed
#define ZEROBYTE_CSTR(size) char[size + 1]

typedef std::vector<std::string> t_ImageBuffer;

const char FD_EMPTY			= ' '; ///< Empty character
const char FD_WALL			= '*'; ///< Representation of a wall inside the console window