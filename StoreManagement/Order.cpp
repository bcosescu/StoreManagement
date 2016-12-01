#include "StdAfx.h"
#include "Order.h"

COrder::COrder(void)
	: CStoredItem()
{
	_value = 0;
}

COrder::COrder(const std::string& from, const std::string& date, double value, const std::vector<BuyItem>& items)
	: CStoredItem()
{
	_from = from;
	_date = date;
	_value = value;
	_items = items;
}

COrder::COrder(ID id, const std::string& from, const std::string& date, double value, const std::vector<BuyItem>& items)
	: CStoredItem(id)
{
	_from = from;
	_date = date;
	_value = value;
	_items = items;
}

COrder::~COrder(void)
{
}
