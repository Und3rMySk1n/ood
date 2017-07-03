#include "SimpleShape.h"
#include "Style.h"

using namespace std;

CSimpleShape::CSimpleShape()
{
	m_fillStyle = make_shared<CStyle>(false, NULL);
	m_outlineStyle = make_shared<CStyle>(true, 0);
}

std::shared_ptr<IStyle> CSimpleShape::GetOutlineStyle()
{
	return m_outlineStyle;
}

const std::shared_ptr<IStyle> CSimpleShape::GetOutlineStyle()const
{
	return m_outlineStyle;
}

std::shared_ptr<IStyle> CSimpleShape::GetFillStyle()
{
	return m_fillStyle;
}

const std::shared_ptr<IStyle> CSimpleShape::GetFillStyle()const
{
	return m_fillStyle;
}

std::shared_ptr<IGroupShape> CSimpleShape::GetGroup()
{
	return m_group;
}

std::shared_ptr<const IGroupShape> CSimpleShape::GetGroup() const
{
	return m_group;
}

void CSimpleShape::SetOutlineStyle(const std::shared_ptr<IStyle> &style)
{
	m_outlineStyle = style;
}

void CSimpleShape::SetFillStyle(const std::shared_ptr<IStyle> &style)
{
	m_fillStyle = style;
}

void CSimpleShape::SetCanvasStyles(ICanvas & canvas)
{
	canvas.SetLineColor(m_outlineStyle->GetColor());
	if (m_fillStyle->IsEnabled())
	{
		canvas.BeginFill(m_fillStyle->GetColor());
	}
}