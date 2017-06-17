#pragma once
#include <iostream>
#include "GraphicsLib.h"

using namespace std;

namespace graphics_lib
{
	CCanvas::CCanvas(std::ostream& outputStream)
		: m_output(outputStream)
	{
	}

	void CCanvas::MoveTo(int x, int y)
	{
		m_output << "MoveTo (" << x << ", " << y << ")" << endl;
	}

	void CCanvas::LineTo(int x, int y)
	{
		m_output << "LineTo (" << x << ", " << y << ")" << endl;
	}
}