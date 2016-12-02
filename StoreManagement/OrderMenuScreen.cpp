#include "StdAfx.h"
#include "OrderMenuScreen.h"
#include "Utils.h"
#include "NavigationManager.h"
#include "OrdersManager.h"
#include "AddOrderScreen.h"
#include "LayoutTableListHelper.h"

COrderMenuScreen::COrderMenuScreen(void)
	:CPaginatedScreen("Order Menu")
{
	selectLine(0);
}


COrderMenuScreen::~COrderMenuScreen(void)
{
}

void COrderMenuScreen::layoutContent()
{
    const std::vector<COrder*>& orders = COrdersManager::instance().ordersAsArray();
    updatePageInfo(7, orders.size());

	std::cout << "[1] Add Order" << std::endl;
	std::cout << "[2] Delete Order" << std::endl;
	std::cout << "[B] Back" << std::endl;
	CPaginatedScreen::layoutContent();
}

void COrderMenuScreen::handleInput(const std::string& userInput)
{
	CScreenBase *screen = NULL;
	switch(CUtils::getNumericOption(userInput)) 
	{
		case 1: screen = new CAddOrderScreen(); break;
        case 2: 
        {
            setCurrentError("NOT IMPLEMENTED!");
            return;
        }
	}

	if(screen)
		CNavigationManager::instance().pushScreen(screen);
}

void COrderMenuScreen::layoutPage(int from, int records)
{
	CLayoutTableListHelper::layoutPageForOrders(std::cout, from, records, selectedLine());
}