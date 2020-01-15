#pragma once
#include "instorege.h"
#include "Sessions.h"
#include "HallManager.h"


class TConcertHalls
{
private:
	vector <seatStruct> seats;
	int number, capasity;
	bool balcony, parter, high;
	const char* scene;


public:

	TConcertHalls()	{};
	~TConcertHalls() {};

};

