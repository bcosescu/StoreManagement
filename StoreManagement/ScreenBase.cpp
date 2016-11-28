#include "StdAfx.h"
#include "ScreenBase.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "NavigationManager.h"
#include "Utils.h"
#include "UsersManager.h"


CScreenBase::CScreenBase(const std::string& screenName)
{
	_screenName = screenName;
	_passwordInput = false;
	_shouldExitAppOption = false;
}


CScreenBase::~CScreenBase(void)
{
}

void CScreenBase::layout()
{
	//clear console
	system("cls");

	std::cout << "STORE MANAGEMENT " << _screenName << std::endl << std::endl;
	if(CUsersManager::instance().currentUser())
	{
		std::cout << "User: " << CUsersManager::instance().currentUser()->userName() << std::endl << std::endl;
	}

	//print the screen
	layoutContent();

	if(_errorOnScreen.size() != 0)
	{
		CUtils::gotoxy(0, INPUT_LINE - 5);
		std::cout << "ERROR: " << _errorOnScreen << std::endl;
	}

	//move cursor some lines back
	CUtils::gotoxy(0, INPUT_LINE);
	std::cout << ">";
	
	//wait for input
	std::string userInput;

	char ch = _getch();
	while(ch != 13)
	{//character 13 is enter
		if(ch == KEY_SPECIAL_BEGIN) {
			ch = _getch();
			continue;
		}
		switch(ch)
		{
			case KEY_UP:
			case KEY_DOWN:
			case KEY_LEFT:
			case KEY_RIGHT:
				handleSpecialKey(ch);
				ch = _getch();
				continue;
		}
		userInput.push_back(ch);
		std::cout << (_passwordInput ? '*' : ch);
		ch = _getch();
	}

	if(userInput.size() == 1)
	{
		if(userInput[0] == 'B' && handleBack())
			return;

		if(userInput[0] == 'X' && _shouldExitAppOption) 
		{
			CNavigationManager::instance().removeAllScreens();
			return;
		}
	}

	resetError();

	//treat the input
	handleInput(userInput);
}

bool CScreenBase::handleBack()
{
	exit();
	return true;
}

void CScreenBase::setCurrentError(const std::string& error)
{
	_errorOnScreen = error;
}

void CScreenBase::resetError()
{
	_errorOnScreen = "";
}

void CScreenBase::exit()
{
	CNavigationManager::instance().popScreen();
}