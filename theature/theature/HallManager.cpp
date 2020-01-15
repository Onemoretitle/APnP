#include "HallManager.h"

ConcreteHall* HallManager::createHall(HallBuilder& builder, int num)
{
	builder.createHall();
	builder.setNumber(num);
	builder.setBalcony(num, 2, 2000, 2);
	builder.setParter(num, 5, 500, 6);
	builder.setHigh(num, 2, 2500, 5);
	builder.sceneType();
	return(builder.getArmy());
}