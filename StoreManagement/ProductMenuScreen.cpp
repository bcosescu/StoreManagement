#include "StdAfx.h"
#include "ProductMenuScreen.h"
#include "Utils.h"

CProductMenuScreen::CProductMenuScreen(void)
	:CScreenBase("Product Menu")
{
}


CProductMenuScreen::~CProductMenuScreen(void)
{
}

void CProductMenuScreen::layoutContent()
{
	std::cout << "[1] List Products" << std::endl;
	std::cout << "[2] Add Product" << std::endl;
	std::cout << "[3] Delete Product" << std::endl;
	std::cout << "[B] Back" << std::endl;
}

void CProductMenuScreen::handleInput(const std::string& userInput)
{
	switch(CUtils::getNumericOption(userInput)) 
	{
/*		case 1: CNavigationManager::instance().pushScreen(new CChangePasswordScreen()); break;
		case 2: CNavigationManager::instance().pushScreen(new CChangePasswordScreen()); break;
		case 3: CNavigationManager::instance().pushScreen(new CChangePasswordScreen()); break;
*/
	}
}