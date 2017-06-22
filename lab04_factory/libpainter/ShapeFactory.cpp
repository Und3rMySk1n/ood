#include "stdafx.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "RegularPolygon.h"
#include "ShapeFactory.h"
#include <sstream>
#include "Utils.h"

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
		return GetTriangleWithParams(params);
	}
	else if (shape == "rectangle")
	{
		return GetRectangleWithParams(params);
	}
	else if (shape == "ellipse")
	{
		return GetEllipseWithParams(params);
	}
	else if (shape == "polygon")
	{
		return GetRegularPolygonWithParams(params);
	}

	throw invalid_argument("Unknown shape");
}

CShapeFactory::~CShapeFactory()
{
}


unique_ptr<CShape> CShapeFactory::GetTriangleWithParams(std::vector<std::string> params) const
{
	Color color = GetColorFromString(params.at(1));
	Vertex v1 = { stof(params.at(2)), stof(params.at(3)) };
	Vertex v2 = { stof(params.at(4)), stof(params.at(5)) };
	Vertex v3 = { stof(params.at(6)), stof(params.at(7)) };

	return make_unique<CTriangle>(color, v1, v2, v3);
}

std::unique_ptr<CShape> CShapeFactory::GetRectangleWithParams(std::vector<std::string> params) const
{
	Color color = GetColorFromString(params.at(1));
	Vertex leftTop = { stof(params.at(2)), stof(params.at(3)) };
	Vertex rightTop = { stof(params.at(4)), stof(params.at(5)) };

	return make_unique<CRectangle>(color, leftTop, rightTop);
}

std::unique_ptr<CShape> CShapeFactory::GetEllipseWithParams(std::vector<std::string> params) const
{
	Color color = GetColorFromString(params.at(1));
	Vertex center = { stof(params.at(2)), stof(params.at(3)) };
	float width = stof(params.at(4));
	float height = stof(params.at(5));

	return make_unique<CEllipse>(color, center, width, height);
}

std::unique_ptr<CShape> CShapeFactory::GetRegularPolygonWithParams(std::vector<std::string> params) const
{
	Color color = GetColorFromString(params.at(1));
	Vertex center = { stof(params.at(2)), stof(params.at(3)) };
	float radius = stof(params.at(4));
	int vertexCount = stoi(params.at(5));

	return make_unique<CRegularPolygon>(color, center, radius, vertexCount);
}