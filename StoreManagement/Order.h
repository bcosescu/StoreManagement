#pragma once
#include <string>
#include <vector>
#include "storeditem.h"
#include "BuyItem.h"

class COrder : public CStoredItem
{
	friend class COrdersManager;

protected:
	COrder(void);
	COrder(const std::string& from, const std::string& date, double value, const std::vector<BuyItem>& items);
	COrder(ID id, const std::string& to, const std::string& date, double value, const std::vector<BuyItem>& items);
	~COrder(void);

public:
	const std::string& from() const { return _from; }
	double value() const { return _value; }
	const std::string& date() const { return _date; }
	const std::vector<BuyItem>& items() const { return _items; }
	
private:

	std::string _from;
	double		_value;
	std::string _date;
	std::vector<BuyItem> _items;
};
