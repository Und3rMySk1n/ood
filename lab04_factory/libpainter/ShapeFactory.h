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
	std::unique_ptr<CShape> GetTriangleWithParams(const std::vector<std::string> &params) const;
	std::unique_ptr<CShape> GetRectangleWithParams(const std::vector<std::string> &params) const;
	std::unique_ptr<CShape> GetEllipseWithParams(const std::vector<std::string> &params) const;
	std::unique_ptr<CShape> GetRegularPolygonWithParams(const std::vector<std::string> &params) const;
};

