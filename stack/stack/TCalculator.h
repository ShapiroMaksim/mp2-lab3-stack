#pragma once
#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

class TCalculator
{
private:
	string infix, postfix;
	TStack <char> StackOperation;
	TStack <double> StackNumber;
	int Priority(const char m) const;
public:
	void ToPostfix();
	void SetInfix();
	string GetPostfix();
	double Calculator();
	TCalculator();
	~TCalculator();
};

TCalculator()
{
}

~TCalculator()
{
	delete[] infix;
	delete[] postfix;
	delete StackOperation;
	delete StackNumber;
}

int Priority(const char m) const
{
	switch(m)
	{
	case '(':
		return 0;
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	}
}

void ToPostfix()
{
	postfix = "";
	StackOperation.Clear();
	string tmp = "(" + infix + ")";
	for (int i = 0; i < tmp.size(); i++) 
	{
		if (tmp[i] == '(')
			StackOperation.Push(tmp[i]);
		if (tmp[i] >= '0'&& tmp[i] <= '9')
			postfix += tmp[i];
		if (tmp[i] == ')')
		{
			while (StackOperation.Top() != '(')
				postfix += StackOperation.Pop();
			StackOperation.Pop();
		}
		if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/' || tmp[i] == '^')
		{
			while (Priority(tmp[i]) <= Priority(StackOperation.Top()))
			{
				postfix += StackOperation.Pop();
				//StackOperation.Push(tmp[i]); 
			}
			StackOperation.Push(tmp[i]);
		}
	}
}

void SetInfix()
{
	infix.clear();
	char c;
	while(true)
	{
		c=getchar();
		if(c==/n)
			break;
		infix+=c;
	}
}

string GetPostfix()
{
	this.ToPostfix;
	return postfix;
}