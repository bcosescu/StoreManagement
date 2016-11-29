#include "StdAfx.h"
#include "PaginatedScreen.h"
#include "Utils.h"
#include <math.h> 


CPaginatedScreen::CPaginatedScreen(const std::string& screenName)
	:CScreenBase(screenName)
{
	_pages = 1;
	_currentPage = 1;
	_recordsCount = 0;
    _recordsOnPageCount = 0;
}


CPaginatedScreen::~CPaginatedScreen(void)
{
}

void CPaginatedScreen::updatePageInfo(int recordsOnPage, int totalRecordsOnPage)
{
    _recordsCount = totalRecordsOnPage;
    _recordsOnPageCount = recordsOnPage;
    _pages = max(1, (int)ceil(_recordsCount / (double)_recordsOnPageCount));
}

void CPaginatedScreen::layoutContent()
{
	std::ios init(NULL);
    init.copyfmt(std::cout);

	std::cout << std::setfill(' ');
    layoutPage(_recordsOnPageCount * (_currentPage - 1), _currentPage == _pages ?  _recordsCount - _recordsOnPageCount * (_currentPage - 1) : _recordsOnPageCount);
    std::cout << std::endl << "      Page " << _currentPage << " of " << _pages << std::endl;
    std::cout << std::endl << "Navigate with <-/-> between pages" << std::endl;
	std::cout.copyfmt(init);
}

		
bool CPaginatedScreen::handleSpecialKey(int specialKey)
{
    bool handled = false;
	switch(specialKey)
	{
		case KEY_LEFT:
		{
			_currentPage = max(1, _currentPage - 1);
            handled = true;
			break;
		}
		
		case KEY_RIGHT:
		{
			_currentPage = min(_currentPage + 1, _pages);
            handled = true;
			break;
		}

	}
    return handled;
}