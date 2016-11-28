#include "StdAfx.h"
#include "StoredItem.h"


CStoredItem::CStoredItem(void)
{
	_id = INVALID_ID;
}

CStoredItem::CStoredItem(int id)
{
	_id = id;
}

CStoredItem::~CStoredItem(void)
{
}
