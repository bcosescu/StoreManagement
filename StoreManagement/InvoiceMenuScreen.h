#pragma once
#include "paginatedscreen.h"
class CInvoiceMenuScreen :
	public CPaginatedScreen
{
public:
	CInvoiceMenuScreen(void);
	~CInvoiceMenuScreen(void);
	
	void layoutContent();
	void handleInput(const std::string& userInput);
    void layoutPage(int from, int records);
};

