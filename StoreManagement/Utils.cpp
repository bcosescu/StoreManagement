#include "StdAfx.h"
#include "Utils.h"
#include <sstream>
#include <ctime>


CUtils::CUtils(void)
{
}


CUtils::~CUtils(void)
{
}

HashType CUtils::hash(const std::string& s, HashType seed)
{
	const char* ch = s.c_str();
    HashType hash = seed;
    while (*ch)
    {
        hash = hash * 101  +  *ch++;
    }
    return hash;
}

//move cursor in console at position
//y - is the line
//x - is the column
void CUtils::gotoxy(int x, int y) 
{ 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void CUtils::wherexy(int& x, int& y)
{ 
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE); 
	GetConsoleScreenBufferInfo(hStd, &screenBufferInfo); 
	x = screenBufferInfo.dwCursorPosition.X; 
	y = screenBufferInfo.dwCursorPosition.Y;
}

int CUtils::getNumericOption(const std::string& input)
{
	try {
// 		std::string::size_type sz;
// 		int option = std::stoi(input, &sz);
// 		return option;

        return CUtils::convertStr<int>(input);
	}
	catch (const std::invalid_argument&) {
	}
	catch (const std::out_of_range&) {
	}
	return INVALID_OPTION;
}

bool CUtils::isValidInt(const std::string& input)
{
	try {
 		std::string::size_type sz;
 		int option = std::stoi(input, &sz);
		
	}
	catch (const std::invalid_argument&) {
		return false;
	}
	catch (const std::out_of_range&) {
		return false;
	}
	return true;
}

void CUtils::split(const std::string &s, char delim, std::vector<std::string> &elems) 
{
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) 
	{
        elems.push_back(item);
    }
}


std::vector<std::string> CUtils::split(const std::string &s, char delim) 
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

void CUtils::consoleColor(int color)
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStd, color);
}

std::string CUtils::currentDate()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%d-%m-%y",timeinfo);
  return std::string(buffer);
}