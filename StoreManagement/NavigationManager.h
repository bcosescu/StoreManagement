#pragma once
#include <stack>
#include "ScreenBase.h"

class CNavigationManager
{
	CNavigationManager(void);
	CNavigationManager(const CNavigationManager&);
	~CNavigationManager(void);

	CNavigationManager& operator=(const CNavigationManager&);

public:
	static CNavigationManager& instance() {
		static CNavigationManager my;
		return my;
	}

	void pushScreen(CScreenBase* newScreen);
	void popScreen();
	CScreenBase* topScreen();
	bool hasMoreScreens();
	void presentCurrentScreen();
	void removeAllScreens();

private:
	std::stack<CScreenBase*> _stackScreens;
};

