#pragma once
#include <memory>
#include "IStyle.h"
#include "Shapes.h"

class CCompositeFillStyle : public IStyle
{
public:
	CCompositeFillStyle(std::shared_ptr<const CShapes> shapes)
		: m_shapes(move(shapes))
	{}

	virtual optional<bool> IsEnabled()const override;
	virtual void Enable(bool enable) override;

	virtual optional<RGBAColor> GetColor()const override;
	virtual void SetColor(RGBAColor color) override;

	~CCompositeFillStyle() {}
private:
	std::shared_ptr<const CShapes> m_shapes;
};

