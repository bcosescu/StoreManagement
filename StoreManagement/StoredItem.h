#pragma once
class CStoredItem
{
public:
	CStoredItem(void);
	CStoredItem(int id);
	~CStoredItem(void);

	int	id() const { return _id; }
	void setId(int id) { _id = id; }
private:
	int _id;
};

