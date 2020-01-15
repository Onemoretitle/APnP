#include "Notifier.h"
void ConreteDNotifier::send()
{
	cout << "Message: " << message;
};

void Decorator::send()
{
	wrappee->send();
};

void DSms::send()
{
	Decorator::send();
	cout << " this is SMS";
};

void DEmail::send()
{
	Decorator::send();
	cout << " this is E-mail";
};

void DAccount::send()
{
	Decorator::send();
	cout << " this is account notification";
};