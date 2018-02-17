#include "CompositeFillStyle.h"
#include "Style.h"

void CCompositeFillStyle::Enable(bool enable)
{
	if (m_shapes->GetShapesCount() != 0)
	{
		for (int i = 0; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			auto style = shape->GetFillStyle();
			style->Enable(true);
		}
	}
}

void CCompositeFillStyle::SetColor(RGBAColor color)
{
	if (m_shapes->GetShapesCount() != 0)
	{
		std::shared_ptr<IStyle> style = std::make_shared<CStyle>(true, color);
		for (int i = 0; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			shape->SetFillStyle(style);
		}
	}
}

optional<bool> CCompositeFillStyle::IsEnabled()const
{
	optional<bool> isEnabled;

	if (m_shapes->GetShapesCount() == 1)
	{
		return m_shapes->GetShapeAtIndex(0)->GetFillStyle()->IsEnabled();
	}

	if (m_shapes->GetShapesCount() > 1)
	{
		isEnabled = m_shapes->GetShapeAtIndex(0)->GetFillStyle()->IsEnabled();
		for (int i = 1; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			if (shape->GetFillStyle()->IsEnabled() != isEnabled)
			{
				isEnabled = boost::none;
				break;
			}
		}
	}

	return isEnabled;
}

optional<RGBAColor> CCompositeFillStyle::GetColor()const
{
	optional<RGBAColor> resultColor;

	if (m_shapes->GetShapesCount() == 1)
	{
		auto style = m_shapes->GetShapeAtIndex(0)->GetFillStyle();
		if (style->IsEnabled())
		{
			return style->GetColor();
		}
	}
	
	if (m_shapes->GetShapesCount() > 1)
	{
		if (m_shapes->GetShapeAtIndex(0)->GetFillStyle()->IsEnabled())
		{
			resultColor = m_shapes->GetShapeAtIndex(0)->GetFillStyle()->GetColor();
			for (int i = 1; i < m_shapes->GetShapesCount(); i++)
			{
				auto style = m_shapes->GetShapeAtIndex(i)->GetFillStyle();
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