#pragma once
#include <string>
#include <memory>
#include <boost\optional.hpp>
#include <boost\none.hpp>
#include "IParagraph.h"
#include "IImage.h"

class IDocument
{
public:
	virtual std::string GetTitle()const = 0;
	virtual void SetTitle(const std::string & title) = 0;

	virtual ~IDocument() = default;
};