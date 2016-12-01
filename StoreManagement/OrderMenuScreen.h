#pragma once
#include "paginatedscreen.h"

class COrderMenuScreen :
	public CPaginatedScreen
{
public:
	COrderMenuScreen(void);
	~COrderMenuScreen(void);
	
	void layoutContent();
	void handleInput(const std::string& userInput);
    void layoutPage(int from, int records);
};