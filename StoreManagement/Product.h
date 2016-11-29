#pragma once
#include "storeditem.h"

class CProduct :
    public CStoredItem
{
    friend class CProductsManager;

protected:
    CProduct(void);
    CProduct(const std::string& name, const std::string& description);
    CProduct(int id, const std::string& name, const std::string& description);
    ~CProduct(void);

public:

    const std::string& name() const { return _name; }
    const std::string& description() const { return _description; }

private:
    std::string _name;
    std::string _description;

};
