#include "GetOutlineStyle.h"



CGetOutlineStyle::CGetOutlineStyle()
{
}


CGetOutlineStyle::~CGetOutlineStyle()
{
}

std::shared_ptr<IStyle> CGetOutlineStyle::GetStyle(std::shared_ptr<IShape> shape)
{
	return shape->GetOutlineStyle();
}