#pragma once
#include "instorege.h"
#include "HallBuilder.h"

class HallManager
{
public:
	ConcreteHall* createHall(HallBuilder& builder, int num);
};

