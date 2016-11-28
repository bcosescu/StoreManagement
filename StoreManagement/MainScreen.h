#pragma once
#include "screenbase.h"
class CMainScreen :
	public CScreenBase
{
public:
	CMainScreen(void);
	~CMainScreen(void);

	void layoutContent();
	void handleInput(const std::string& userInput);
	bool handleBack();
};

