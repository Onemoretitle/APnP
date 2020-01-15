#include "Tickets.h"

void TTickets::perfomOrders() 
{
	for (vector<ptrOrder>::iterator ordIt = orders.begin(); ordIt != orders.end(); ordIt++)
	{
		(*ordIt)->order();
		(*ordIt)->pay();
	}
}

void TTickets::takeOrder(IBook* newOrder)
{
	orders.push_back(newOrder);
}

void TTickets::deliteOrder(int seat)
{
	orders.erase(orders.begin() + seat);
}


