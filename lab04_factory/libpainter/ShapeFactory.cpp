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
	stringstream params(description);
	string name;
	params >> name;	

	if (name == "triangle")
	{
		Vertex v1, v2, v3;
		string colorAsString;

		params >> colorAsString; 
		params >> v1.x;
		params >> v1.y;
		params >> v2.x;
		params >> v2.y;
		params >> v3.x;
		params >> v3.y;
		Color color = GetColorFromString(colorAsString);

		return make_unique<CTriangle>(color, v1, v2, v3);
	}
	else if (name == "rectangle")
	{
		Vertex leftTop, rightTop;
		string colorAsString;

		params >> colorAsString;
		params >> leftTop.x;
		params >> leftTop.y;
		params >> rightTop.x;
		params >> rightTop.y;
		Color color = GetColorFromString(colorAsString);

		return make_unique<CRectangle>(color, leftTop, rightTop);
	}
	else if (name == "ellipse")
	{
		Vertex center;
		float height, width;
		string colorAsString;
		
		params >> colorAsString;
		params >> center.x;
		params >> center.y;
		params >> width;
		params >> height;
		Color color = GetColorFromString(colorAsString);

		return make_unique<CEllipse>(color, center, width, height);
	}
	else if (name == "polygon")
	{
		Vertex center;
		float radius;
		int vertexCount;
		string colorAsString;

		params >> colorAsString;
		params >> center.x;
		params >> center.y;
		params >> radius;
		params >> vertexCount;
		Color color = GetColorFromString(colorAsString);

		return make_unique<CRegularPolygon>(color, center, radius, vertexCount);
	}

	throw invalid_argument("Unknown shape");
}

CShapeFactory::~CShapeFactory()
{
}
