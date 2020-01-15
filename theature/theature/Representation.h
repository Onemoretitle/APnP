#pragma once
#include "instorege.h"
#include "brige.h"

class Representation
{	
	const char* rep_name;
	class State* current;
public:
	Representation();
	void setCurrent(State* s, const char* name)
	{
		current = s;
		rep_name = name;
	}
	void on();
	void off();
	void inq();
};

class State
{
public:
	virtual void online(Representation* m, int nm, int rw, bool pay)
	{
		cout << "   already online\n";
		BridgeBook* order = new BridgeHaveOrder(nm, rw, pay);
	}
	virtual void offline(Representation* m, int nm, int rw)
	{
		cout << "   already offline\n";
	}
	virtual void inqueue(Representation* m, int nm, int rw)
	{
		cout << "   already in queue\n";
		BridgeBook* notPrepaid = new BridgeHaveOrder(nm, rw, false);
	}
};


class ON : public State
{
public:
	ON()
	{
		cout << "   ON-ctor ";
	};
	~ON()
	{
		cout << "   dtor-ON\n";
	};
	void off(Representation* m);
};

class OFF : public State
{
public:
	OFF()
	{
		cout << "   OFF-ctor ";
	};
	~OFF()
	{
		cout << "   dtor-OFF\n";
	};
	void inq(Representation* m);
};

class INQ : public State
{
public:
	INQ()
	{
		cout << "   OFF-ctor ";
	};
	~INQ()
	{
		cout << "   dtor-OFF\n";
	};
	void on(Representation* m);
};

