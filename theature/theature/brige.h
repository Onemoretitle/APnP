#pragma once
#include "instorege.h"
#include "HallBuilder.h"

class BridgeBookImp 
{
public:
	BridgeBookImp(int nm, int rw)
	{
		num = nm;
		row = rw;
	}
	virtual void info();
protected:
	int num, row;
};

class BridgeHaveOrderImp : public BridgeBookImp
{
public:
	BridgeHaveOrderImp(int nm, int rw, bool havePayment) : BridgeBookImp(nm, rw)
	{
		pay_ = havePayment;
	}
	void info();
protected:
	bool pay_;
};

class BridgeHaveNotOrderImp : public BridgeBookImp
{
public:
	BridgeHaveNotOrderImp(int nm, int rw) : BridgeBookImp(nm, rw)
	{};
	void info();
};


class BridgeBook
{
public:
	BridgeBook() {}
	BridgeBook(int nm, int rw)
	{
		imp_ = new BridgeBookImp(nm, rw);
	}
	virtual void info() 
	{
		imp_->info();
	}
protected:
	BridgeBookImp* imp_;
};

class BridgeHaveOrder : public BridgeBook
{
public:
	BridgeHaveOrder(int nm, int rw, bool havePayment)
	{
		imp_ = new BridgeHaveOrderImp(nm, rw, havePayment);
	}
};

class BridgeHaveNotOrder : public BridgeBook
{
public:
	BridgeHaveNotOrder(int nm, int rw)
	{
		imp_ = new BridgeHaveNotOrderImp(nm, rw);
	}
};
