#include "StdAfx.h"
#include "ChangePasswordScreen.h"
#include "UsersManager.h"
#include "Utils.h"


CChangePasswordScreen::CChangePasswordScreen(void)
	:CScreenBase("Change Password")
{
	_currentStep = eEnterPassword;
	_passwordInput = true;
}


CChangePasswordScreen::~CChangePasswordScreen(void)
{
}

void CChangePasswordScreen::layoutContent()
{
	std::cout << "[B] Back" << std::endl;

	CUtils::gotoxy(0, INPUT_LINE - 1);
	switch(_currentStep) {
		case eEnterPassword: 
		{
			std::cout << "Enter password:" << std::endl;
			break;
		}
		case eEnterPasswordAgain: 
		{
			std::cout << "Confirm password:" << std::endl;
			break;
		}
	}
}

void CChangePasswordScreen::handleInput(const std::string& userInput)
{
	switch(_currentStep) 
	{
		case eEnterPassword:
		{
			_firstStepPassword = CUtils::hash(userInput);
			_currentStep = eEnterPasswordAgain;
			break;
		}
		case eEnterPasswordAgain:
		{
			if(_firstStepPassword != CUtils::hash(userInput)) {
				setCurrentError("Password did not match!");
				return;
			}
			CUsersManager::instance().currentUser()->setNewPassword(_firstStepPassword);
			exit();
			break;
		}
	}
}