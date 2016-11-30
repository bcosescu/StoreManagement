#pragma once
#include <map>
#include <vector>
#include "Invoice.h"
#include "StoredItemManager.h"

class CInvoicesManager : public CStoredItemManager
{
	typedef std::map<int, CInvoice*> INVOICEMAP;
	typedef std::vector<CInvoice*> INVOICEARRAY;
	CInvoicesManager(void);
	CInvoicesManager(const CInvoicesManager&);
	~CInvoicesManager(void);

	CInvoicesManager& operator=(const CInvoicesManager&);

public:
	static CInvoicesManager& instance() {
		static CInvoicesManager my;
		return my;
	}

	bool createInvoice(const std::string& to, const std::string& date, double value, const std::vector<BuyItem>& items);
	const INVOICEARRAY& invoicesAsArray() { return _invoicesArr; }
	CInvoice* invoice(ID id);

private:
	void importInvoices();
	void exportInvoices();

	INVOICEMAP _invoices;
	INVOICEARRAY _invoicesArr;
};
