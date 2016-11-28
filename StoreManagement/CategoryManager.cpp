#include "StdAfx.h"
#include "CategoryManager.h"
#include "Utils.h"
#include "Category.h"

CCategoryManager::CCategoryManager(void)
	:CStoredItemManager(CATEGORIES_FILE)
{
	_headerForFile.push_back("#This is the categories file");
	_headerForFile.push_back("#Header is:ID;NAME;DESCRIPTION");
}


CCategoryManager::~CCategoryManager(void)
{
	exportCategories();
	for(CATEGORYMAP::iterator it = _categories.begin(); it != _categories.end(); it++) 
	{
		delete it->second;
	}
}

bool CCategoryManager::isCategoryNamePresent(const std::string& name)
{
	if(!_importedContent)
		importCategories();

	for(CATEGORYMAP::iterator it = _categories.begin(); it != _categories.end(); it++)
	{
		if(!it->second->name().compare(name))
			return true;
	}
	return false;
}

bool CCategoryManager::createCategory(const std::string& name, const std::string& description)
{
	if(!_importedContent)
		importCategories();
	
	CCategory* tmp = new CCategory(nextId(), name, description);
	_categories.insert(std::pair<int, CCategory*>(tmp->id(), tmp));
	_categoriesArr.push_back(tmp);
	return true;
}

void CCategoryManager::importCategories()
{
	std::vector<std::string> lines = readContent();
	for(size_t i = 0; i < lines.size(); i++) 
	{
		std::vector<std::string> tokens = CUtils::split(lines[i], ';');
		if(tokens.size() != 3)
			continue;

		CCategory* tmp = new CCategory(CONVERT_TO_ID(tokens[0]), tokens[1], tokens[2]);
		_categories.insert(std::pair<int, CCategory*>(CONVERT_TO_ID(tokens[0]), tmp));
		_categoriesArr.push_back(tmp);
	}
}

void CCategoryManager::exportCategories()
{
	std::vector<std::string> lines;
	for(CATEGORYMAP::iterator it = _categories.begin(); it != _categories.end(); it++)
	{
		std::stringstream ss;
		ss << it->second->id() << FIELD_DELIM << it->second->name() << FIELD_DELIM << it->second->description();
		lines.push_back(ss.str());
	}
	writeContent(lines);
}