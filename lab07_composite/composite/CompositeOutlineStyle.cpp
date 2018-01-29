#include "CompositeOutlineStyle.h"

void CCompositeOutlineStyle::Enable(bool enable)
{
	throw std::logic_error("Composite style can not be modified directly.");
}

void CCompositeOutlineStyle::SetColor(RGBAColor color)
{
	throw std::logic_error("Composite style can not be modified directly.");
}

optional<bool> CCompositeOutlineStyle::IsEnabled()const
{
	optional<bool> isEnabled = true;

	if (m_shapes->GetShapesCount() > 0)
	{
		for (int i = 0; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			if (shape->GetOutlineStyle()->IsEnabled() != true)
			{
				isEnabled = false;
				break;
			}
		}
	}

	return isEnabled;
}

optional<RGBAColor> CCompositeOutlineStyle::GetColor()const
{
	optional<RGBAColor> resultColor;
	if (m_shapes->GetShapesCount() == 0)
	{
		return resultColor;
	}

	std::shared_ptr<const IStyle> commonStyle = m_shapes->GetShapeAtIndex(0)->GetFillStyle();
	if (m_shapes->GetShapesCount() > 0)
	{
		for (int i = 1; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			if (commonStyle != shape->GetOutlineStyle())
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