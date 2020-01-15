#pragma once
#include "instorege.h"
class DNotifier
{
public:
	virtual void send() = 0;
};

class ConreteDNotifier : public DNotifier
{
	const char* message;
public:
	ConreteDNotifier(const char* note)
	{
		message = note;
	}

	void send();
};

class Decorator : public DNotifier 
{
	DNotifier* wrappee; 
public:
	Decorator(DNotifier* wrpee)
	{
		wrappee = wrpee;
	}

	void send();
};

class DSms : public Decorator
{
public:
	DSms(DNotifier* wrpee) : Decorator(wrpee) {}

	void send();
};

class DEmail : public Decorator
{
public:
	DEmail(DNotifier* wrpee) : Decorator(wrpee) {}

	void send();
};

class DAccount : public Decorator
{
public:
	DAccount(DNotifier* wrpee) : Decorator(wrpee) {}

	void send();
};


class AdaptedMessage
{
public:
	const char* takeMessage(const char* message) 
	{
		const char* note = message;
		return note;
	}
};

class ANotifier
{
public:
	virtual ~ANotifier() {}
	virtual void send(const char* message) {};
};

class Adapter : public ANotifier
{
public:
	Adapter(AdaptedMessage* p) : p_ames(p) {}
	~Adapter() 
	{
		delete p_ames;
	}
	void send(const char* message)
	{
		cout << p_ames->takeMessage(message) << " IT'S ADAPTED MESSAGE" << endl;
	}
private:
	AdaptedMessage* p_ames;
};


class Compression
{
public:
	virtual ~Compression() {}
	virtual void compress() = 0;
};

class Dnote : public Compression
{
public:
	DNotifier* message = new DAccount(new DSms(new DEmail(new ConreteDNotifier("THIS IS A PURE MASSAGE"))));
	void compress() {
		cout << "--Decorator--" << endl;
		message->send();
	}
};

class Anote : public Compression
{
public:
	ANotifier* message = new Adapter(new AdaptedMessage());
	void compress() {
		cout << "--Adapter--" << endl;
		message->send("message");
	}
};

class Compressor
{
public:
	Compressor(Compression* comp) : p(comp) {}
	~Compressor() { delete p; }
	void compress()
	{
		p->compress();
	}
private:
	Compression* p;
};


