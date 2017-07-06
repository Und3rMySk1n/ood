#pragma once
#include <iostream>
#include "GraphicsLib.h"
#include <iomanip>

using namespace std;

namespace graphics_lib
{
	CCanvas::CCanvas(std::ostream& outputStream)
		: m_output(outputStream)
	{
	}

	void CCanvas::SetColor(uint32_t rgbColor)
	{
		m_output << "SetColor #" << std::setfill('0') << std::setw(6) << std::hex << rgbColor << std::dec << endl;
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