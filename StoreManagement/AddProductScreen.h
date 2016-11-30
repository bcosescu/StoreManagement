#pragma once
#include "PaginatedScreen.h"
#include <vector>

class CAddProductScreen :
	public CPaginatedScreen
{
	typedef enum { eEnterName, eEnterDescription, eEnterQuantity, eEnterPrice, eEnterCategories } eStep;
public:
	CAddProductScreen(void);
	~CAddProductScreen(void);
	
	void layoutContent();
	void handleInput(const std::string& userInput);
    void layoutPage(int from, int records);

private:
	eStep _currentStep;
	std::string _productName;
	std::string _productDescription;
	int _quantity;
	double _price;
	std::vector<ID> _categories;
};

