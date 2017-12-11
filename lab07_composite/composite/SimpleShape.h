#pragma once
#include "ICanvas.h"
#include "IShape.h"

class CSimpleShape : public IShape
{
public:
	CSimpleShape();
	
	virtual std::shared_ptr<IStyle> GetOutlineStyle() override;
	virtual std::shared_ptr<const IStyle> GetOutlineStyle()const override;

	virtual std::shared_ptr<IStyle> GetFillStyle() override;
	virtual std::shared_ptr<const IStyle> GetFillStyle()const override;

	virtual std::shared_ptr<IGroupShape> GetGroup() override;
	virtual std::shared_ptr<const IGroupShape> GetGroup() const override;

	void SetOutlineStyle(const std::shared_ptr<IStyle> &style) override;
	void SetFillStyle(const std::shared_ptr<IStyle> &style) override;
	void SetCanvasStyles(ICanvas & canvas);

protected:
	std::shared_ptr<IStyle> m_outlineStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};