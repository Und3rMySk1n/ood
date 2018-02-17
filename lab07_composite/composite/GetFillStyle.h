#pragma once
#include "IGetStyleBehavior.h"

class CGetFillStyle : public IGetStyleBehavior
{
public:
	CGetFillStyle();

	std::shared_ptr<IStyle> GetStyle(std::shared_ptr<IShape> shape) override;

	~CGetFillStyle();
};

