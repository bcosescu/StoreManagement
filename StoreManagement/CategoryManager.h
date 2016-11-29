#pragma once
#include <map>
#include <vector>
#include "Category.h"
#include "StoredItemManager.h"

class CCategoryManager : public CStoredItemManager
{
	typedef std::map<int, CCategory*> CATEGORYMAP;
	typedef std::vector<CCategory*> CATEGORYARRAY;
	CCategoryManager(void);
	CCategoryManager(const CCategoryManager&);
	~CCategoryManager(void);

	CCategoryManager& operator=(const CCategoryManager&);

public:
	static CCategoryManager& instance() {
		static CCategoryManager my;
		return my;
	}

	bool isCategoryNamePresent(const std::string& name);
	bool createCategory(const std::string& name, const std::string& description);
	const CATEGORYARRAY& categoriesAsArray() { return _categoriesArr; }
	CCategory* category(ID id);

private:
	void importCategories();
	void exportCategories();

	CATEGORYMAP _categories;
	CATEGORYARRAY _categoriesArr;
};

