#pragma once
#include <map>
#include <vector>
#include "Order.h"
#include "StoredItemManager.h"

class COrdersManager : public CStoredItemManager
{
	typedef std::map<int, COrder*> ORDERMAP;
	typedef std::vector<COrder*> ORDERARRAY;
	COrdersManager(void);
	COrdersManager(const COrdersManager&);
	~COrdersManager(void);

	COrdersManager& operator=(const COrdersManager&);

public:
	static COrdersManager& instance() {
		static COrdersManager my;
		return my;
	}

	bool createOrder(const std::string& from, const std::string& date, double value, const std::vector<BuyItem>& items);
	const ORDERARRAY& ordersAsArray() { return _ordersArr; }
	COrder* order(ID id);

private:
	void importOrders();
	void exportOrders();

	ORDERMAP _orders;
	ORDERARRAY _ordersArr;
};

