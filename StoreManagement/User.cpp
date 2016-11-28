#include "StdAfx.h"
#include "User.h"


CUser::CUser(void)
	: CStoredItem()
{
	_password = INVALID_PASSWORD;
}

CUser::CUser(const std::string& userName, HashType password)
	: CStoredItem()
{
	_userName = userName;
	_password = password;
}

CUser::CUser(int id, const std::string& userName, HashType password)
	: CStoredItem(id)
{
	_userName = userName;
	_password = password;
}

CUser::~CUser(void)
{
}
