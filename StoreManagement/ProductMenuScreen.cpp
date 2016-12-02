#include "StdAfx.h"
#include "ProductMenuScreen.h"
#include "Utils.h"
#include "Product.h"
#include "ProductsManager.h"
#include "NavigationManager.h"
#include "AddProductScreen.h"
#include "LayoutTableListHelper.h"

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
	CLayoutTableListHelper::layoutPageForProducts(std::cout, from, records, selectedLine());
}