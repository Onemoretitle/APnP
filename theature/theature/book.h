#pragma once
#include"instorege.h"

class IBook 
{ // ���������
public:
	virtual void order() = 0;
	virtual void pay() = 0;
};

