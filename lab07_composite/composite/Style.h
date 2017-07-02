#pragma once
#include "IStyle.h"

class CStyle : public IStyle
{
public:
	virtual optional<bool> IsEnabled()const override
	{
		return m_isEnabled;
	}

	virtual void Enable(bool enable) override
	{
		m_isEnabled = enable;
	}

	virtual optional<RGBAColor> GetColor()const override
	{
		return m_color;
	}

	virtual void SetColor(RGBAColor color) override
	{
		m_color = color;
	}
private:
	bool m_isEnabled = false;
	RGBAColor m_color;
};