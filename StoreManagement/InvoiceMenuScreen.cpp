#include "StdAfx.h"
#include "InvoiceMenuScreen.h"
#include "Utils.h"
#include "NavigationManager.h"
#include "InvoicesManager.h"
#include "AddInvoiceScreen.h"
#include "LayoutTableListHelper.h"

CInvoiceMenuScreen::CInvoiceMenuScreen(void)
	:CPaginatedScreen("Invoice Menu")
{
	selectLine(0);
}


CInvoiceMenuScreen::~CInvoiceMenuScreen(void)
{
}

void CInvoiceMenuScreen::layoutContent()
{
    const std::vector<CInvoice*>& invoices = CInvoicesManager::instance().invoicesAsArray();
    updatePageInfo(7, invoices.size());

	std::cout << "[1] Add Invoice" << std::endl;
	std::cout << "[2] Delete Invoice" << std::endl;
	std::cout << "[B] Back" << std::endl;
	CPaginatedScreen::layoutContent();
}

void CInvoiceMenuScreen::handleInput(const std::string& userInput)
{
	CScreenBase *screen = NULL;
	switch(CUtils::getNumericOption(userInput)) 
	{
		case 1: screen = new CAddInvoiceScreen(); break;
        case 2: 
        {
            setCurrentError("NOT IMPLEMENTED!");
            return;
        }
	}

	if(screen)
		CNavigationManager::instance().pushScreen(screen);
}

void CInvoiceMenuScreen::layoutPage(int from, int records)
{
	CLayoutTableListHelper::layoutPageForInvoices(std::cout, from, records, selectedLine());
}