#include "StdAfx.h"
#include "SignInScreen.h"
#include <iostream>
#include "NavigationManager.h"
#include "Utils.h"
#include "UsersManager.h"
#include "MainScreen.h"

CSignInScreen::CSignInScreen(void)
	:CScreenBase("Sign In")
{
	_currentStep = eEnterUserName;
}


CSignInScreen::~CSignInScreen(void)
{
}


void CSignInScreen::layoutContent()
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
			_passwordInput = true;
			std::cout << "Enter password:" << std::endl;
			break;
		}
	}
}

void CSignInScreen::handleInput(const std::string& userInput)
{
	switch(_currentStep) 
	{
		case eEnterUserName: 
		{
			//store username
			_currentStep = eEnterPassword;
			_userName = userInput;
			break;
		}

		case eEnterPassword: 
		{
			HashType currentPassword = CUtils::hash(userInput);
			if(!CUsersManager::instance().validateUser(_userName, currentPassword))
			{
				setCurrentError("Password or user incorrect!");
				return;
			}
			
			exit();
			CNavigationManager::instance().removeAllScreens();
			CNavigationManager::instance().pushScreen(new CMainScreen());
			break;
		}
	}
}