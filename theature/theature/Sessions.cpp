#include "Sessions.h"
void Sessions::online(int nm, int rw)
{
	current->online(this, nm, rw);
}

void Sessions::offline(int nm, int rw)
{
	current->offline(this, nm, rw);
}

void Sessions::inqueue(int nm, int rw)
{
	current->inqueue(this, nm, rw);
}


void ON::offline(Sessions* m, int nm, int rw)
{
	cout << "Session going from online to offline";
	order = new BridgeHaveNotOrder(nm, rw);
	order->info();
	m->setCurrent(new OFF());
	delete this;
}

void ON::inqueue(Sessions* m, int nm, int rw)
{
	cout << "Session going from online to queue";
	order = new BridgeHaveOrder(nm, rw, false);
	order->info();
	m->setCurrent(new INQ());
	delete this;
}

void OFF::inqueue(Sessions* m, int nm, int rw)
{
	cout << "Session going from offline to queue";
	order = new BridgeHaveOrder(nm, rw, false);
	order->info();
	m->setCurrent(new INQ());
	delete this;
}

void OFF::online(Sessions* m, int nm, int rw)
{
	cout << "Session going from offline to online";
	order = new BridgeHaveOrder(nm, rw, true);
	order->info();
	m->setCurrent(new ON());
	delete this;
}

void INQ::online(Sessions* m, int nm, int rw)
{
	cout << "Session going from queue to online";
	order = new BridgeHaveOrder(nm, rw, true);
	order->info();
	m->setCurrent(new ON());
	delete this;
}

void INQ::offline(Sessions* m, int nm, int rw)
{
	cout << "Session going from queue to offline";
	order = new BridgeHaveNotOrder(nm, rw);
	order->info();
	m->setCurrent(new OFF());
	delete this;
}

Sessions::Sessions()
{
	current = new INQ();
	cout << '\n';
}