#pragma once
#include "IGetStyleBehavior.h"

class CGetOutlineStyle : public IGetStyleBehavior
{
public:
	CGetOutlineStyle();

	std::shared_ptr<IStyle> GetStyle(std::shared_ptr<IShape> shape) override;

	~CGetOutlineStyle();
};

