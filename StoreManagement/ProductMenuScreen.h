#pragma once
#include "screenbase.h"
class CProductMenuScreen :
	public CScreenBase
{
public:
	CProductMenuScreen(void);
	~CProductMenuScreen(void);

	void layoutContent();
	void handleInput(const std::string& userInput);
};

