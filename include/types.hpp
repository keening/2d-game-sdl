#pragma once 

#include <cstdint>

typedef int32_t  i32;
typedef int16_t  i16;
typedef int8_t    i8;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t   u8;
typedef float    f32;
typedef double   f64;

enum Direction { NONE, LEFT, RIGHT, UP, DOWN };

struct vec2_t { i32 x, y; };