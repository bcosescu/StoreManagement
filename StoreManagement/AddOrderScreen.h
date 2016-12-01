#pragma once
#include "paginatedscreen.h"
#include <vector>
#include "BuyItem.h"

class CAddOrderScreen :
	public CPaginatedScreen
{
	typedef enum { eEnterFrom, eEnterQuantity } eStep;
public:
	CAddOrderScreen(void);
	~CAddOrderScreen(void);
	
	void layoutContent();
	void handleInput(const std::string& userInput);
    void layoutPage(int from, int records);

private:
	eStep _currentStep;
	std::string _from;
	double _value;
	std::vector<BuyItem> _items;
};

