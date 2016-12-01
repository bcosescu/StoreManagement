#pragma once
#include "PaginatedScreen.h"
#include <vector>

class CAddProductScreen :
	public CPaginatedScreen
{
	typedef enum { eEnterName, eEnterDescription, eEnterPrice, eEnterSupplierPrice, eEnterCategories } eStep;
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
	double _price;
	double _supplierPrice;
	std::vector<ID> _categories;
};

