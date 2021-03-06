#pragma once
#include "Color.h"
#include <string>
#include <sstream>
#include <vector>
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

static string ColorAsString(Color color)
{
	map<Color, string> colorsTable = {
		{ Color::black, "black" },
		{ Color::blue, "blue" },
		{ Color::green, "green" },
		{ Color::pink, "pink" },
		{ Color::red, "red" },
		{ Color::yellow, "yellow" }
	};

	return colorsTable.at(color);
}

static vector<string> GetParamsFromString(const string &paramsAsString)
{
	stringstream paramsAsStream(paramsAsString);
	vector<string> paramsList;
	string param;

	while (paramsAsStream >> param)
	{
		paramsList.push_back(param);
	}

	return paramsList;
}