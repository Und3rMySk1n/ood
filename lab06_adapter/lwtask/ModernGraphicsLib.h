#pragma once
#include <iostream>

// ѕространство имен современной графической библиотеки (недоступно дл€ изменени€)
namespace modern_graphics_lib
{
	class CRGBAColor
	{
	public:
		CRGBAColor(float r, float g, float b, float a) 
			: r(r)
			, g(g)
			, b(b)
			, a(a)
		{
		}

		float r, g, b, a;
	};


	class CPoint
	{
	public:
		CPoint(int x, int y) :x(x), y(y) {}

		int x;
		int y;
	};

	//  ласс дл€ современного рисовани€ графики
	class CModernGraphicsRenderer
	{
	public:
		CModernGraphicsRenderer(std::ostream & strm);
		~CModernGraphicsRenderer();

		// Ётот метод должен быть вызван в начале рисовани€
		void BeginDraw();

		// ¬ыполн€ет рисование линии
		void DrawLine(const CPoint & start, const CPoint & end, const CRGBAColor& color);

		// Ётот метод должен быть вызван в конце рисовани€
		void EndDraw();
	private:
		std::ostream & m_out;
		bool m_drawing = false;
	};
}