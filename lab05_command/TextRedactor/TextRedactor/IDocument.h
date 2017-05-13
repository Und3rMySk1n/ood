#pragma once
#include <string>
#include <memory>
#include <boost\optional.hpp>
#include <boost\none.hpp>
#include "IParagraph.h"

class IDocument
{
public:
	virtual std::shared_ptr<IParagraph> InsertParagraph(const std::string& text,
		boost::optional<size_t> position = boost::none) = 0;


	virtual ~IDocument() = default;
};