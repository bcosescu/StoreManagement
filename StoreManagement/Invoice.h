#pragma once
#include <string>
#include <vector>
#include "StoredItem.h"

struct BuyItem
{
	BuyItem()
	{
		productId = INVALID_ID;
		quantity = 0;
	}

	BuyItem(ID id, int qnt)
	{
		productId = id;
		quantity = qnt;
	}

	ID productId;
	int quantity;
};

class CInvoice : public CStoredItem
{
	friend class CInvoicesManager;

protected:
	CInvoice(void);
	CInvoice(const std::string& to, const std::string& date, double value, const std::vector<BuyItem>& items);
	CInvoice(ID id, const std::string& to, const std::string& date, double value, const std::vector<BuyItem>& items);
	~CInvoice(void);

public:
	const std::string& to() const { return _to; }
	double value() const { return _value; }
	const std::string& date() const { return _date; }
	const std::vector<BuyItem>& items() const { return _items; }
	
private:

	std::string _to;
	double		_value;
	std::string _date;
	std::vector<BuyItem> _items;
};
