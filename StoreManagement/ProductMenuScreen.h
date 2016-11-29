#pragma once
#include "PaginatedScreen.h"
class CProductMenuScreen :
	public CPaginatedScreen
{
public:
	CProductMenuScreen(void);
	~CProductMenuScreen(void);

	void layoutContent();
	void handleInput(const std::string& userInput);
    void layoutPage(int from, int records);
};

