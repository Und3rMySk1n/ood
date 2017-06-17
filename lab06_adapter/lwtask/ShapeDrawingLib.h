#pragma once
#include "GraphicsLib.h"

// ѕространство имен библиотеки дл€ рисовани€ фигур (использует graphics_lib)
//  од библиотеки недоступен дл€ изменени€
namespace shape_drawing_lib
{
	struct Point
	{
		int x;
		int y;
	};

	// »нтерфейс объектов, которые могут быть нарисованы на холсте из graphics_lib
	class ICanvasDrawable
	{
	public:
		virtual void Draw(graphics_lib::ICanvas & canvas)const = 0;
		virtual ~ICanvasDrawable() = default;
	};

	class CTriangle : public ICanvasDrawable
	{
	public:
		CTriangle(const Point & p1, const Point & p2, const Point & p3)
			: m_pOne(p1)
			, m_pTwo(p2)
			, m_pThree(p3)
		{
		}

		void Draw(graphics_lib::ICanvas & canvas)const override;
	private:
		Point m_pOne = { 0, 0 };
		Point m_pTwo = { 0, 0 };
		Point m_pThree = { 0, 0 };
	};

	class CRectangle : public ICanvasDrawable
	{
	public:
		CRectangle(const Point & leftTop, int width, int height)
		{
			// TODO: написать код конструктора
		}

		void Draw(graphics_lib::ICanvas & canvas)const override
		{
			// TODO: написать код рисовани€ пр€моугольника на холсте
		}
	private:
		// TODO: дописать приватную часть 
	};

	// ’удожник, способный рисовать ICanvasDrawable-объекты на ICanvas
	class CCanvasPainter
	{
	public:
		CCanvasPainter(graphics_lib::ICanvas & canvas)
		{
			// TODO: дописать конструктор класса
		}
		void Draw(const ICanvasDrawable & drawable)
		{
			// TODO: дописать код рисовани€ ICanvasDrawable на canvas, переданном в конструктор
		}
	private:
		// TODO: дописать приватную часть
	};
}