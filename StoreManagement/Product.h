#pragma once
#include "storeditem.h"
#include <vector>

class CProduct :
    public CStoredItem
{
    friend class CProductsManager;

protected:
    CProduct(void);
	CProduct(const std::string& name, const std::string& description, int quantity, double price, double supplierPrice, const std::vector<ID>& categories);
    CProduct(int id, const std::string& name, const std::string& description, int quantity, double price, double supplierPrice, const std::vector<ID>& categories);
    ~CProduct(void);

public:

    const std::string&	name() const { return _name; }
    const std::string&	description() const { return _description; }
	int					quantity() const { return _quantity; }
	double				price() const { return _price; }
	double				supplierPrice() const { return _supplierPrice; }
	const std::vector<ID>& categories() const { return _categories; }
	void				increaseQuantity(int quantity) { _quantity += quantity; }
	void				decreaseQuantity(int quantity) { _quantity = max(0, _quantity - quantity); }

private:
    std::string _name;
    std::string _description;
	int			_quantity;
	double		_price;
	double		_supplierPrice;
	std::vector<ID> _categories;
};
