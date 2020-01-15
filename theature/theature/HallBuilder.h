#pragma once
#include "instorege.h"

class Number
{
public:
	int num;
	Number(int n) 
	{ 
		num = n; 
	}
	void info();
};

class Balcony
{
public:
	int capasity, row, price;
	Balcony(int seatsNum, int seatPrice)
	{
		price = seatPrice;
		capasity = seatsNum;
	}
	void info();
};

class Parter
{
public:
	int capasity, row, price;
	Parter(int seatsNum, int seatPrice)
	{
		price = seatPrice;
		capasity = seatsNum;
	}
	void info();
};

class High
{
public:
	int capasity, row, price;
	High(int seatsNum, int seatPrice)
	{
		price = seatPrice;
		capasity = seatsNum;
	}
	void info();
};

class MainScene
{
public:
	void info();
};

class OchestraPit
{
public:
	void info();
};

class RediualScene
{
public:
	void info();
};

class SmallScene
{
public:
	void info();
};

class Balc;
class Part;
class Hig;

class Seat 
{	
public:
	vector <seatStruct> seats;
	static Seat* createSeat(int type, int n, int seatsNum, int seatPrice, int rows);
	virtual void info() = 0;
};

class Balc : public Seat
{
public:
	Balc(int n, int seatsNum, int seatPrice, int rows)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < seatsNum / rows; j++)
			{
				seatStruct tmpSeat;
				tmpSeat.number = j + 1;
				tmpSeat.hallNum = n;
				tmpSeat.row = i + 1;
				tmpSeat.price = seatPrice;
				tmpSeat.type = "Balcony type";
				seats.push_back(tmpSeat);
			}
		}
	}
	void info();
};

class Part : public Seat
{
public:
	Part(int n, int seatsNum, int seatPrice, int rows)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < seatsNum / rows; j++)
			{
				seatStruct tmpSeat;
				tmpSeat.number = j + 1;
				tmpSeat.hallNum = n;
				tmpSeat.row = i + 1;
				tmpSeat.price = seatPrice;
				tmpSeat.type = "Parter seat";
				seats.push_back(tmpSeat);
			}
		}
	}
	void info();
};

class Hig : public Seat
{
public:
	Hig(int n, int seatsNum, int seatPrice, int rows)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < seatsNum / rows; j++)
			{
				seatStruct tmpSeat;
				tmpSeat.number = j + 1;
				tmpSeat.hallNum = n;
				tmpSeat.row = i + 1;
				tmpSeat.price = seatPrice;
				tmpSeat.type = "High seat";
				seats.push_back(tmpSeat);
			}
		}
	}
	void info();
};

// Фабрики Seat
/*class Factory
{
public:
	
	virtual ~Factory() {}
};

class BalcFactory : public Factory
{
public:
	Seat* createSeat(int n, int seatsNum, int seatPrice, int rows)
	{
		return new Balc(n, seatsNum, seatPrice, rows);
	}
};

class PartFactory : public Factory
{
public:
	Seat* createSeat(int n, int seatsNum, int seatPrice, int rows)
	{
		return new Part(n, seatsNum, seatPrice, rows);
	}
};

class HigFactory : public Factory
{
public:
	Seat* createSeat(int n, int seatsNum, int seatPrice, int rows)
	{
		return new Hig(n, seatsNum, seatPrice, rows);
	}
};
*/
class Scene
{
public:
	Scene(const char* fileName, const char* modificator)
	{
		strcpy(_name, fileName);
		strcpy(_mod, modificator);
	}
	const char* getName()
	{
		return _name;
	}
	void info();
private:
	char _name[20];
	char  _mod[100];

};

class FlyweightFactory
{
public:
	static Scene* getScene(const char* name, const char* mod)
	{
		for (int i = 0; i < _numScenes; i++)
		{
			if (!strcmp(name, _scenes[i]->getName()))
			{
				return _scenes[i];
			}
		}
		_scenes[_numScenes] = new Scene(name, mod);
		return _scenes[_numScenes++];
	}
private:
	enum
	{
		MAX_SCENES = 3
	};
	static int _numScenes;
	static Scene* _scenes[MAX_SCENES];
};

class ConcreteHall
{
public:
	vector<Number> num;
	vector<Balcony> bal;
	vector<Parter> pat;
	vector<High> hig;
	vector<Scene> sce;
	//vector<ScenesWithoutPit> wcp;
	//vector<RediualScene> res;
	//vector<SmallScene> sms;
	vector<Seat*> sts;

	void info();
};

class HallBuilder
{
protected:
	ConcreteHall* Hbuilder;
public:
	HallBuilder() : Hbuilder(0) {}
	virtual ~HallBuilder() {}
	virtual void createHall() = 0;//{};
	virtual void setNumber(int hallNumber) {};
	virtual void setBalcony(int hallNumber, int seatsNum, int seatPrice, int rows) {};
	virtual void setParter(int hallNumber, int seatsNum, int seatPrice, int rows) {};
	virtual void setHigh(int hallNumber, int seatsNum, int seatPrice, int rows) {};
	virtual void sceneType() {};

	virtual ConcreteHall* getArmy()
	{ 
		return Hbuilder;
	}
};

class BigHallBuilder : public HallBuilder
{
public:
	void createHall()
	{
		Hbuilder = new ConcreteHall;
	}
	void setNumber(int hallNumber);
	void setBalcony(int hallNumber, int seatsNum, int seatPrice, int rows);
	void setParter(int hallNumber, int seatsNum, int seatPrice, int rows);
	void setHigh(int hallNumber, int seatsNum, int seatPrice, int rows);
	void sceneType();
};

class SmallHallBuilder : public HallBuilder
{
public:
	void createHall()
	{
		Hbuilder = new ConcreteHall;
	}

	void setNumber(int hallNumber);
	void setParter(int hallNumber, int seatsNum, int seatPrice, int rows);
	void sceneType();
};
