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
	_currentSelectedLine = NO_SELECTION;
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
    layoutPage(startRecordsPosInCurrentPage(), endRecordsPosInCurrentPage() - startRecordsPosInCurrentPage() + 1);
    std::cout << std::endl << "      Page " << _currentPage << " of " << _pages << std::endl;
    std::cout << std::endl << "Use arrows key to move between pages!!!" << std::endl;
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

		case KEY_UP:
		{
			if(_currentSelectedLine == 0)
			{
				handled = true;
				break;
			}

			if(!isCurrentSelectedLineInCurrentPage())
				_currentSelectedLine = endRecordsPosInCurrentPage();
			else
				_currentSelectedLine -= 1;

			verifyCurrentPage();
			handled = true;
			break;
		}

		case KEY_DOWN:
		{
			if(_currentSelectedLine == _recordsCount - 1)
			{
				handled = true;
				break;
			}

			if(!isCurrentSelectedLineInCurrentPage())
				_currentSelectedLine = startRecordsPosInCurrentPage();
			else
				_currentSelectedLine += 1;

			verifyCurrentPage();
			handled = true;
			break;
		}
	}
    return handled;
}

void CPaginatedScreen::verifyCurrentPage()
{
	if(_currentSelectedLine < startRecordsPosInCurrentPage())
		_currentPage = max(1, _currentPage - 1);
	else if (_currentSelectedLine > endRecordsPosInCurrentPage())
		_currentPage = min(_currentPage + 1, _pages);
}

bool CPaginatedScreen::isCurrentSelectedLineInCurrentPage()
{
	int begin = startRecordsPosInCurrentPage();
	int end = endRecordsPosInCurrentPage();
	return _currentSelectedLine >= begin && _currentSelectedLine <= end;
}

int CPaginatedScreen::startRecordsPosInCurrentPage()
{
	return _recordsOnPageCount * (_currentPage - 1);
}

int	CPaginatedScreen::endRecordsPosInCurrentPage()
{
	int recordsOnCurrentPage =  _currentPage == _pages ?  _recordsCount - _recordsOnPageCount * (_currentPage - 1) : _recordsOnPageCount;
	return startRecordsPosInCurrentPage() + recordsOnCurrentPage - 1;
}