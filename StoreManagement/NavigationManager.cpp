#include "StdAfx.h"
#include "NavigationManager.h"
#include "ScreenBase.h"


CNavigationManager::CNavigationManager(void)
{
}


CNavigationManager::~CNavigationManager(void)
{
}

void CNavigationManager::pushScreen(CScreenBase* newScreen)
{
	_stackScreens.push(newScreen);
}
	
void CNavigationManager::popScreen() 
{
	CScreenBase* current = topScreen();
	if(current)
		delete current;

	_stackScreens.pop();
}

CScreenBase* CNavigationManager::topScreen() 
{
	return _stackScreens.size() == 0 ? NULL : _stackScreens.top();
}

bool CNavigationManager::hasMoreScreens() 
{
	return topScreen() != 0;
}

void CNavigationManager::presentCurrentScreen()
{
	if(!hasMoreScreens())
		return;

	topScreen()->layout();
}

void CNavigationManager::removeAllScreens()
{
	while(hasMoreScreens())
	{
		popScreen();
	}
}