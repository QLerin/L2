#pragma once

#include <stdint.h>

/// For cstr memory allocations when zero byte is needed
#define ZEROBYTE_CSTR(size) char[size + 1]

const char FD_WALL = '*'; ///< Representation of a wall inside the console window