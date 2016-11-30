#pragma once
#include "screenbase.h"
#include <iomanip>

class CPaginatedScreen :
	public CScreenBase
{
public:
	CPaginatedScreen(const std::string& screenName);
	~CPaginatedScreen(void);

	void layoutContent();
	bool handleSpecialKey(int specialKey);
    virtual void layoutPage(int from, int records) = 0;

protected:
    void updatePageInfo(int recordsOnPage, int totalRecordsOnPage);
	bool isLineSelected(int line) { return line == _currentSelectedLine; }
	int  selectedLine() { return _currentSelectedLine; }
	void selectLine(int line) { _currentSelectedLine = line; }

private:
	void verifyCurrentPage();
	bool isCurrentSelectedLineInCurrentPage();
	int startRecordsPosInCurrentPage();
	int	endRecordsPosInCurrentPage();

    int _recordsCount;
    int _recordsOnPageCount;
	int _pages;
	int _currentPage;
	int _currentSelectedLine;
};

