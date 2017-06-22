#pragma once
#include "IShapeFactory.h"
#include "Shape.h"
#include <memory>

class CShapeFactory :
	public IShapeFactory
{
public:
	CShapeFactory();

	std::unique_ptr<CShape> CreateShape(const std::string & description) override;

	~CShapeFactory();
private:
	std::unique_ptr<CShape> GetTriangleWithParams(std::vector<std::string> params) const;
	std::unique_ptr<CShape> GetRectangleWithParams(std::vector<std::string> params) const;
	std::unique_ptr<CShape> GetEllipseWithParams(std::vector<std::string> params) const;
	std::unique_ptr<CShape> GetRegularPolygonWithParams(std::vector<std::string> params) const;
};

