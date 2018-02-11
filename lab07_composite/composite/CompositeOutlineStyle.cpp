#include "CompositeOutlineStyle.h"
#include "Style.h"

void CCompositeOutlineStyle::Enable(bool enable)
{
	throw std::logic_error("Composite style can not be enabled directly.");
}

void CCompositeOutlineStyle::SetColor(RGBAColor color)
{
	if (m_shapes->GetShapesCount() != 0)
	{
		std::shared_ptr<IStyle> style = std::make_shared<CStyle>(true, color);
		for (int i = 0; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			shape->SetOutlineStyle(style);
		}
	}
}

optional<bool> CCompositeOutlineStyle::IsEnabled()const
{
	optional<bool> isEnabled;

	if (m_shapes->GetShapesCount() == 1)
	{
		return m_shapes->GetShapeAtIndex(0)->GetOutlineStyle()->IsEnabled();
	}

	if (m_shapes->GetShapesCount() > 1)
	{
		isEnabled = m_shapes->GetShapeAtIndex(0)->GetOutlineStyle()->IsEnabled();
		for (int i = 1; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			if (shape->GetOutlineStyle()->IsEnabled() != isEnabled)
			{
				isEnabled = boost::none;
				break;
			}
		}
	}

	return isEnabled;
}

optional<RGBAColor> CCompositeOutlineStyle::GetColor()const
{
	optional<RGBAColor> resultColor;

	if (m_shapes->GetShapesCount() == 1)
	{
		auto style = m_shapes->GetShapeAtIndex(0)->GetOutlineStyle();
		if (style->IsEnabled())
		{
			return style->GetColor();
		}
	}

	if (m_shapes->GetShapesCount() > 1)
	{
		if (m_shapes->GetShapeAtIndex(0)->GetOutlineStyle()->IsEnabled())
		{
			resultColor = m_shapes->GetShapeAtIndex(0)->GetOutlineStyle()->GetColor();
			for (int i = 1; i < m_shapes->GetShapesCount(); i++)
			{
				auto style = m_shapes->GetShapeAtIndex(i)->GetOutlineStyle();
				if (style->GetColor() != resultColor || !style->IsEnabled())
				{
					resultColor = boost::none;
					break;
				}
			}
		}
	}

	return resultColor;
}