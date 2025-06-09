#include "User.h"

Node::Node(int _priority, std::string _value)
{
	this->priority = _priority;
	this->value = _value;
}

Node::Node()
{
	this->priority = 0;
	this->value = "None";
}

User::~User()
{
	delete this;
}

void User::printInfo()
{
	std::cout << "Value: " << this->value << "\n";
}

int User::getPriority()
{
	return this->priority;
}

std::string User::getValue()
{
	return this->value;
}
