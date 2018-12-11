#include "TCalculator.h"

TCalculator::TCalculator()
{
}


TCalculator::~TCalculator()
{
}

int TCalculator::Priority(const char m) const
{
	switch (m)
	{
	case '(':
		return 0;
	case  '+':
		return 1;
	case  '-':
		return 1;
	case  '*':
		return 2;
	case  '/':
		return 2;
	case  '^':
		return 3;
	default:throw m;
	}
}

void TCalculator::ToPostfix()
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
			postfix += ' ';
			while (Priority(tmp[i]) <= Priority(StackOperation.Top()))
			{
				postfix += StackOperation.Pop();
				//StackOperation.Push(tmp[i]); ///////////////////////////////////////////
			}
			StackOperation.Push(tmp[i]);
		}
	}
}
void TCalculator::SetInfix() 
{
	infix.clear();
	char c;
	while (1) 
	{
		c = getchar();
		if (c == '\n')
			break;
		else
			infix += c;
	}
	
}
string TCalculator::GetPostfix() 
{
	this->ToPostfix();
	return postfix;
}

double TCalculator::Calculator() 
{
	double num1, num2, res,tmp;
	StackNumber.Clear();
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') 
		{
			num2 = StackNumber.Pop();
			num1 = StackNumber.Pop();
			switch (postfix[i])
			{
			case '+':
				res = num1 + num2;
				break;
			case '-':
				res = num1 - num2;
				break;
			case '*':
				res = num1 * num2;
				break;
			case '/':
				res = num1 / num2;
				break;
			case '^':
				res = pow(num1,num2);
				break;
			
			}
			StackNumber.Push(res);
		}
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			char *p;
			double x;
			x = strtod(&postfix[i], &p);
			StackNumber.Push(x);
			int Lenght = p - &postfix[i];
			i += Lenght - 1;
		}
	}
	tmp = StackNumber.Pop();
	return tmp;
}