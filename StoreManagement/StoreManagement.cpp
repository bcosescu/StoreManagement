// StoreManagement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WelcomeScreen.h"
#include "NavigationManager.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CNavigationManager::instance().pushScreen(new CWelcomeScreen());
	while(CNavigationManager::instance().hasMoreScreens()) {
		CNavigationManager::instance().presentCurrentScreen();
	}

	return 0;
}

