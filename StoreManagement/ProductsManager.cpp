#include "StdAfx.h"
#include "ProductsManager.h"
#include "Utils.h"
#include "Product.h"

CProductsManager::CProductsManager(void)
:CStoredItemManager(CATEGORIES_FILE)
{
    _headerForFile.push_back("#This is the product file");
    _headerForFile.push_back("#Header is:ID;NAME;DESCRIPTION;CATEGORIES");
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

bool CProductsManager::isProductNamePresent(const std::string& name)
{
    if(!_importedContent)
        importProducts();

    for(PRODUCTMAP::iterator it = _products.begin(); it != _products.end(); it++)
    {
        if(!it->second->name().compare(name))
            return true;
    }
    return false;
}

bool CProductsManager::createProduct(const std::string& name, const std::string& description)
{
    if(!_importedContent)
        importProducts();

    CProduct* tmp = new CProduct(nextId(), name, description);
    _products.insert(std::pair<int, CProduct*>(tmp->id(), tmp));
    _productsArr.push_back(tmp);
    return true;
}

void CProductsManager::importProducts()
{
    std::vector<std::string> lines = readContent();
    for(size_t i = 0; i < lines.size(); i++) 
    {
        std::vector<std::string> tokens = CUtils::split(lines[i], ';');
        if(tokens.size() != 3)
            continue;

        CProduct* tmp = new CProduct(CONVERT_TO_ID(tokens[0]), tokens[1], tokens[2]);
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
        ss << it->second->id() << FIELD_DELIM << it->second->name() << FIELD_DELIM << it->second->description();
        lines.push_back(ss.str());
    }
    writeContent(lines);
}