#pragma once
#include <string>

class CScreenBase
{
public:
	CScreenBase(const std::string& screenName);
	virtual ~CScreenBase(void);

	void layout();
	virtual void layoutContent() = 0;
	virtual bool handleSpecialKey(int specialKey) { return false; }
	virtual void handleInput(const std::string& input) = 0;
	virtual bool handleBack();

	void setCurrentError(const std::string& error);
	void resetError();
	void exit();

protected:
	bool _passwordInput;
	bool _shouldExitAppOption;
	std::string _errorOnScreen;
	std::string _screenName;
};

