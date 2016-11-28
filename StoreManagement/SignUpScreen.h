#pragma once
#include "screenbase.h"
#include "Utils.h"

class CSignUpScreen :
	public CScreenBase
{
	typedef enum { eEnterUserName, eEnterPassword, eEnterPasswordAgain } eStep;
public:
	CSignUpScreen(void);
	~CSignUpScreen(void);

	void layoutContent();
	void handleInput(const std::string& userInput);

private:
	eStep _currentStep;
	std::string _userName;
	HashType _firstStepPassword;
};

