#include "StdAfx.h"
#include "LayoutTableListHelper.h"
#include <vector>
#include <iomanip>
#include "CategoryManager.h"
#include "ProductsManager.h"
#include "Utils.h"
#include "OrdersManager.h"
#include "InvoicesManager.h"

void CLayoutTableListHelper::layoutPageForCategories(std::ostream& stream, int from, int records, int selectedLine)
{
	stream << std::endl;
    stream << "Current categories:" << std::endl;

    stream << std::setw(ID_WIDTH) << std::right << "ID" << std::setw(SEPARATOR_WIDTH) << " " 
              << std::setw(NAME_WIDTH) << std::left << "NAME" << std::setw(SEPARATOR_WIDTH) << " " 
              << std::setw(DESCRIPTION_WIDTH) << "DESCRIPTION" << std::endl << std::endl;

    const std::vector<CCategory*>& categories = CCategoryManager::instance().categoriesAsArray();
    for(int i = 0; i < records; i++) 
    {
        CCategory* category = categories[from + i];
		CUtils::consoleColor( from + i == selectedLine ? SELECTED_COLOR : NORMAL_COLOR);
        stream	<< std::setw(ID_WIDTH) << std::right << category->id() << std::setw(SEPARATOR_WIDTH) << " " 
                << std::setw(NAME_WIDTH) << std::left << category->name() << std::setw(SEPARATOR_WIDTH) << " " 
                << std::setw(DESCRIPTION_WIDTH) << category->description() << std::endl;
		CUtils::consoleColor(NORMAL_COLOR);
	}
}

void CLayoutTableListHelper::layoutPageForProducts(std::ostream& stream, int from, int records, int selectedLine)
{
    stream << std::endl;
    stream << "Current products:" << std::endl;

    stream << std::setw(ID_WIDTH) << std::right << "ID" << std::setw(SEPARATOR_WIDTH) << " " 
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
		CUtils::consoleColor(from + i == selectedLine ? SELECTED_COLOR : NORMAL_COLOR);
        stream << std::setw(ID_WIDTH) << std::right << product->id() << std::setw(SEPARATOR_WIDTH) << " " 
            << std::setw(PROD_NAME_WIDTH) << std::left << product->name() << std::setw(SEPARATOR_WIDTH) << " " 
            << std::setw(PROD_DESCRIPTION_WIDTH) << product->description() << std::setw(SEPARATOR_WIDTH) << " " 
			<< std::setw(7) << std::right << product->price() << std::left << std::setw(SEPARATOR_WIDTH) << " " 
			<< std::setw(10) << std::right << product->supplierPrice() << std::left << std::setw(SEPARATOR_WIDTH) << " "
			<< std::setw(QUANTITY_WIDTH) << std::right << product->quantity() << std::left;

		stream << std::setw(SEPARATOR_WIDTH) << " " << std::setw(10);

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
		stream << ss.str() << std::endl;
		CUtils::consoleColor(NORMAL_COLOR);
    }
}

void CLayoutTableListHelper::layoutPageForInvoices(std::ostream& stream, int from, int records, int selectedLine)
{
	stream << std::endl;
    stream << "Current invoices:" << std::endl;

    stream << std::setw(ID_WIDTH) << std::right << "ID" << std::setw(SEPARATOR_WIDTH) << " " 
              << std::setw(DATE_WIDTH) << std::left << "DATE" << std::setw(SEPARATOR_WIDTH) << " " 
              << std::setw(NAME_WIDTH) << "TO" << std::setw(SEPARATOR_WIDTH) << " "
			  << std::setw(VALUE_WIDTH) << "VALUE" << std::setw(SEPARATOR_WIDTH) << " "
			  << std::endl << std::endl;

    const std::vector<CInvoice*>& invoices = CInvoicesManager::instance().invoicesAsArray();
    for(int i = 0; i < records; i++) 
    {
		CUtils::consoleColor(from + i == selectedLine ? SELECTED_COLOR : NORMAL_COLOR);
        CInvoice* invoice = invoices[from + i];
        stream << std::setw(ID_WIDTH) << std::right << invoice->id() << std::setw(SEPARATOR_WIDTH) << " " 
                  << std::setw(DATE_WIDTH) << std::left << invoice->date() << std::setw(SEPARATOR_WIDTH) << " " 
				  << std::setw(NAME_WIDTH) << std::left << invoice->to() << std::setw(SEPARATOR_WIDTH) << " "
                  << std::setw(VALUE_WIDTH) << std::left << invoice->value() << std::endl;
		CUtils::consoleColor(NORMAL_COLOR);
    }
}

void CLayoutTableListHelper::layoutPageForOrders(std::ostream& stream, int from, int records, int selectedLine)
{
	stream << std::endl;
    stream << "Current orders:" << std::endl;

    stream << std::setw(ID_WIDTH) << std::right << "ID" << std::setw(SEPARATOR_WIDTH) << " " 
              << std::setw(DATE_WIDTH) << std::left << "DATE" << std::setw(SEPARATOR_WIDTH) << " " 
              << std::setw(NAME_WIDTH) << "FROM" << std::setw(SEPARATOR_WIDTH) << " "
			  << std::setw(VALUE_WIDTH) << "VALUE" << std::setw(SEPARATOR_WIDTH) << " "
			  << std::endl << std::endl;

    const std::vector<COrder*>& orders = COrdersManager::instance().ordersAsArray();
    for(int i = 0; i < records; i++) 
    {
		CUtils::consoleColor(from + i == selectedLine ? SELECTED_COLOR : NORMAL_COLOR);
        COrder* order = orders[from + i];
        stream << std::setw(ID_WIDTH) << std::right << order->id() << std::setw(SEPARATOR_WIDTH) << " " 
                  << std::setw(DATE_WIDTH) << std::left << order->date() << std::setw(SEPARATOR_WIDTH) << " " 
				  << std::setw(NAME_WIDTH) << std::left << order->from() << std::setw(SEPARATOR_WIDTH) << " "
                  << std::setw(VALUE_WIDTH) << std::left << order->value() << std::endl;
		CUtils::consoleColor(NORMAL_COLOR);
    }
}
