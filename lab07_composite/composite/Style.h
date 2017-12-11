#pragma once
#include "IStyle.h"

class CStyle : public IStyle
{
public:
	CStyle(bool isEnabled, RGBAColor color);

	virtual bool IsEnabled()const override;
	virtual void Enable(bool enable) override;

	virtual RGBAColor GetColor()const override;
	virtual void SetColor(RGBAColor color) override;
private:
	bool m_isEnabled = false;
	RGBAColor m_color = 0;
};