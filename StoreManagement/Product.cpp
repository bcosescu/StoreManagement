#include "StdAfx.h"
#include "Product.h"

CProduct::CProduct(void)
{
	_quantity = 0;
	_price = 0;
	_supplierPrice = 0;
}

CProduct::~CProduct(void)
{
}

CProduct::CProduct(const std::string& name, const std::string& description, int quantity, double price, double supplierPrice, const std::vector<ID>& categories)
: CStoredItem()
{
    _name = name;
    _description = description;
	_quantity = quantity;
	_price = price;
	_supplierPrice = supplierPrice;
	_categories = categories;
}

CProduct::CProduct(int id, const std::string& name, const std::string& description, int quantity, double price, double supplierPrice, const std::vector<ID>& categories)
: CStoredItem(id)
{
    _name = name;
    _description = description;
	_quantity = quantity;
	_price = price;
	_supplierPrice = supplierPrice;
	_categories = categories;
}