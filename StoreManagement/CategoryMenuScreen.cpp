#include "StdAfx.h"
#include "CategoryMenuScreen.h"
#include "Utils.h"
#include "NavigationManager.h"
#include "AddCategoryScreen.h"


CCategoryMenuScreen::CCategoryMenuScreen(void)
	:CPaginatedScreen("Category Menu")
{
}


CCategoryMenuScreen::~CCategoryMenuScreen(void)
{
}

void CCategoryMenuScreen::layoutContent()
{
	std::cout << "[1] Add Category" << std::endl;
	std::cout << "[2] Delete Category" << std::endl;
	std::cout << "[B] Back" << std::endl;
	CPaginatedScreen::layoutContent();
}

void CCategoryMenuScreen::handleInput(const std::string& userInput)
{
	switch(CUtils::getNumericOption(userInput)) 
	{
		case 2: CNavigationManager::instance().pushScreen(new CAddCategoryScreen()); break;
/*		case 1: CNavigationManager::instance().pushScreen(new CChangePasswordScreen()); break;
		case 2: CNavigationManager::instance().pushScreen(new CChangePasswordScreen()); break;
		case 3: CNavigationManager::instance().pushScreen(new CChangePasswordScreen()); break;
*/
	}
}
