#include "StdAfx.h"
#include "InvoicesManager.h"
#include "utils.h"

CInvoicesManager::CInvoicesManager(void)
	:CStoredItemManager(INVOICES_FILE)
{
	_headerForFile.push_back("#This is the invoices file");
	_headerForFile.push_back("#Header is:ID;TO;DATE;VALUE;ITEMS");
    importInvoices();
}


CInvoicesManager::~CInvoicesManager(void)
{
	exportInvoices();
	for(INVOICEMAP::iterator it = _invoices.begin(); it != _invoices.end(); it++) 
	{
		delete it->second;
	}
}

bool CInvoicesManager::createInvoice(const std::string& to, const std::string& date, double value, const std::vector<BuyItem>& items)
{
	if(!_importedContent)
		importInvoices();
	
	CInvoice* tmp = new CInvoice(nextId(), to, date, value, items);
	_invoices.insert(std::pair<ID, CInvoice*>(tmp->id(), tmp));
	_invoicesArr.push_back(tmp);
	return true;
}

void CInvoicesManager::importInvoices()
{
	std::vector<std::string> lines = readContent();
	for(size_t i = 0; i < lines.size(); i++) 
	{
		std::vector<std::string> tokens = CUtils::split(lines[i], ';');
		if(tokens.size() != 5)
			continue;

		std::vector<std::string> itemsToken = CUtils::split(tokens[4], SUB_FIELD_DELIM);
		std::vector<BuyItem> items;
		size_t j = 0;
		while(j < itemsToken.size())
		{
			items.push_back(BuyItem(CONVERT_TO_ID(itemsToken[j]), CONVERT_TO_INT(itemsToken[j+1])));
			j += 2;
		}

		CInvoice* tmp = new CInvoice(CONVERT_TO_ID(tokens[0]), tokens[1], tokens[2], CONVERT_TO_DOUBLE(tokens[3]), items);
		_invoices.insert(std::pair<int, CInvoice*>(CONVERT_TO_ID(tokens[0]), tmp));
		_invoicesArr.push_back(tmp);
	}
}

void CInvoicesManager::exportInvoices()
{
	std::vector<std::string> lines;
	for(INVOICEMAP::iterator it = _invoices.begin(); it != _invoices.end(); it++)
	{
		std::stringstream ss;
		ss << it->second->id() << FIELD_DELIM << it->second->to() << FIELD_DELIM << it->second->date() << FIELD_DELIM
			<< it->second->value() << FIELD_DELIM;

		const std::vector<BuyItem>& items = it->second->items();
		for(size_t i = 0; i < items.size(); i++)
		{
			ss << items[i].productId << SUB_FIELD_DELIM << items[i].quantity;
			if(i != items.size() - 1)
				ss << SUB_FIELD_DELIM;
		}

		lines.push_back(ss.str());
	}
	writeContent(lines);
}

CInvoice* CInvoicesManager::invoice(ID id)
{
	INVOICEMAP::iterator it = _invoices.find(id);
	if(it == _invoices.end())
		return NULL;

	return it->second;
}