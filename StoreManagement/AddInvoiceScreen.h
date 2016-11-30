#pragma once
#include "paginatedscreen.h"
#include <vector>
#include "Invoice.h"

class CAddInvoiceScreen :
	public CPaginatedScreen
{
	typedef enum { eEnterTo, eEnterQuantity } eStep;
public:
	CAddInvoiceScreen(void);
	~CAddInvoiceScreen(void);
	
	void layoutContent();
	void handleInput(const std::string& userInput);
    void layoutPage(int from, int records);

private:
	eStep _currentStep;
	std::string _to;
	double _value;
	std::vector<BuyItem> _items;
};

