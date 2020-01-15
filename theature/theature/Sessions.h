#pragma once
#include "brige.h"

class Sessions
{
	class State* current;
public:
	Sessions();
	void setCurrent(State* s)
	{
		current = s;
	}
	void online(int nm, int rw);
	void offline(int nm, int rw);
	void inqueue(int nm, int rw);
};

class State
{
public:
	BridgeBook* order = new BridgeBook();
	virtual void online(Sessions* m, int nm, int rw)
	{
		cout << "Session already online\n";
	}
	virtual void offline(Sessions* m, int nm, int rw)
	{
		cout << "Session already offline\n";
	}
	virtual void inqueue(Sessions* m, int nm, int rw)
	{
		cout << "Session already in queue\n";
	}
};

class ON : public State
{
public:
	ON()
	{
		cout << "Session is online ";
	};
	~ON()
	{
		cout << "repleaced from online session\n";
	};
	void inqueue(Sessions* m, int nm, int rw);
	void offline(Sessions* m, int nm, int rw);
};

class OFF : public State
{
public:
	OFF()
	{
		cout << "Session is offline ";
	};
	~OFF()
	{
		cout << "repleaced from offline session\n";
	};
	void inqueue(Sessions* m, int nm, int rw);
	void online(Sessions* m, int nm, int rw);
};

class INQ : public State
{
public:
	INQ()
	{
		cout << "Session in queue ";
	};
	~INQ()
	{
		cout << "repleaced from queue session\n";
	};
	void online(Sessions* m, int nm, int rw);
	void offline(Sessions* m, int nm, int rw);
};


