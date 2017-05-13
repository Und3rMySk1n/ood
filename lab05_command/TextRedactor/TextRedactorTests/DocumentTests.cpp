#include "stdafx.h"
#include "../TextRedactor/Document.h"
#include <memory>

using namespace std;

struct Document_
{
	CDocument document;
};

BOOST_FIXTURE_TEST_SUITE(Document, Document_)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(have_no_title)
		{
			BOOST_CHECK_EQUAL(document.GetTitle(), "");
		}

		BOOST_AUTO_TEST_CASE(can_have_new_title)
		{
			document.SetTitle("Test title");
			BOOST_CHECK_EQUAL("Test title", document.GetTitle());
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()