#include "StdAfx.h"
#include "SignUpScreen.h"
#include <iostream>
#include "NavigationManager.h"
#include "Utils.h"
#include "UsersManager.h"


CSignUpScreen::CSignUpScreen(void)
	:CScreenBase("Sign Up")
{
	_currentStep = eEnterUserName;
}


CSignUpScreen::~CSignUpScreen(void)
{
}

void CSignUpScreen::layoutContent()
{
	std::cout << "[B] Back" << std::endl;

	CUtils::gotoxy(0, INPUT_LINE - 1);
	switch(_currentStep) {
		case eEnterUserName: 
		{
			std::cout << "Enter username:" << std::endl;
			break;
		}
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

void CSignUpScreen::handleInput(const std::string& userInput)
{
	switch(_currentStep) 
	{
		case eEnterUserName: 
		{
			if(CUsersManager::instance().isUserNamePresent(userInput))
			{
				setCurrentError("Username is not valid!");
				return;
			}
			_passwordInput = true;
			_userName = userInput;
			_currentStep = eEnterPassword;
			break;
		}

		case eEnterPassword:
		{
			_passwordInput = true;
			//store password
			_currentStep = eEnterPasswordAgain;
			_firstStepPassword = CUtils::hash(userInput);
			break;
		}
		case eEnterPasswordAgain: 
		{
			//store password
			if(_firstStepPassword != CUtils::hash(userInput)) {
				setCurrentError("Password did not match!");
				return;
			}

			CUsersManager::instance().createUser(_userName, _firstStepPassword);
			exit();
			break;
		}
	}
}