#include "StdAfx.h"
#include "ProductMenuScreen.h"
#include "Utils.h"
#include "Product.h"
#include "ProductsManager.h"
#include "NavigationManager.h"
#include "AddProductScreen.h"
#include "CategoryManager.h"

CProductMenuScreen::CProductMenuScreen(void)
	:CPaginatedScreen("Product Menu")
{
}


CProductMenuScreen::~CProductMenuScreen(void)
{
}

void CProductMenuScreen::layoutContent()
{
    const std::vector<CProduct*>& products = CProductsManager::instance().productsAsArray();
    updatePageInfo(7, (int)products.size());

    std::cout << "[1] Add Product" << std::endl;
    std::cout << "[2] Delete Product" << std::endl;
    std::cout << "[B] Back" << std::endl;
    CPaginatedScreen::layoutContent();
}

void CProductMenuScreen::handleInput(const std::string& userInput)
{
    switch(CUtils::getNumericOption(userInput)) 
    {
		case 1: CNavigationManager::instance().pushScreen(new CAddProductScreen()); break;
		case 2: 
        {
            setCurrentError("NOT IMPLEMENTED!");
            return;
        }
    }
}

void CProductMenuScreen::layoutPage(int from, int records)
{
    std::cout << std::endl;
    std::cout << "Current products:" << std::endl;

    std::cout << std::setw(ID_WIDTH) << std::right << "ID" << std::setw(SEPARATOR_WIDTH) << " " 
        << std::setw(PROD_NAME_WIDTH) << std::left << "NAME" << std::setw(SEPARATOR_WIDTH) << " " 
        << std::setw(PROD_DESCRIPTION_WIDTH) << std::left << "DESCRIPTION" << std::setw(SEPARATOR_WIDTH) << " " 
		<< std::setw(7) << std::right << "PRICE" << std::setw(SEPARATOR_WIDTH) << " " 
		<< std::setw(10) << std::right << "SUPP PRICE" << std::setw(SEPARATOR_WIDTH) << " "
		<< std::setw(QUANTITY_WIDTH) << std::right << "QNT" << std::left << std::setw(SEPARATOR_WIDTH) << " " 
		<< std::setw(10) << std::left << "CATEGORIES" 
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
			<< std::setw(10) << std::right << product->supplierPrice() << std::left << std::setw(SEPARATOR_WIDTH) << " "
			<< std::setw(QUANTITY_WIDTH) << std::right << product->quantity() << std::left;

		std::cout << std::setw(SEPARATOR_WIDTH) << " " << std::setw(10);

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