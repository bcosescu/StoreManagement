#pragma once
#include "screenbase.h"
class CSignInScreen :
	public CScreenBase
{
	typedef enum { eEnterUserName, eEnterPassword } eStep;

public:
	CSignInScreen(void);
	~CSignInScreen(void);

	void layoutContent();
	void handleInput(const std::string& userInput);

private:
	eStep _currentStep;
	std::string _userName;
};

