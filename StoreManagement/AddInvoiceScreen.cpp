#include "StdAfx.h"
#include "AddInvoiceScreen.h"
#include "InvoicesManager.h"
#include "ProductsManager.h"
#include "CategoryManager.h"
#include "Utils.h"
#include "LayoutTableListHelper.h"

CAddInvoiceScreen::CAddInvoiceScreen(void)
	:CPaginatedScreen("Add Invoice")
{
	_currentStep = eEnterTo;
	_value = 0;
}



CAddInvoiceScreen::~CAddInvoiceScreen(void)
{
}

void CAddInvoiceScreen::layoutContent()
{
	const std::vector<CProduct*>& products = CProductsManager::instance().productsAsArray();
    updatePageInfo(7, (int)products.size());

	std::cout << "[B] Back" << std::endl;
	if(_currentStep == eEnterQuantity)
		CPaginatedScreen::layoutContent();

	CUtils::gotoxy(0, INPUT_LINE - 1);
	switch(_currentStep) {
		case eEnterTo: 
		{
			std::cout << "Enter name to whom invoice is for:" << std::endl;
			break;
		}
		case eEnterQuantity: 
		{
			std::cout << "Enter quantity:" << std::endl;
			break;
		}
	}
}

void CAddInvoiceScreen::handleInput(const std::string& userInput)
{
	switch(_currentStep) 
	{
		case eEnterTo: 
		{
			_currentStep = eEnterQuantity;
			_to = userInput;
			break;
		}

		case eEnterQuantity:
		{
			if(userInput == "" && _items.size() > 0)
			{
				CInvoicesManager::instance().createInvoice(_to, CUtils::currentDate(), _value, _items);
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
			if(quantity > product->quantity())
			{
				setCurrentError("Quantity requested is too big(That what she said)!");
				return;
			}

			_items.push_back(BuyItem(product->id(), quantity));
			_value += quantity * product->price();
			product->decreaseQuantity(quantity);
			selectLine(NO_SELECTION);
			break;
		}
	}
}

void CAddInvoiceScreen::layoutPage(int from, int records)
{
	CLayoutTableListHelper::layoutPageForProducts(std::cout, from, records, selectedLine());
}
