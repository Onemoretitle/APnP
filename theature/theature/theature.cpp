#include "theature.h"

void Theature::reset() 
{
	halls.clear();
	repertoire.clear();
	name = "";
	addres = "";
	numberOfHalls = 0;
}

void Theature::info() 
{
	cout << "Addres: " << addres << endl
		<< "Theature " << name << endl
		<< "With capasity in " << numberOfHalls << " halls" << endl;
	for (int i = 0; i < halls.size(); i++)
	{
		halls[i]->info();
	}
}

void Theature::setParamiters(int numberBigHalls_, int nuberSmallHalls_, const char* name_, const char* addres_)
{
	localDir build;
	localBHbuilder bigH;
	localSHbuilder smallH;
	for (int i = 0; i < numberBigHalls_; i++)
	{
		halls.push_back(build.createHall(bigH, i + 1));
	}
	for (int i = numberBigHalls_; i < numberBigHalls_ + nuberSmallHalls_; i++)
	{
		halls.push_back(build.createHall(smallH, i + 1));
	}
	repertoire.clear();
	name = name_;
	addres = addres_;
	numberOfHalls = numberBigHalls_ + nuberSmallHalls_;
}

TheaturePool* TheaturePool::getInstance()
{
	if (instance == 0)
	{
		instance = new TheaturePool;
	}
	return instance;
}

Theature* TheaturePool::getTheature() 
{
	if (theatures.empty())
	{
		cout << "Creating new." << endl << endl;
		return new Theature;
	}
	else
	{
		cout << "Reusing existing." << endl << endl;
		Theature* resource = theatures.front();
		theatures.pop_front();
		return resource;
	}
}

void TheaturePool::returnTheature(Theature* object)
{
	object->reset();
	theatures.push_back(object);
}