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

	void modern_graphics_lib::CModernGraphicsRenderer::DrawLine(const CPoint & start, const CPoint & end)
	{
		if (!m_drawing)
		{
			throw logic_error("DrawLine is allowed between BeginDraw()/EndDraw() only");
		}
		m_out << boost::format(R"(  <line fromX="%1%" fromY="%2" toX="%3%" toY="%4%"/>)") << endl;
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