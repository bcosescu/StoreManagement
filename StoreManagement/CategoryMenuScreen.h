#pragma once
#include "PaginatedScreen.h"
class CCategoryMenuScreen :
	public CPaginatedScreen
{
public:
	CCategoryMenuScreen(void);
	~CCategoryMenuScreen(void);

	void layoutContent();
	void handleInput(const std::string& userInput);
};

