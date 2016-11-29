#include "StdAfx.h"
#include "CategoryMenuScreen.h"
#include "Utils.h"
#include "NavigationManager.h"
#include "AddCategoryScreen.h"
#include "CategoryManager.h"

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
/*		case 1: CNavigationManager::instance().pushScreen(new CChangePasswordScreen()); break;
		case 2: CNavigationManager::instance().pushScreen(new CChangePasswordScreen()); break;
		case 3: CNavigationManager::instance().pushScreen(new CChangePasswordScreen()); break;
*/
	}
}

void CCategoryMenuScreen::layoutPage(int from, int records)
{
    std::cout << std::endl;
    std::cout << "Current categories:" << std::endl;

    std::cout << std::setw(ID_WIDTH) << std::right << "ID" << std::setw(SEPARATOR_WIDTH) << " " 
              << std::setw(NAME_WIDTH) << std::left << "NAME" << std::setw(SEPARATOR_WIDTH) << " " 
              << std::setw(DESCRIPTION_WIDTH) << "DESCRIPTION" << std::endl << std::endl;

    const std::vector<CCategory*>& categories = CCategoryManager::instance().categoriesAsArray();
    for(int i = 0; i < records; i++) 
    {
        CCategory* category = categories[from + i];
        std::cout << std::setw(ID_WIDTH) << std::right << category->id() << std::setw(SEPARATOR_WIDTH) << " " 
                  << std::setw(NAME_WIDTH) << std::left << category->name() << std::setw(SEPARATOR_WIDTH) << " " 
                  << std::setw(DESCRIPTION_WIDTH) << category->description() << std::endl;
    }
}