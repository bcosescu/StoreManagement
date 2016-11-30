#include "StdAfx.h"
#include "InvoiceMenuScreen.h"
#include "Utils.h"
#include "NavigationManager.h"
#include "InvoicesManager.h"
#include "AddInvoiceScreen.h"

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
    std::cout << std::endl;
    std::cout << "Current invoices:" << std::endl;

    std::cout << std::setw(ID_WIDTH) << std::right << "ID" << std::setw(SEPARATOR_WIDTH) << " " 
              << std::setw(DATE_WIDTH) << std::left << "DATE" << std::setw(SEPARATOR_WIDTH) << " " 
              << std::setw(NAME_WIDTH) << "TO" << std::setw(SEPARATOR_WIDTH) << " "
			  << std::setw(VALUE_WIDTH) << "VALUE" << std::setw(SEPARATOR_WIDTH) << " "
			  << std::endl << std::endl;

    const std::vector<CInvoice*>& invoices = CInvoicesManager::instance().invoicesAsArray();
    for(int i = 0; i < records; i++) 
    {
		CUtils::consoleColor(isLineSelected(from + i) ? SELECTED_COLOR : NORMAL_COLOR);
        CInvoice* invoice = invoices[from + i];
        std::cout << std::setw(ID_WIDTH) << std::right << invoice->id() << std::setw(SEPARATOR_WIDTH) << " " 
                  << std::setw(DATE_WIDTH) << std::left << invoice->date() << std::setw(SEPARATOR_WIDTH) << " " 
				  << std::setw(NAME_WIDTH) << std::left << invoice->to() << std::setw(SEPARATOR_WIDTH) << " "
                  << std::setw(VALUE_WIDTH) << std::left << invoice->value() << std::endl;
		CUtils::consoleColor(NORMAL_COLOR);
    }
}