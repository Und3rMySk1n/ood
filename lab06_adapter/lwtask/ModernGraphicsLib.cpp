#pragma once
#include <iostream>
#include <stdexcept>
#include <boost/format.hpp>
#include "ModernGraphicsLib.h"

using namespace std;

// ѕространство имен современной графической библиотеки (недоступно дл€ изменени€)
namespace modern_graphics_lib
{
	modern_graphics_lib::CModernGraphicsRenderer::CModernGraphicsRenderer(std::ostream & strm) : m_out(strm)
	{
	}

	modern_graphics_lib::CModernGraphicsRenderer::~CModernGraphicsRenderer()
	{
		if (m_drawing) // «авершаем рисование, если оно было начато
		{
			EndDraw();
		}
	}

	void modern_graphics_lib ::CModernGraphicsRenderer::BeginDraw()
	{
		if (m_drawing)
		{
			throw logic_error("Drawing has already begun");
		}
		m_out << "<draw>" << endl;
		m_drawing = true;
	}

	void modern_graphics_lib::CModernGraphicsRenderer::DrawLine(const CPoint & start, const CPoint & end, const CRGBAColor& color)
	{
		if (!m_drawing)
		{
			throw logic_error("DrawLine is allowed between BeginDraw()/EndDraw() only");
		}
		m_out << boost::format(R"(  <line fromX="%1%" fromY="%2%" toX="%3%" toY="%4%">)") % start.x % start.y % end.x % end.y << endl;
		m_out << boost::format(R"(    <color r="%1$.1f" g="%2$.1f" b="%3$.1f" a="%4$.1f" />)") % color.r % color.g % color.b % color.a << endl;
		m_out << "  </line>" << endl;
	}

	void modern_graphics_lib::CModernGraphicsRenderer::EndDraw()
	{
		if (!m_drawing)
		{
			throw logic_error("Drawing has not been started");
		}
		m_out << "</draw>" << endl;
		m_drawing = false;
	}
}