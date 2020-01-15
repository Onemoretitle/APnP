#include "brige.h"

void BridgeBookImp::info()
{
	cout << "Ticket number " << num
		<< " in row " << row << endl;
}

void BridgeHaveOrderImp::info()
{
	cout << endl
		<< "Ticket number " << num
		<< " in row " << row
		<< " is booked" << endl
		<< "Status: ";
	if (pay_)
	{
		cout << "Payment is successful" << endl;
	}
	else
	{
		cout << "Whaiting a payment" << endl;
	}
}

void BridgeHaveNotOrderImp::info()
{
	cout << endl
		<< "Ticket number " << num
		<< " in row " << row
		<< " is not booked" << endl
		<< "Status: Need book a ticket to make a payment" << endl;
}