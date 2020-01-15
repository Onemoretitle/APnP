#include "instorege.h"
#include "theature.h"
#include "Users.h"

TheaturePool* TheaturePool::instance = 0;

void createCheck(int blcNum, int patNum, int higNum)
{
	/*CountPr high(2500 * higNum);
	CountPr parter(500 * patNum);
	CountPr balcony(2000 * blcNum);
	Composite total(2000 * blcNum + 500 * patNum + 2500 * higNum);
	total.add(&balcony);
	total.add(&parter);
	total.add(&high);
	cout << "Cost: ";
	total.getStrength();
	cout << '\n';
	for (int i = 0; i < 3; i++)
	{
		total.volunteer();
		cout << '\n';
	}*/
	Highs tryOne;
	Parters tryTwo;
	Balconys tryThr;
	tryOne.add(&tryTwo);
	tryOne.add(&tryThr);
	tryThr.setNext(&tryOne);
	
	tryOne.handle(HIGH, higNum);
	tryOne.handle(BALCONY, blcNum);
	tryOne.handle(PARTER, patNum);
}

int getUserInput(string prompt)
{
	int input;
	cout << prompt;
	cin >> input;
	return input;
}

class Entrance
{
public:
	void create() 
	{
		cout << "APPLICATION THEATURE " << endl;
	}
	void pattern(string name) 
	{
		cout << "Pattern: " << name << endl;
	}
};

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
protected:
	Command(Entrance* p) : ivent(p) {}
	Entrance* ivent;
};

class CreateCommand : public Command
{
public:
	CreateCommand(Entrance* p) : Command(p) {}
	void execute() {
		ivent->create();
	}
};

class PattrenCommand : public Command
{
public:
	
	//ConcreteHall* bh = localDir.createHall(localBHbuilder, 1);
	//ConcreteHall* sh = localDir.createHall(localSHbuilder, 2);
	Compressor* dpoint = new Compressor(new Dnote);
	Compressor* apoint = new Compressor(new Anote);


	TTickets* Petr = new TTickets();
	TTickets* Vera = new TTickets();
	TTickets* Alex = new TTickets();
	HaveOrder* typePrepaid = new HaveOrder(2, 5, true);
	HaveOrder* typeNotPrepaid = new HaveOrder(3, 1, false);
	HaveNotOrder* typeNotBooked = new HaveNotOrder();

	BridgeBook* prepaid = new BridgeHaveOrder(2, 5, true);
	BridgeBook* notPrepaid = new BridgeHaveOrder(3, 1, false);
	BridgeBook* notBooked = new BridgeHaveNotOrder(5, 1);
	
	TheaturePool* pool = TheaturePool::getInstance();
	Theature* one;
	Theature* two;
	
	//Sessions* ses;

	PattrenCommand(Entrance* p) : Command(p) {}
	void execute() 
	{
		int patternType;
		patternType = getUserInput("Enter pattern type number: ");
		switch (patternType)
		{
		case 1:
		{
			ivent->pattern("---Decorator---");
			cout << "Bridge is not available now. Try callback it later" << endl
				<< "Anyway you can call Strategy (case 8) where Bridge already used";
			//meaasge->send();
			break;
		}
		case 2:
		{
			ivent->pattern("---Builder---");
			cout << "Builder is not available now. Try callback it later" << endl
				<< "Anyway you can call Object pool (case 6) where Builder already used";
			//cout << endl << "Grand hall:" << endl;
			//bh->info();
			//cout << "\nPrivate hall:" << endl;
			//sh->info();
			break;
		}
		case 3:
		{
			ivent->pattern("---Delegate---");
			cout << endl << "Petr:" << endl;
			Petr->takeOrder(typePrepaid);
			Petr->perfomOrders();
			cout << endl << "Vera:" << endl;
			Vera->takeOrder(typeNotPrepaid);
			Vera->perfomOrders();
			cout << endl << "Alex:" << endl;
			Alex->takeOrder(typeNotBooked);
			Alex->perfomOrders();
			break;
		}
		case 4:
		{
			ivent->pattern("---Chain-and-Composite---");
			//cout << "Price of current order ";
			createCheck(0,0,0);
			//curOrder->addUnit(createCheck(2, 5, 0));
			//cout << curOrder->getStrength() << " RUB." << endl;
			break;
		}
		case 5:
		{
			ivent->pattern("---Bridge---");
			cout << "Bridge is not available now. Try callback it later" << endl
				<< "Anyway you can call State (case 7) where Bridge already used";
			/*prepaid->info();
			notPrepaid->info();
			notBooked->info();*/
			break;
		}
		case 6:
		{
			ivent->pattern("---Object-Pool-(Singletone)---");
			one = pool->getTheature();
			one->setParamiters(1, 2, "FIRST", "STREET 1");
			one->info();
			cout << endl;
			two = pool->getTheature();
			two->setParamiters(2, 2, "SECOND", "STREET 2");
			two->info();
			cout << endl;
			pool->returnTheature(one);
			pool->returnTheature(two);
		
			cout << "reset" << endl;
			one = pool->getTheature();
			one->info();
			cout << endl;
			two = pool->getTheature();
			two->info();
			cout << endl;
			break;
		}
		case 7:
		{
			ivent->pattern("---State---");
			void(Sessions::* ptrs[])(int nm, int rw) =
			{
			  &Sessions::inqueue, &Sessions::offline, &Sessions::online
			};
			Sessions fsm;
			int num;
			cout << "\t 0 - queue \n\t 1 - offline \n\t 2 - online";
			do
			{
				cout << "\nEnter:";
				cin >> num;
				(fsm.*ptrs[num])(2, 3);
			} while (num != 1);

			break;
		}
		
		case 8: 
		{
			ivent->pattern("---Strategy---");
			dpoint->compress();
			cout << endl;
			apoint->compress();
			break;
		}
		default:
			cout << "Sorry but this pattern is still in work =) ";
			break;
		}
	}
};

int main(int argc, const char* argv[])
{
	Entrance enIvt;
	vector<Command*> v;
	v.push_back(new CreateCommand(&enIvt));
	v.push_back(new PattrenCommand(&enIvt));
	
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i]->execute();
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		delete v[i];
	}

	return 0;
}
