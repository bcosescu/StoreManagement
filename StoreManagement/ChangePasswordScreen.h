#pragma once
#include "screenbase.h"
class CChangePasswordScreen :
	public CScreenBase
{
	typedef enum { eEnterPassword, eEnterPasswordAgain } eStep;
public:
	CChangePasswordScreen(void);
	~CChangePasswordScreen(void);
	
	void layoutContent();
	void handleInput(const std::string& userInput);

private:
	eStep _currentStep;
	HashType _firstStepPassword;
};

