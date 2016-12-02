#include "StdAfx.h"
#include "AddOrderScreen.h"
#include "OrdersManager.h"
#include "ProductsManager.h"
#include "Utils.h"
#include "CategoryManager.h"
#include "LayoutTableListHelper.h"

CAddOrderScreen::CAddOrderScreen(void)
	:CPaginatedScreen("Add Order")
{
	_currentStep = eEnterFrom;
	_value = 0;
}

CAddOrderScreen::~CAddOrderScreen(void)
{
}

void CAddOrderScreen::layoutContent()
{
	const std::vector<CProduct*>& products = CProductsManager::instance().productsAsArray();
    updatePageInfo(7, (int)products.size());

	std::cout << "[B] Back" << std::endl;
	if(_currentStep == eEnterQuantity)
		CPaginatedScreen::layoutContent();

	CUtils::gotoxy(0, INPUT_LINE - 1);
	switch(_currentStep) {
		case eEnterFrom: 
		{
			std::cout << "Enter name to whom the order is from:" << std::endl;
			break;
		}
		case eEnterQuantity: 
		{
			std::cout << "Enter quantity:" << std::endl;
			break;
		}
	}
}

void CAddOrderScreen::handleInput(const std::string& userInput)
{
	switch(_currentStep) 
	{
		case eEnterFrom: 
		{
			_currentStep = eEnterQuantity;
			_from = userInput;
			break;
		}

		case eEnterQuantity:
		{
			if(userInput == "" && _items.size() > 0)
			{
				COrdersManager::instance().createOrder(_from, CUtils::currentDate(), _value, _items);
				exit();
				return;
			}
			
			if(!CUtils::isValidInt(userInput))
			{
				setCurrentError("Invalid input!");
				return;
			}

			if(selectedLine() == NO_SELECTION)
			{
				setCurrentError("Select a product before entering quantity!");
				return;
			}

			int quantity = CONVERT_TO_INT(userInput);
			CProduct* product = CProductsManager::instance().productsAsArray()[selectedLine()];
			if(quantity <= 0)
			{
				setCurrentError("Invalid quantity!");
				return;
			}

			_items.push_back(BuyItem(product->id(), quantity));
			_value += quantity * product->supplierPrice();
			product->increaseQuantity(quantity);
			selectLine(NO_SELECTION);
			break;
		}
	}
}

void CAddOrderScreen::layoutPage(int from, int records)
{
	CLayoutTableListHelper::layoutPageForProducts(std::cout, from, records, selectedLine());
}
