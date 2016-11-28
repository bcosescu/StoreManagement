#pragma once
#include "storeditem.h"
class CCategory :
	public CStoredItem
{
	friend class CCategoryManager;

protected:
	CCategory(void);
	CCategory(const std::string& name, const std::string& description);
	CCategory(int id, const std::string& name, const std::string& description);
	~CCategory(void);

public:

	const std::string& name() const { return _name; }
	const std::string& description() const { return _description; }

private:
	std::string _name;
	std::string _description;

};

