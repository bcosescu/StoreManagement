#include "StdAfx.h"
#include "CategoryMenuScreen.h"
#include "Utils.h"
#include "NavigationManager.h"
#include "AddCategoryScreen.h"
#include "CategoryManager.h"
#include "LayoutTableListHelper.h"

CCategoryMenuScreen::CCategoryMenuScreen(void)
	:CPaginatedScreen("Category Menu")
{
}


CCategoryMenuScreen::~CCategoryMenuScreen(void)
{
}

void CCategoryMenuScreen::layoutContent()
{
    const std::vector<CCategory*>& categories = CCategoryManager::instance().categoriesAsArray();
    updatePageInfo(7, categories.size());

	std::cout << "[1] Add Category" << std::endl;
	std::cout << "[2] Delete Category" << std::endl;
	std::cout << "[B] Back" << std::endl;
	CPaginatedScreen::layoutContent();
}

void CCategoryMenuScreen::handleInput(const std::string& userInput)
{
	switch(CUtils::getNumericOption(userInput)) 
	{
		case 1: CNavigationManager::instance().pushScreen(new CAddCategoryScreen()); break;
        case 2: 
        {
            setCurrentError("NOT IMPLEMENTED!");
            return;
        }
	}
}

void CCategoryMenuScreen::layoutPage(int from, int records)
{
	CLayoutTableListHelper::layoutPageForCategories(std::cout, from, records, selectedLine());
}