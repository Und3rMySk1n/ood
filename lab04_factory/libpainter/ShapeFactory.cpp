#include "stdafx.h"
#include "Triangle.h"
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

	throw invalid_argument("Unknown shape");
}

CShapeFactory::~CShapeFactory()
{
}
