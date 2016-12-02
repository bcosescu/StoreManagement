#include "StdAfx.h"
#include "AddProductScreen.h"
#include "Utils.h"
#include "ProductsManager.h"
#include "LayoutTableListHelper.h"
#include "CategoryManager.h"

CAddProductScreen::CAddProductScreen(void)
	:CPaginatedScreen("Add Product")
{
	_currentStep = eEnterName;
	_price = 0;
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
		case eEnterPrice:
		{
			selectLine(0);
			std::cout << "Enter price:" << std::endl;
			break;
		}
		case eEnterSupplierPrice:
		{
			selectLine(0);
			std::cout << "Enter supplier price:" << std::endl;
			break;
		}
		case eEnterCategories:
		{
			if(_categories.size() > 0)
			{
				std::cout << "Select another category id(if done just press ENTER):" << std::endl;
			} 
			else
			{
				std::cout << "Select category id:" << std::endl;
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
			_currentStep = eEnterPrice;
			_productDescription = userInput;
			break;
		}

		case eEnterPrice:
		{
			_currentStep = eEnterSupplierPrice;
			_price = CONVERT_TO_DOUBLE(userInput);
			break;
		}

		case eEnterSupplierPrice:
		{
			_currentStep = eEnterCategories;
			_supplierPrice = CONVERT_TO_DOUBLE(userInput);
			break;
		}

		case eEnterCategories:
		{
			if(userInput == "" && selectedLine() != NO_SELECTION)
			{
				const std::vector<CCategory*>& categories = CCategoryManager::instance().categoriesAsArray();
				bool bAlreadyAdded = false;
				for(size_t i = 0; i < _categories.size() && !bAlreadyAdded; i++)
				{
					bAlreadyAdded = _categories[i] == selectedLine();
				}

				if(bAlreadyAdded)
					break;

				_categories.push_back(categories[selectedLine()]->id());
				selectLine(NO_SELECTION);
				break;
			}

			if(userInput == "" && _categories.size() > 0)
			{
				CProductsManager::instance().createProduct(_productName, _productDescription, _price, _supplierPrice, _categories);
				exit();
				return;
			}

			if(!CUtils::isValidInt(userInput))
			{
				setCurrentError("Invalid input!");
				return;
			}

			break;
		}
	}
}

void CAddProductScreen::layoutPage(int from, int records)
{
	if(_currentStep != eEnterCategories)
		return;

	CLayoutTableListHelper::layoutPageForCategories(std::cout, from, records, selectedLine());
}