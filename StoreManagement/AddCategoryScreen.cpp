#include "StdAfx.h"
#include "AddCategoryScreen.h"
#include "Utils.h"
#include "CategoryManager.h"

CAddCategoryScreen::CAddCategoryScreen(void)
	:CScreenBase("Add Category")
{
	_currentStep = eEnterName;
}


CAddCategoryScreen::~CAddCategoryScreen(void)
{
}

void CAddCategoryScreen::layoutContent()
{
	std::cout << "[B] Back" << std::endl;
	CUtils::gotoxy(0, INPUT_LINE - 1);
	switch(_currentStep) {
		case eEnterName: 
		{
			std::cout << "Enter name:" << std::endl;
			break;
		}
		case eEnterDescription: 
		{
			std::cout << "Enter description:" << std::endl;
			break;
		}
	}
}

void CAddCategoryScreen::handleInput(const std::string& userInput)
{
	switch(_currentStep) 
	{
		case eEnterName: 
		{
			if(CCategoryManager::instance().isCategoryNamePresent(userInput))
			{
				setCurrentError("Category name already exists!");
				return;
			}

			_currentStep = eEnterDescription;
			_categoryName = userInput;
			break;
		}

		case eEnterDescription: 
		{	
			CCategoryManager::instance().createCategory(_categoryName, userInput);
			exit();
			break;
		}
	}
}