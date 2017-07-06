#pragma once
#include <sstream>

// ������������ ���� ����������� ���������� (���������� ��� ���������)
namespace graphics_lib
{
	// ����� ��� ���������
	class ICanvas
	{
	public:
		virtual void SetColor(uint32_t rgbColor) = 0;
		// ������ "����" � ����� x, y
		virtual void MoveTo(int x, int y) = 0;
		// ������ ����� � ������� �������, ���������� ���� � ����� x,y 
		virtual void LineTo(int x, int y) = 0;
		virtual ~ICanvas() = default;
	};

	// ���������� ������ ��� ���������
	class CCanvas : public ICanvas
	{
	public:
		CCanvas(std::ostream& outputStream);
		void SetColor(uint32_t rgbColor) override;
		void MoveTo(int x, int y) override;
		void LineTo(int x, int y) override;
	private:
		std::ostream& m_output;
	};
}