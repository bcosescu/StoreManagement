#pragma once
#include "screenbase.h"
class CAddCategoryScreen :
	public CScreenBase
{
	typedef enum { eEnterName, eEnterDescription } eStep;
public:
	CAddCategoryScreen(void);
	~CAddCategoryScreen(void);

	void layoutContent();
	void handleInput(const std::string& userInput);

private:
	eStep _currentStep;
	std::string _categoryName;
};

