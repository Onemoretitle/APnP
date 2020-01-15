#pragma once
#include "instorege.h"
#include "HallManager.h"
#include "Tickets.h"
#include "Sessions.h"

typedef HallManager localDir;
typedef BigHallBuilder localBHbuilder;
typedef SmallHallBuilder localSHbuilder;

class Theature
{
public:
	vector <ConcreteHall*> halls;
	const char* name;
	const char* addres;
	vector <char*> repertoire;
	int numberOfHalls;
public:
	Theature()
	{
		halls.clear();
		repertoire.clear();
		name = "";
		addres = "";
		numberOfHalls = 0;
	}
	void reset();
	void info();
	void setParamiters(int numberBigHalls_, int nuberSmallHalls_, const char* name_, const char* addres_);
};
//singleton.
class TheaturePool
{
private:
	list<Theature*> theatures;
	static TheaturePool* instance;
	TheaturePool() {}
public:
	static TheaturePool* getInstance();
	
	Theature* getTheature();
	
	void returnTheature(Theature* object);
};
