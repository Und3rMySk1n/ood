#pragma once
#include "CommonTypes.h"
#include <boost/optional.hpp>

using boost::optional;

class IStyle
{
public:
	virtual bool IsEnabled()const = 0;
	virtual void Enable(bool enable) = 0;

	virtual RGBAColor GetColor()const = 0;
	virtual void SetColor(RGBAColor color) = 0;

	virtual ~IStyle() = default;
};