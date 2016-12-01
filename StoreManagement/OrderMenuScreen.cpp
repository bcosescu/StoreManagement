#include "StdAfx.h"
#include "OrderMenuScreen.h"
#include "Utils.h"
#include "NavigationManager.h"
#include "OrdersManager.h"
#include "AddOrderScreen.h"

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
    std::cout << std::endl;
    std::cout << "Current orders:" << std::endl;

    std::cout << std::setw(ID_WIDTH) << std::right << "ID" << std::setw(SEPARATOR_WIDTH) << " " 
              << std::setw(DATE_WIDTH) << std::left << "DATE" << std::setw(SEPARATOR_WIDTH) << " " 
              << std::setw(NAME_WIDTH) << "FROM" << std::setw(SEPARATOR_WIDTH) << " "
			  << std::setw(VALUE_WIDTH) << "VALUE" << std::setw(SEPARATOR_WIDTH) << " "
			  << std::endl << std::endl;

    const std::vector<COrder*>& orders = COrdersManager::instance().ordersAsArray();
    for(int i = 0; i < records; i++) 
    {
		CUtils::consoleColor(isLineSelected(from + i) ? SELECTED_COLOR : NORMAL_COLOR);
        COrder* order = orders[from + i];
        std::cout << std::setw(ID_WIDTH) << std::right << order->id() << std::setw(SEPARATOR_WIDTH) << " " 
                  << std::setw(DATE_WIDTH) << std::left << order->date() << std::setw(SEPARATOR_WIDTH) << " " 
				  << std::setw(NAME_WIDTH) << std::left << order->from() << std::setw(SEPARATOR_WIDTH) << " "
                  << std::setw(VALUE_WIDTH) << std::left << order->value() << std::endl;
		CUtils::consoleColor(NORMAL_COLOR);
    }
}