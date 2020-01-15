#include "payOrder.h"

void HaveOrder::order()
{
	cout <<". Ticket number " << num << " in row " << row << " is booked." << endl;
};

void HaveOrder::pay()
{
	if (havePayment)
	{
		cout << "Payment is successful" << endl;
	}
	else 
	{
		cout << "Whaiting a payment" << endl;
	}
};

void HaveNotOrder::order()
{

	cout << "Ticket is not booked" << endl;
};

void HaveNotOrder::pay()
{
	cout << "Need book a ticket to make a payment" << endl;
};
