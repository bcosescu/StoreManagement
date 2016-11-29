#include "StdAfx.h"
#include "ProductMenuScreen.h"
#include "Utils.h"
#include "Product.h"
#include "ProductsManager.h"
#include "NavigationManager.h"

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
   // case 1: CNavigationManager::instance().pushScreen(new CAddCategoryScreen()); break;
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
        << std::setw(NAME_WIDTH) << std::left << "NAME" << std::setw(SEPARATOR_WIDTH) << " " 
        << std::setw(DESCRIPTION_WIDTH) << "DESCRIPTION" << std::endl << std::endl;

    const std::vector<CProduct*>& products = CProductsManager::instance().productsAsArray();
    for(int i = 0; i < records; i++) 
    {
        CProduct* product = products[from + i];
        std::cout << std::setw(ID_WIDTH) << std::right << product->id() << std::setw(SEPARATOR_WIDTH) << " " 
            << std::setw(NAME_WIDTH) << std::left << product->name() << std::setw(SEPARATOR_WIDTH) << " " 
            << std::setw(DESCRIPTION_WIDTH) << product->description() << std::endl;
    }
}