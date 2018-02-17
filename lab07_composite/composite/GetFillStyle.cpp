#include "GetFillStyle.h"



CGetFillStyle::CGetFillStyle()
{
}


CGetFillStyle::~CGetFillStyle()
{
}

std::shared_ptr<IStyle> CGetFillStyle::GetStyle(std::shared_ptr<IShape> shape)
{
	return shape->GetFillStyle();
}
