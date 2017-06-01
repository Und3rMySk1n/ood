#include "stdafx.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "RegularPolygon.h"
#include "ShapeFactory.h"
#include <sstream>

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

		params >> v1.x;
		params >> v1.y;
		params >> v2.x;
		params >> v2.y;
		params >> v3.x;
		params >> v3.y;

		return make_unique<CTriangle>(v1, v2, v3);
	}
	else if (name == "rectangle")
	{
		Vertex leftTop, rightTop;

		params >> leftTop.x;
		params >> leftTop.y;
		params >> rightTop.x;
		params >> rightTop.y;

		return make_unique<CRectangle>(leftTop, rightTop);
	}
	else if (name == "ellipse")
	{
		Vertex center;
		float height, width;

		params >> center.x;
		params >> center.y;
		params >> width;
		params >> height;

		return make_unique<CEllipse>(center, width, height);
	}
	else if (name == "polygon")
	{
		Vertex center;
		float radius;
		int vertexCount;

		params >> center.x;
		params >> center.y;
		params >> radius;
		params >> vertexCount;

		return make_unique<CRegularPolygon>(center, radius, vertexCount);
	}

	throw invalid_argument("Unknown shape");
}

CShapeFactory::~CShapeFactory()
{
}
