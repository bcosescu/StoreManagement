#include "StdAfx.h"
#include "WelcomeScreen.h"
#include <iostream>
#include "NavigationManager.h"
#include "SigninScreen.h"
#include "SignUpScreen.h"
#include "Utils.h"

CWelcomeScreen::CWelcomeScreen(void)
	:CScreenBase("Welcome")
{
	_shouldExitAppOption = true;
}


CWelcomeScreen::~CWelcomeScreen(void)
{
}

void CWelcomeScreen::layoutContent()
{
	std::cout << "[1] Login" << std::endl;
	std::cout << "[2] Sign up" << std::endl;
	std::cout << "[X] Exit";
}

void CWelcomeScreen::handleInput(const std::string& userInput)
{
	switch(CUtils::getNumericOption(userInput)) 
	{
		case 1: CNavigationManager::instance().pushScreen(new CSignInScreen()); break;
		case 2: CNavigationManager::instance().pushScreen(new CSignUpScreen()); break;
	}
}

bool CWelcomeScreen::handleBack()
{
	return false;
}

