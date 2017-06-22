#pragma once
#include "Color.h"
#include <string>
#include <map>

using namespace std;

static Color GetColorFromString(string colorAsString)
{
	map<string, Color> colorsTable = {
		{ "black", Color::black },
		{ "blue", Color::blue },
		{ "green", Color::green },
		{ "pink", Color::pink },
		{ "red", Color::red },
		{ "yellow", Color::yellow }
	};

	return colorsTable.at(colorAsString);
}
