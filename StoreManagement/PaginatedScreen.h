#pragma once
#include "screenbase.h"
class CPaginatedScreen :
	public CScreenBase
{
public:
	CPaginatedScreen(const std::string& screenName);
	~CPaginatedScreen(void);

	void layoutContent();
	void handleSpecialKey(int specialKey);

	void updateRecordsCount(int recordsCount);

protected:
	int _recordsCount;

private:
	int _pages;
	int _currentPage;
};

