#include "StdAfx.h"
#include "ProductsManager.h"
#include "Utils.h"
#include "Product.h"

CProductsManager::CProductsManager(void)
:CStoredItemManager(PRODUCTS_FILE)
{
    _headerForFile.push_back("#This is the product file");
    _headerForFile.push_back("#Header is:ID;NAME;DESCRIPTION;QUANTITY;PRICE;CATEGORIES");
    importProducts();
}


CProductsManager::~CProductsManager(void)
{
    exportProducts();
    for(PRODUCTMAP::iterator it = _products.begin(); it != _products.end(); it++) 
    {
        delete it->second;
    }
}

bool CProductsManager::createProduct(const std::string& name, const std::string& description, int quantity, double price, const std::vector<ID>& cateories)
{
    if(!_importedContent)
        importProducts();

    CProduct* tmp = new CProduct(nextId(), name, description, quantity, price, cateories);
    _products.insert(std::pair<int, CProduct*>(tmp->id(), tmp));
    _productsArr.push_back(tmp);
    return true;
}

void CProductsManager::importProducts()
{
    std::vector<std::string> lines = readContent();
    for(size_t i = 0; i < lines.size(); i++) 
    {
        std::vector<std::string> tokens = CUtils::split(lines[i], FIELD_DELIM);
        if(tokens.size() != 6)
            continue;

		std::vector<std::string> categoriesToken = CUtils::split(tokens[5], SUB_FIELD_DELIM);
		std::vector<ID> categories;
		for(size_t j = 0; j < categoriesToken.size(); j++)
		{
			categories.push_back(CONVERT_TO_ID(categoriesToken[j]));
		}

        CProduct* tmp = new CProduct(CONVERT_TO_ID(tokens[0]), tokens[1], tokens[2], CONVERT_TO_INT(tokens[3]), CONVERT_TO_DOUBLE(tokens[4]), categories);
        _products.insert(std::pair<int, CProduct*>(CONVERT_TO_ID(tokens[0]), tmp));
        _productsArr.push_back(tmp);
    }
}

void CProductsManager::exportProducts()
{
    std::vector<std::string> lines;
    for(PRODUCTMAP::iterator it = _products.begin(); it != _products.end(); it++)
    {
        std::stringstream ss;
        ss << it->second->id() << FIELD_DELIM 
			<< it->second->name() << FIELD_DELIM 
			<< it->second->description() << FIELD_DELIM
			<< it->second->quantity() << FIELD_DELIM
			<< it->second->price() << FIELD_DELIM;

		std::vector<ID> categories = it->second->categories();
		for(size_t i = 0 ; i < categories.size(); i++)
		{
			ss << categories[i];
			if(i != categories.size() - 1)
				ss << SUB_FIELD_DELIM;
		}
        lines.push_back(ss.str());
    }
    writeContent(lines);
}