#include "CompositeFillStyle.h"

void CCompositeFillStyle::Enable(bool enable)
{
	throw std::logic_error("Composite style can not be modified directly.");
}

void CCompositeFillStyle::SetColor(RGBAColor color)
{
	throw std::logic_error("Composite style can not be modified directly.");
}

optional<bool> CCompositeFillStyle::IsEnabled()const
{
	optional<bool> isEnabled = true;

	if (m_shapes->GetShapesCount() > 0)
	{
		for (int i = 0; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			if (shape->GetFillStyle()->IsEnabled() != true)
			{
				isEnabled = false;
				break;
			}
		}
	}

	return isEnabled;
}

optional<RGBAColor> CCompositeFillStyle::GetColor()const
{
	optional<RGBAColor> resultColor;
	if (m_shapes->GetShapesCount() == 0)
	{
		return resultColor;
	}

	std::shared_ptr<const IStyle> commonStyle = m_shapes->GetShapeAtIndex(0)->GetFillStyle();
	if (m_shapes->GetShapesCount() > 1)
	{
		for (int i = 1; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			if (commonStyle != shape->GetFillStyle())
			{
				commonStyle = nullptr;
				break;
			}
		}
	}

	if (commonStyle != nullptr)
	{
		resultColor = commonStyle->GetColor();
	}
	return resultColor;
}