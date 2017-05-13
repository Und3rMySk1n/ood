#include "stdafx.h"
#include "Document.h"

using namespace std;

void CDocument::SetTitle(const std::string & title)
{
	m_title = title;
}

std::string CDocument::GetTitle() const
{
	return m_title;
}