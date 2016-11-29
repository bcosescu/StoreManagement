#pragma once
#include <map>
#include <vector>
#include "Product.h"
#include "StoredItemManager.h"

class CProductsManager : public CStoredItemManager
{
    typedef std::map<int, CProduct*> PRODUCTMAP;
    typedef std::vector<CProduct*> PRODUCTARRAY;
    CProductsManager(void);
    CProductsManager(const CProductsManager&);
    ~CProductsManager(void);

    CProductsManager& operator=(const CProductsManager&);

public:
    static CProductsManager& instance() {
        static CProductsManager my;
        return my;
    }

    bool isProductNamePresent(const std::string& name);
    bool createProduct(const std::string& name, const std::string& description);
    const PRODUCTARRAY& productsAsArray() { return _productsArr; }

private:
    void importProducts();
    void exportProducts();

    PRODUCTMAP _products;
    PRODUCTARRAY _productsArr;
};
