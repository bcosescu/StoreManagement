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

private:
    int _recordsCount;
    int _recordsOnPageCount;
	int _pages;
	int _currentPage;
};

