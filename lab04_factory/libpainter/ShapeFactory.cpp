#include "stdafx.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "RegularPolygon.h"
#include "ShapeFactory.h"
#include <sstream>
#include "Utils.h"
s
using namespace std;

CShapeFactory::CShapeFactory()
{
}

unique_ptr<CShape> CShapeFactory::CreateShape(const string & description)
{
	vector<string> params = GetParamsFromString(description);
	string shape = params.at(0);

	if (shape == "triangle")
	{
		Color color = GetColorFromString(params.at(1));
		Vertex v1 = { stof(params.at(2)), stof(params.at(3)) };
		Vertex v2 = { stof(params.at(4)), stof(params.at(5)) };
		Vertex v3 = { stof(params.at(6)), stof(params.at(7)) };

		return make_unique<CTriangle>(color, v1, v2, v3);
	}
	else if (shape == "rectangle")
	{
		Color color = GetColorFromString(params.at(1));
		Vertex leftTop = { stof(params.at(2)), stof(params.at(3)) };
		Vertex rightTop = { stof(params.at(4)), stof(params.at(5)) };

		return make_unique<CRectangle>(color, leftTop, rightTop);
	}
	else if (shape == "ellipse")
	{
		Color color = GetColorFromString(params.at(1));
		Vertex center = { stof(params.at(2)), stof(params.at(3)) };
		float width = stof(params.at(4));
		float height = stof(params.at(5));

		return make_unique<CEllipse>(color, center, width, height);
	}
	else if (shape == "polygon")
	{
		Color color = GetColorFromString(params.at(1));
		Vertex center = { stof(params.at(2)), stof(params.at(3)) };
		float radius = stof(params.at(4));
		int vertexCount = stoi(params.at(5));

		return make_unique<CRegularPolygon>(color, center, radius, vertexCount);
	}

	throw invalid_argument("Unknown shape");
}

CShapeFactory::~CShapeFactory()
{
}
