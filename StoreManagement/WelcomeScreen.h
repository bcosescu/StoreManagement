#pragma once
#include "screenbase.h"
class CWelcomeScreen :
	public CScreenBase
{
public:
	CWelcomeScreen(void);
	~CWelcomeScreen(void);

	void layoutContent();
	void handleInput(const std::string& userInput);
	bool handleBack();
};

