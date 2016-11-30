#include "StdAfx.h"
#include "Invoice.h"

CInvoice::CInvoice(void)
	: CStoredItem()
{
	_value = 0;
}

CInvoice::CInvoice(const std::string& to, const std::string& date, double value, const std::vector<BuyItem>& items)
	: CStoredItem()
{
	_to = to;
	_date = date;
	_value = value;
	_items = items;
}

CInvoice::CInvoice(ID id, const std::string& to, const std::string& date, double value, const std::vector<BuyItem>& items)
	: CStoredItem(id)
{
	_to = to;
	_date = date;
	_value = value;
	_items = items;
}

CInvoice::~CInvoice(void)
{
}
