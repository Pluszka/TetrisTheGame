#include "color.h"
#include <vector>
const Color blue = { 25, 130, 196, 255 };
const Color red = { 255, 89, 94, 255 };
const Color yellow = { 255, 202, 58, 255 };
const Color purple = { 106, 76, 147, 255 };
const Color dark = { 82, 166, 117, 255 };
const Color bright = { 225, 146, 76, 255 };
const Color green = { 138, 201, 38, 255 };

std::vector<Color> GetCellColors() {

	return { blue, red, yellow, purple, dark, bright, green, BLACK};
}