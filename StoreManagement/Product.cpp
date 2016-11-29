#include "StdAfx.h"
#include "Product.h"

CProduct::CProduct(void)
{
	_quantity = 0;
}

CProduct::~CProduct(void)
{
}

CProduct::CProduct(const std::string& name, const std::string& description, int quantity, const std::vector<ID>& categories)
: CStoredItem()
{
    _name = name;
    _description = description;
	_quantity = quantity;
	_categories = categories;
}

CProduct::CProduct(int id, const std::string& name, const std::string& description, int quantity, const std::vector<ID>& categories)
: CStoredItem(id)
{
    _name = name;
    _description = description;
	_quantity = quantity;
	_categories = categories;
}