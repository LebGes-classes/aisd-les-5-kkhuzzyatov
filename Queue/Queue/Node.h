#pragma once

#include <string>
#include <iostream>

class Node
{
	int priority;
	std::string value;

public:
	Node(int _priority, std::string _value);
	Node();
	~Node();
	void printInfo();
	int getPriority();
	std::string getValue();
};