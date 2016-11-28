#pragma once
#include <string>
#include "StoredItem.h"

class CUser : public CStoredItem
{
	friend class CUsersManager;

protected:
	CUser(void);
	CUser(const std::string& userName, HashType password);
	CUser(int id, const std::string& userName, HashType password);
	~CUser(void);

public:
	const std::string& userName() const { return _userName; }
	HashType password() const { return _password; }
	void setNewPassword(HashType password) { _password = password; }

private:

	std::string _userName;
	HashType    _password;
};

