#pragma once
#include "Color.h"
#include "Vertex.h"
#include "ICanvas.h"
#include "IShape.h"

class CShape : public IShape
{
public:
	CShape();

	virtual std::unique_ptr<CShape> Clone()const = 0;

	virtual void SetColor(Color color) override;
	virtual Color GetColor() const override;

	virtual ~CShape();
private:
	Color m_color = Color::black;
};


template <typename Base, typename CloneInterface, typename Impl>
class CShapeImpl : public Base
{
public:
	std::unique_ptr<CloneInterface> Clone()const override
	{
		return make_unique<Impl>(*static_cast<Impl const*>(this));
	}
};