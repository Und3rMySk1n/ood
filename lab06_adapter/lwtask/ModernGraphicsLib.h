#pragma once
#include <iostream>

// ������������ ���� ����������� ����������� ���������� (���������� ��� ���������)
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

	// ����� ��� ������������ ��������� �������
	class CModernGraphicsRenderer
	{
	public:
		CModernGraphicsRenderer(std::ostream & strm);
		~CModernGraphicsRenderer();

		// ���� ����� ������ ���� ������ � ������ ���������
		void BeginDraw();

		// ��������� ��������� �����
		void DrawLine(const CPoint & start, const CPoint & end, const CRGBAColor& color);

		// ���� ����� ������ ���� ������ � ����� ���������
		void EndDraw();
	private:
		std::ostream & m_out;
		bool m_drawing = false;
	};
}