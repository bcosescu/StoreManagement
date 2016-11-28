#include "StdAfx.h"
#include "MainScreen.h"
#include <iostream>
#include "Utils.h"
#include "NavigationManager.h"
#include "UsersManager.h"
#include "ChangePasswordScreen.h"
#include "CategoryMenuScreen.h"
#include "ProductMenuScreen.h"

CMainScreen::CMainScreen(void)
	:CScreenBase("Main")
{
	_shouldExitAppOption = true;
}


CMainScreen::~CMainScreen(void)
{
}

void CMainScreen::layoutContent()
{
	std::cout << "[1] Change Password" << std::endl;
	std::cout << "[2] Category Menu" << std::endl;
	std::cout << "[3] Product Menu" << std::endl;
	std::cout << "[4] Generate Something" << std::endl;
	std::cout << "[X] Exit" << std::endl;
}

void CMainScreen::handleInput(const std::string& userInput)
{
	switch(CUtils::getNumericOption(userInput)) 
	{
		case 1: CNavigationManager::instance().pushScreen(new CChangePasswordScreen()); break;
		case 2: CNavigationManager::instance().pushScreen(new CCategoryMenuScreen()); break;
		case 3: CNavigationManager::instance().pushScreen(new CProductMenuScreen()); break;
	}
}

bool CMainScreen::handleBack()
{
	return false;
}