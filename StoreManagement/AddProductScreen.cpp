#include "StdAfx.h"
#include "AddProductScreen.h"
#include "Utils.h"
#include "ProductsManager.h"
#include "CategoryManager.h"

CAddProductScreen::CAddProductScreen(void)
	:CPaginatedScreen("Add Product")
{
	_currentStep = eEnterName;
	_quantity = 0;
}


CAddProductScreen::~CAddProductScreen(void)
{
}

void CAddProductScreen::layoutContent()
{
	const std::vector<CCategory*>& categries = CCategoryManager::instance().categoriesAsArray();
    updatePageInfo(7, (int)categries.size());

	std::cout << "[B] Back" << std::endl;
	if(_currentStep == eEnterCategories)
		CPaginatedScreen::layoutContent();

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
		case eEnterQuantity: 
		{
			std::cout << "Enter quantity:" << std::endl;
			break;
		}
		case eEnterCategories:
		{
			if(_categories.size() > 0)
			{
				std::cout << "Enter another category id(if done just press ENTER):" << std::endl;
			} 
			else
			{
				std::cout << "Enter category id:" << std::endl;
			}
			break;
		}
	}
}

void CAddProductScreen::handleInput(const std::string& userInput)
{
	switch(_currentStep) 
	{
		case eEnterName: 
		{
			_currentStep = eEnterDescription;
			_productName = userInput;
			break;
		}

		case eEnterDescription:
		{
			_currentStep = eEnterQuantity;
			_productDescription = userInput;
			break;
		}

		case eEnterQuantity: 
		{	
			if(!CUtils::isValidInt(userInput))
			{
				setCurrentError("Invalid input!");
				return;
			}

			_currentStep = eEnterCategories;
			_quantity = CONVERT_TO_INT(userInput);
			break;
		}

		case eEnterCategories:
		{
			if(userInput == "" && _categories.size() > 0)
			{
				CProductsManager::instance().createProduct(_productName, _productDescription, _quantity, _categories);
				exit();
				return;
			}

			if(!CUtils::isValidInt(userInput))
			{
				setCurrentError("Invalid input!");
				return;
			}

			ID categoryId = CONVERT_TO_ID(userInput);
			if(!CCategoryManager::instance().category(categoryId))
			{
				setCurrentError("Invalid category id!");
				return;
			}
			_categories.push_back(categoryId);
			break;
		}
	}
}

void CAddProductScreen::layoutPage(int from, int records)
{
	if(_currentStep != eEnterCategories)
		return;

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