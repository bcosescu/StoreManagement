#pragma once
#include <vector>
#include <string>

class CStoredItemManager
{

protected:
	CStoredItemManager(const std::string& fileName);
	CStoredItemManager(const CStoredItemManager&);
	~CStoredItemManager(void);

	CStoredItemManager& operator=(const CStoredItemManager&);

	std::vector<std::string> readContent();
	void writeContent(const std::vector<std::string>& lines);

	ID	nextId() { return ++_currentId; }

private:
	std::string _fileName;
	ID	_currentId;

protected:
	std::vector<std::string> _headerForFile;
	bool _importedContent;
};

