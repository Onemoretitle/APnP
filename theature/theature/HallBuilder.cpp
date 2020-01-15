#include "HallBuilder.h"

int FlyweightFactory::_numScenes = 0;
Scene* FlyweightFactory::_scenes[];

//Seat* factory = new Seat;

void Number::info()
{
	cout << endl << "Hall number: " << num << endl;
}

void Balcony::info()
{
	cout << endl << "Balcony" << endl << "Seats in balcony: " << capasity << endl << "Seat price: " << price << endl;
}
void Parter::info()
{
	cout << endl << "Parter" << endl << "Seats in parter: " << capasity << endl << "Seat price: " << price << endl;
}
void High::info()
{
	cout << endl << "High" << endl << "Seats in high: " << capasity << endl << "Seat price: " << price << endl;
}

void Scene::info() 
{
	if (_mod != " ")
		cout << "Scene type " << _name << " " << _mod << endl;
	else
		cout << "Scene type " << _name << endl;
}
void MainScene::info()
{
	cout << endl << endl << "Main scene";
}
void OchestraPit::info() 
{
	cout << " with Ochestra pit" << endl;
}
void RediualScene::info()
{
	cout << endl << endl << "Rediual scene";
}
void SmallScene::info()
{
	cout << endl << endl << "Small scene";
}

void ConcreteHall::info()
{
	int i;
	for (i = 0; i < num.size(); ++i)  num[i].info();
	for (i = 0; i < bal.size(); ++i)  bal[i].info();
	for (i = 0; i < pat.size(); ++i)  pat[i].info();
	for (i = 0; i < hig.size(); ++i)  hig[i].info();
	for (i = 0; i < sce.size(); ++i)  sce[i].info();
	//for (i = 0; i < ocp.size(); ++i)  ocp[i].draw();
	//for (i = 0; i < wcp.size(); ++i)  wcp[i].draw();
	for (i = 0; i < sts.size(); ++i)  sts[i]->info();
}

Seat* Seat::createSeat(int type, int n, int seatsNum, int seatPrice, int rows)
{
	if (type == BALCONY)
	{
		return new Balc(n, seatsNum, seatPrice, rows);
	}
	if (type == PARTER)
	{
		return new Part(n, seatsNum, seatPrice, rows);
	}
	if (type == HIGH)
	{
		return new Hig(n, seatsNum, seatPrice, rows);
	}
};
void Balc::info() 
{
	cout << endl << "Balcony seats" << endl;
	for (int i = 0; i < seats.size() ; i++)
	{
		//cout << "Seat hall: " << seats[i].hallNum << endl;
		cout << "Seat number: " << seats[i].number;
		cout << " row: " << seats[i].row << endl;
		//cout << "Seat price: " << seats[i].price << endl;
		//cout << "Seat type: " << seats[i].type << endl;
	}
}
void Part::info()
{
	cout << endl << "Parter seats" << endl;
	for (int i = 0; i < seats.size(); i++)
	{
		//cout << "Seat hall: " << seats[i].hallNum << endl;
		cout << "Seat number: " << seats[i].number;
		cout << " row: " << seats[i].row << endl;
		//cout << "Seat price: " << seats[i].price << endl;
		//cout << "Seat type: " << seats[i].type << endl;
	}
}
void Hig::info()
{
	cout << endl << "High seats" << endl;
	for (int i = 0; i < seats.size(); i++)
	{
		//cout << "Seat hall: " << seats[i].hallNum << endl;
		cout << "Seat number: " << seats[i].number;
		cout << " row: " << seats[i].row << endl;
		//cout << "Seat price: " << seats[i].price << endl;
		//cout << "Seat type: " << seats[i].type << endl;
	}
}

void BigHallBuilder::setNumber(int hallNumber)
{ 
	Hbuilder->num.push_back(Number(hallNumber)); 
};
void BigHallBuilder::setBalcony(int hallNumber, int seatsNum, int seatPrice, int rows)
{
	Hbuilder->bal.push_back(Balcony(seatsNum, seatPrice)); 
	Hbuilder->sts.push_back(Seat::createSeat(BALCONY, hallNumber, seatsNum, seatPrice, rows));
};
void BigHallBuilder::setParter(int hallNumber, int seatsNum, int seatPrice, int rows)
{
	Hbuilder->pat.push_back(Parter(seatsNum, seatPrice));
	Hbuilder->sts.push_back(Seat::createSeat(PARTER, hallNumber, seatsNum, seatPrice, rows));
};
void BigHallBuilder::setHigh(int hallNumber, int seatsNum, int seatPrice, int rows)
{
	Hbuilder->hig.push_back(High(seatsNum, seatPrice));
	Hbuilder->sts.push_back(Seat::createSeat(HIGH, hallNumber, seatsNum, seatPrice, rows));
};
void BigHallBuilder::sceneType()
{
	Hbuilder->sce.push_back(*FlyweightFactory::getScene("Main scene", "with ochrstra pit"));
	//Hbuilder->ocp.push_back(OchestraPit());
};

void SmallHallBuilder::setNumber(int hallNumber)
{
	Hbuilder->num.push_back(Number(hallNumber));
};
void SmallHallBuilder::setParter(int hallNumber, int seatsNum, int seatPrice, int rows)
{
	Hbuilder->pat.push_back(Parter(seatsNum, seatPrice));
	Hbuilder->sts.push_back(Seat::createSeat(PARTER, hallNumber, seatsNum, seatPrice, rows));
};
void SmallHallBuilder::sceneType()
{
	Hbuilder->sce.push_back(*FlyweightFactory::getScene("Small scene", " "));
};