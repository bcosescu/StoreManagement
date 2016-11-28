#include "StdAfx.h"
#include "UsersManager.h"
#include "User.h"
#include <fstream>
#include <vector>
#include "Utils.h"
#include <sstream>

CUsersManager::CUsersManager(void)
	: CStoredItemManager(USERS_FILE)
{
	_headerForFile.push_back("#This is the users file");
	_headerForFile.push_back("#Header is:ID;USERNAME;HASH");
	_currentUser = NULL;
}


CUsersManager::~CUsersManager(void)
{
	exportUsers();
	for(USERSMAP::iterator it = _users.begin(); it != _users.end(); it++) 
	{
		delete it->second;
	}
}

bool CUsersManager::isUserNamePresent(const std::string& userName)
{
	if(!_importedContent)
		importUsers();

	for(USERSMAP::iterator it = _users.begin(); it != _users.end(); it++)
	{
		if(!it->second->userName().compare(userName))
			return true;
	}
	return false;
}

bool CUsersManager::createUser(const std::string& userName, HashType password)
{
	if(!_importedContent)
		importUsers();
	
	CUser* tmp = new CUser(nextId(), userName, password);
	_users.insert(std::pair<int, CUser*>(tmp->id(), tmp));
	_currentUser = tmp;
	return true;
}

bool CUsersManager::validateUser(const std::string& userName, HashType password)
{
	if(!_importedContent)
		importUsers();

	for(USERSMAP::iterator it = _users.begin(); it != _users.end(); it++)
	{
		if(!it->second->userName().compare(userName) && (it->second->password() == password))
		{
			_currentUser = it->second;
			return true;
		}
	}
	return false;
}

void CUsersManager::importUsers()
{
	std::vector<std::string> lines = readContent();
	for(size_t i = 0; i < lines.size(); i++) 
	{
		std::vector<std::string> tokens = CUtils::split(lines[i], ';');
		if(tokens.size() != 3)
			continue;

		_users.insert(std::pair<int, CUser*>(CONVERT_TO_ID(tokens[0]), new CUser(CONVERT_TO_ID(tokens[0]), tokens[1], CONVERT_TO_HASH(tokens[2]))));
	}
}

void CUsersManager::exportUsers()
{
	std::vector<std::string> lines;
	for(USERSMAP::iterator it = _users.begin(); it != _users.end(); it++)
	{
		std::stringstream ss;
		ss << it->second->id() << FIELD_DELIM << it->second->userName() << FIELD_DELIM << it->second->password();
		lines.push_back(ss.str());
	}
	writeContent(lines);
}
