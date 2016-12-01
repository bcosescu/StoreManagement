#include "StdAfx.h"
#include "OrdersManager.h"
#include "utils.h"

COrdersManager::COrdersManager(void)
	:CStoredItemManager(ORDERS_FILE)
{
	_headerForFile.push_back("#This is the orders file");
	_headerForFile.push_back("#Header is:ID;FROM;DATE;VALUE;ITEMS");
    importOrders();
}


COrdersManager::~COrdersManager(void)
{
	exportOrders();
	for(ORDERMAP::iterator it = _orders.begin(); it != _orders.end(); it++) 
	{
		delete it->second;
	}
}

bool COrdersManager::createOrder(const std::string& from, const std::string& date, double value, const std::vector<BuyItem>& items)
{
	if(!_importedContent)
		importOrders();
	
	COrder* tmp = new COrder(nextId(), from, date, value, items);
	_orders.insert(std::pair<ID, COrder*>(tmp->id(), tmp));
	_ordersArr.push_back(tmp);
	return true;
}

void COrdersManager::importOrders()
{
	std::vector<std::string> lines = readContent();
	for(size_t i = 0; i < lines.size(); i++) 
	{
		std::vector<std::string> tokens = CUtils::split(lines[i], ';');
		if(tokens.size() != 5)
			continue;

		std::vector<std::string> itemsToken = CUtils::split(tokens[4], SUB_FIELD_DELIM);
		std::vector<BuyItem> items;
		size_t j = 0;
		while(j < itemsToken.size())
		{
			items.push_back(BuyItem(CONVERT_TO_ID(itemsToken[j]), CONVERT_TO_INT(itemsToken[j+1])));
			j += 2;
		}

		COrder* tmp = new COrder(CONVERT_TO_ID(tokens[0]), tokens[1], tokens[2], CONVERT_TO_DOUBLE(tokens[3]), items);
		_orders.insert(std::pair<int, COrder*>(CONVERT_TO_ID(tokens[0]), tmp));
		_ordersArr.push_back(tmp);
	}
}

void COrdersManager::exportOrders()
{
	std::vector<std::string> lines;
	for(ORDERMAP::iterator it = _orders.begin(); it != _orders.end(); it++)
	{
		std::stringstream ss;
		ss << it->second->id() << FIELD_DELIM << it->second->from() << FIELD_DELIM << it->second->date() << FIELD_DELIM
			<< it->second->value() << FIELD_DELIM;

		const std::vector<BuyItem>& items = it->second->items();
		for(size_t i = 0; i < items.size(); i++)
		{
			ss << items[i].productId << SUB_FIELD_DELIM << items[i].quantity;
			if(i != items.size() - 1)
				ss << SUB_FIELD_DELIM;
		}

		lines.push_back(ss.str());
	}
	writeContent(lines);
}

COrder* COrdersManager::order(ID id)
{
	ORDERMAP::iterator it = _orders.find(id);
	if(it == _orders.end())
		return NULL;

	return it->second;
}