#pragma once
#include <string>
#include <vector>
#include <sstream>

#define CONVERT_TO_ID(x)	CUtils::convertStr<ID>(x)
#define CONVERT_TO_HASH(x)	CUtils::convertStr<HashType>(x)
#define CONVERT_TO_INT(x)	CUtils::convertStr<int>(x)
#define CONVERT_TO_DOUBLE(x) CUtils::convertStr<double>(x)
#define SELECTED_COLOR 23
#define NORMAL_COLOR 7

class CUtils
{
public:
	CUtils(void);
	~CUtils(void);

	static HashType hash(const std::string& s, HashType seed = 0);
	static void gotoxy(int x, int y);
	static void wherexy(int& x, int& y);
	static int getNumericOption(const std::string& input);
	static bool isValidInt(const std::string& input);
	static std::vector<std::string> split(const std::string &s, char delim);
	static void split(const std::string &s, char delim, std::vector<std::string> &elems);
	template<typename T>
	static T convertStr(const std::string &s);

	static void consoleColor(int color);
	static std::string currentDate();
};

template<typename T>
T CUtils::convertStr(const std::string& s)
{
	std::istringstream reader(s);
	T value;
	reader >> value;
	return value;
}