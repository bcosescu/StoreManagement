#include "StdAfx.h"
#include "Category.h"


CCategory::CCategory(void)
	: CStoredItem()
{
}

CCategory::~CCategory(void)
{
}

CCategory::CCategory(const std::string& name, const std::string& description)
	: CStoredItem()
{
	_name = name;
	_description = description;
}

CCategory::CCategory(int id, const std::string& name, const std::string& description)
	: CStoredItem(id)
{
	_name = name;
	_description = description;
}



