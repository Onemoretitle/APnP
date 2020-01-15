#pragma once
#include "book.h"
#include "HallBuilder.h"

// конкретные делегаты:
class HaveOrder : public IBook
{
private:
	bool havePayment;
	int num, row;
public:
	HaveOrder(int nm, int rw, bool prepaid)
	{
		num = nm;
		row = rw;
		havePayment = prepaid;
	};
	~HaveOrder() {};

	void order();
	void pay();
};

class HaveNotOrder : public IBook
{
public:
	HaveNotOrder() {};
	~HaveNotOrder() {};
	void order();
	void pay();
};





