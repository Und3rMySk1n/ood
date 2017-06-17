#pragma once
#include "GraphicsLib.h"

// ������������ ���� ���������� ��� ��������� ����� (���������� graphics_lib)
// ��� ���������� ���������� ��� ���������
namespace shape_drawing_lib
{
	struct Point
	{
		int x;
		int y;
	};

	// ��������� ��������, ������� ����� ���� ���������� �� ������ �� graphics_lib
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
			// TODO: �������� ��� ������������
		}

		void Draw(graphics_lib::ICanvas & canvas)const override
		{
			// TODO: �������� ��� ��������� �������������� �� ������
		}
	private:
		// TODO: �������� ��������� ����� 
	};

	// ��������, ��������� �������� ICanvasDrawable-������� �� ICanvas
	class CCanvasPainter
	{
	public:
		CCanvasPainter(graphics_lib::ICanvas & canvas)
		{
			// TODO: �������� ����������� ������
		}
		void Draw(const ICanvasDrawable & drawable)
		{
			// TODO: �������� ��� ��������� ICanvasDrawable �� canvas, ���������� � �����������
		}
	private:
		// TODO: �������� ��������� �����
	};
}