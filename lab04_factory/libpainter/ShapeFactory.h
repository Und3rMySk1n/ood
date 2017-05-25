#pragma once
#include "IShapeFactory.h"
#include "Triangle.h"
#include <memory>

class CShapeFactory :
	public IShapeFactory
{
public:
	CShapeFactory();

	std::unique_ptr<CShape> CreateShape(const std::string & description) override;

	~CShapeFactory();
};

