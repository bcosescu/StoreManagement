#pragma once
#include "storeditem.h"
#include <vector>

class CProduct :
    public CStoredItem
{
    friend class CProductsManager;

protected:
    CProduct(void);
	CProduct(const std::string& name, const std::string& description, int quantity, double price, const std::vector<ID>& categories);
    CProduct(int id, const std::string& name, const std::string& description, int quantity, double price,const std::vector<ID>& categories);
    ~CProduct(void);

public:

    const std::string& name() const { return _name; }
    const std::string& description() const { return _description; }
	int				   quantity() const { return _quantity; }
	double			   price() const { return _price; }
	const std::vector<ID>& categories() const { return _categories; }
	void			   setQuantity(int quantity) { _quantity = quantity; }

private:
    std::string _name;
    std::string _description;
	int			_quantity;
	double		_price;
	std::vector<ID> _categories;
};
