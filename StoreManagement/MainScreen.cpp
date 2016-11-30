#include "StdAfx.h"
#include "MainScreen.h"
#include <iostream>
#include "Utils.h"
#include "NavigationManager.h"
#include "UsersManager.h"
#include "ChangePasswordScreen.h"
#include "CategoryMenuScreen.h"
#include "ProductMenuScreen.h"
#include "InvoiceMenuScreen.h"

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
	std::cout << "[4] Invoices Menu" << std::endl;
	std::cout << "[X] Exit" << std::endl;
}

void CMainScreen::handleInput(const std::string& userInput)
{
	CScreenBase *screen = NULL;
	switch(CUtils::getNumericOption(userInput)) 
	{
		case 1: screen = new CChangePasswordScreen(); break;
		case 2: screen = new CCategoryMenuScreen(); break;
		case 3: screen = new CProductMenuScreen(); break;
		case 4: screen = new CInvoiceMenuScreen(); break;
	}

	if(screen)
		CNavigationManager::instance().pushScreen(screen);
}

bool CMainScreen::handleBack()
{
	return false;
}