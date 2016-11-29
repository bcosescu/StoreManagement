#include "StdAfx.h"
#include "Product.h"

CProduct::CProduct(void)
{
}

CProduct::~CProduct(void)
{
}

CProduct::CProduct(const std::string& name, const std::string& description)
: CStoredItem()
{
    _name = name;
    _description = description;
}

CProduct::CProduct(int id, const std::string& name, const std::string& description)
: CStoredItem(id)
{
    _name = name;
    _description = description;
}