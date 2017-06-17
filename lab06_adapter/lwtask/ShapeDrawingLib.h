#pragma once
#include "GraphicsLib.h"

// Пространство имен библиотеки для рисования фигур (использует graphics_lib)
// Код библиотеки недоступен для изменения
namespace shape_drawing_lib
{
	struct Point
	{
		int x;
		int y;
	};

	// Интерфейс объектов, которые могут быть нарисованы на холсте из graphics_lib
	class ICanvasDrawable
	{
	public:
		virtual void Draw(graphics_lib::ICanvas & canvas)const = 0;
		virtual ~ICanvasDrawable() = default;
	};

	class CTriangle : public ICanvasDrawable
	{
	public:
		CTriangle(const Point & p1, const Point & p2, const Point & p3);
		void Draw(graphics_lib::ICanvas & canvas)const override;
	private:
		Point m_pOne = { 0, 0 };
		Point m_pTwo = { 0, 0 };
		Point m_pThree = { 0, 0 };
	};

	class CRectangle : public ICanvasDrawable
	{
	public:
		CRectangle(const Point & leftTop, int width, int height);
		void Draw(graphics_lib::ICanvas & canvas)const override;
	private:
		Point m_leftTop = { 0, 0 };
		Point m_rightBottom = { 0, 0 };
	};

	// Художник, способный рисовать ICanvasDrawable-объекты на ICanvas
	class CCanvasPainter
	{
	public:
		CCanvasPainter(graphics_lib::ICanvas & canvas)
		{
			// TODO: дописать конструктор класса
		}
		void Draw(const ICanvasDrawable & drawable)
		{
			// TODO: дописать код рисования ICanvasDrawable на canvas, переданном в конструктор
		}
	private:
		// TODO: дописать приватную часть
	};
}