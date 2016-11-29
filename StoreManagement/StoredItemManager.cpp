#include "StdAfx.h"
#include "StoredItemManager.h"
#include <fstream>
#include "Utils.h"

CStoredItemManager::CStoredItemManager(const std::string& fileName)
{
	_fileName = fileName;
	_importedContent = false;
	_currentId = 0;
}


CStoredItemManager::~CStoredItemManager(void)
{
}

std::vector<std::string> CStoredItemManager::readContent()
{
	std::ifstream inputFile(_fileName.c_str());
    std::string line;
	int usersRead = 0;
	std::vector<std::string> lines;
    while(std::getline(inputFile, line))
    {
		if(line.size() == 0)
			continue;

		if(line.size() > 0 && line[0] == '#') 
		{
			if(line.find("#ID=") == 0)
			{
				std::vector<std::string> tokens = CUtils::split(line.c_str(), '=');
				_currentId = CUtils::convertStr<ID>(tokens[1]);
				continue;
			}
			else
			{
				if(line[0] == '#')
					continue;
			}
		}

		lines.push_back(line);
	}
	_importedContent = true;
	return lines;
}

void CStoredItemManager::writeContent(const std::vector<std::string>& lines)
{
	std::ofstream outputFile(_fileName.c_str());

	for(size_t i = 0; i < _headerForFile.size(); i++)
	{
		outputFile << _headerForFile[i] << std::endl;
	}

	outputFile << "#DO NOT MESS WITH THIS" << std::endl;
	outputFile << "#ID=" << _currentId << std::endl;

	for(size_t i = 0; i < lines.size(); i++)
	{
		outputFile << lines[i] << std::endl;
	}
	outputFile.close();
}
