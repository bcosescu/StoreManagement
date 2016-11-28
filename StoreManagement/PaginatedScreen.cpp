#include "StdAfx.h"
#include "PaginatedScreen.h"
#include "Utils.h"
#include <iomanip>


CPaginatedScreen::CPaginatedScreen(const std::string& screenName)
	:CScreenBase(screenName)
{
	_pages = 1;
	_currentPage = 1;
	_recordsCount = 0;
}


CPaginatedScreen::~CPaginatedScreen(void)
{
}

void CPaginatedScreen::layoutContent()
{
	int x = 0;
	int y = 0;
	CUtils::wherexy(x, y);

	_pages = min(1, ceil(_recordsCount / double(INPUT_LINE - 3 - y)));
	std::ios init(NULL);
    init.copyfmt(std::cout);

	std::cout << std::setfill(' ');
	std::cout << std::setw(5) << std::right << "ID" << std::setw(2) << " " << std::setw(20) << std::left << "NAME" << std::setw(30) << "DESCRIPTION" << std::endl;
	std::cout.copyfmt(init);
}
		
void CPaginatedScreen::handleSpecialKey(int specialKey)
{
	switch(specialKey)
	{
		case KEY_LEFT:
		{
			_currentPage = min(1, _currentPage - 1);
			break;
		}
		
		case KEY_RIGHT:
		{
			_currentPage = max(_currentPage + 1, _pages);
			break;
		}

	}
}