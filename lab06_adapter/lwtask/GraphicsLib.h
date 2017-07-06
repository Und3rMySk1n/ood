#pragma once
#include <sstream>

// Пространство имен графической библиотеки (недоступно для изменения)
namespace graphics_lib
{
	// Холст для рисования
	class ICanvas
	{
	public:
		virtual void SetColor(uint32_t rgbColor) = 0;
		// Ставит "перо" в точку x, y
		virtual void MoveTo(int x, int y) = 0;
		// Рисует линию с текущей позиции, передвигая перо в точку x,y 
		virtual void LineTo(int x, int y) = 0;
		virtual ~ICanvas() = default;
	};

	// Реализация холста для рисования
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