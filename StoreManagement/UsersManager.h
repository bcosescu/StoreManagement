#pragma once
#include <map>
#include "User.h"
#include "StoredItemManager.h"

class CUsersManager : public CStoredItemManager
{
	typedef std::map<int, CUser*> USERSMAP;
	CUsersManager(void);
	CUsersManager(const CUsersManager&);
	~CUsersManager(void);

	CUsersManager& operator=(const CUsersManager&);

public:
	static CUsersManager& instance() {
		static CUsersManager my;
		return my;
	}

	bool isUserNamePresent(const std::string& userName);
	bool createUser(const std::string& userName, HashType password);
	bool validateUser(const std::string& userName, HashType password);
	CUser* currentUser() { return _currentUser; }

private:
	void importUsers();
	void exportUsers();

	USERSMAP _users;
	CUser*	_currentUser;
};

