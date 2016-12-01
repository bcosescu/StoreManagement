#pragma once

struct BuyItem
{
	BuyItem()
	{
		productId = INVALID_ID;
		quantity = 0;
	}

	BuyItem(ID id, int qnt)
	{
		productId = id;
		quantity = qnt;
	}

	ID productId;
	int quantity;
};
