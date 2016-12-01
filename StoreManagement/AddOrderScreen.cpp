#include "StdAfx.h"
#include "AddOrderScreen.h"
#include "OrdersManager.h"
#include "ProductsManager.h"
#include "Utils.h"
#include "CategoryManager.h"

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
			if(quantity > product->quantity())
			{
				setCurrentError("Quantity requested is too big(That what she said)!");
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
    std::cout << std::endl;
    std::cout << "Current products:" << std::endl;

    std::cout << std::setw(ID_WIDTH) << std::right << "ID" << std::setw(SEPARATOR_WIDTH) << " " 
        << std::setw(PROD_NAME_WIDTH) << std::left << "NAME" << std::setw(SEPARATOR_WIDTH) << " " 
        << std::setw(PROD_DESCRIPTION_WIDTH) << "DESCRIPTION" << std::setw(SEPARATOR_WIDTH) << " " 
		<< std::setw(7) << "PRICE" << std::setw(SEPARATOR_WIDTH) << " " 
		<< std::setw(QUANTITY_WIDTH) << std::right << "QNT" << std::left << std::setw(SEPARATOR_WIDTH) << " " 
		<< std::setw(10) << "CATEGORIES" 
		<< std::endl << std::endl;

    const std::vector<CProduct*>& products = CProductsManager::instance().productsAsArray();
    for(int i = 0; i < records; i++) 
    {
        CProduct* product = products[from + i];
		CUtils::consoleColor(isLineSelected(from + i) ? SELECTED_COLOR : NORMAL_COLOR);
        std::cout << std::setw(ID_WIDTH) << std::right << product->id() << std::setw(SEPARATOR_WIDTH) << " " 
            << std::setw(PROD_NAME_WIDTH) << std::left << product->name() << std::setw(SEPARATOR_WIDTH) << " " 
            << std::setw(PROD_DESCRIPTION_WIDTH) << product->description() << std::setw(SEPARATOR_WIDTH) << " " 
			<< std::setw(7) << std::right << product->price() << std::left << std::setw(SEPARATOR_WIDTH) << " " 
			<< std::setw(QUANTITY_WIDTH) << std::right << product->quantity() << std::left;

		std::cout << std::setw(SEPARATOR_WIDTH) << " " << std::setw(20);

		const std::vector<ID>& categories = product->categories();
		std::stringstream ss;
		for(size_t j = 0; j < categories.size(); j++)
		{
			CCategory * category = CCategoryManager::instance().category(categories[j]);
			if(category)
			{
				ss << category->name();
				if(j != categories.size() - 1)
					ss << ',';
			}
		}
		std::cout << ss.str() << std::endl;
		CUtils::consoleColor(NORMAL_COLOR);
    }
}
