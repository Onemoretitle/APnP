#pragma once
#include "instorege.h"
#include "payOrder.h"
#include "book.h"

typedef IBook* ptrOrder;

class TTickets
{
private:
	char* session;
	int seatId;
	//ConcreteHall* hall;
	vector <ptrOrder> orders;

public:
	TTickets()
	{
		orders.clear();
		session = nullptr;
		seatId = 0;
		
	}
	~TTickets();

	void perfomOrders();
	void takeOrder(IBook* newOrder);
	void deliteOrder(int seat);

};

// Component 
class Ticket
{
	int value;
	Ticket* next;
public:
	Ticket(int v, Ticket* n) 
	{
		value = v;
		next = n;
	}
	void setNext(Ticket* n) 
	{
		next = n;
	}
	virtual void getStrength() 
	{
		cout << value << "RUB. ";
	};
	virtual void volunteer() 
	{
		next->volunteer();
	}
};

// Primitives
class CountPr : public Ticket
{
private:
	int vle;
public:
	CountPr(int val, Ticket* n = 0) : Ticket(val, n) { vle = val; }
	void volunteer()
	{
		//Ticket::getStrength();
		if (vle == 0)
		{
			Ticket::volunteer();
		}
	}
};

// Composite
class Composite : public Ticket
{
	vector <Ticket*> children;
public:
	Composite(int val, Ticket* n = 0) : Ticket(val, n) {}
	void add(Ticket* c)
	{
		children.push_back(c);
	}
	void getStrength()
	{
		Ticket::getStrength();
		for (int i = 0; i < children.size(); i++)
		{
			children[i]->getStrength();
		}
	}
	void volunteer()
	{
		Ticket::volunteer();
	}
};


class Base
{
	Base* next;
public:
	Base()
	{
		next = 0;
	}
	void setNext(Base* n)
	{
		next = n;
	}
	void add(Base* n)
	{
		if (next)
			next->add(n);
		else
			next = n;
	}
	virtual void handle(int state, int i)
	{
		next->handle(state, i);
	}
};

class Highs : public Base
{
public:
	/*virtual*/void handle(int state, int i)
	{
		if (state == HIGH && i >= 0)
		{
			// 3. Don't handle requests 3 times out of 4
			cout << "High prace " << i * 2500 << " for " << i << " seats " << endl;
		}
		else
		{
			cout << "it isn't high seat " << endl;
			Base::handle(state, i);
		}
	}
};

class Parters : public Base
{
public:
	/*virtual*/void handle(int state, int i)
	{
		if (state == PARTER && i >= 0)
		{
			cout << "Parter prace " << i * 500 << " for " << i << " seats " << endl;
		}
		else
		{
			cout << "it isn't parter seat  " << endl;
			Base::handle(state, i);
		}
	}
};

class Balconys : public Base
{
public:
	/*virtual*/void handle(int state, int i)
	{
		if (state == BALCONY && i >= 0)
		{
			cout << "Balcony prace " << i * 2000 << " for " << i << " seats " << endl;
		}
		else
		{
			cout << "it isn't balcony seat " << endl;
			Base::handle(state, i); 
		}
	}
};