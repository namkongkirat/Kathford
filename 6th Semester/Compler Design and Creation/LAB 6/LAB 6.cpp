#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;
char stack[20];
int top = -1;
 
string getString(char x)
{
	string s(1,x);
	return s;
}

string IntToString(int a)
{
	ostringstream temp;
	temp<<a;
	return temp.str();
}

void push(char x)
{
	stack[++top] = x;
}

char pop()
{
	if(top==-1)
		return -1;
	else
		return stack[top--];
}

int priority(char x)
{
	if(x == '(')
		return 0;
	if(x == '+' || x == '-')
		return 1;
	if(x == '*' || x == '/')
		return 2;
}

bool isOperator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		return true;
	else 
		return false;
}

int main()
{
	char exp[20];
	string pexp;
	string t[20];
	string tac_stack[20];
	int terms = 0;
	char *e,x;
	int n=0;
	cout<<"Enter the expression: ";
	cin>>exp;
	e=exp;
	while(*e != '\0')
	{
		if(isalnum(*e))
		{
			pexp.append(getString(*e));
		}
		else if(*e == '(')
			push(*e);
		else if(*e == ')')
		{
			while((x=pop()) != '(')
			{
				pexp.append(getString(x));
			}
		}
		else
		{
			while (priority(stack[top]) >= priority(*e))
			{
				pexp.append(getString(pop()));
			}
			push(*e);
		}
		e++;
	}
	
	while(top != -1)
	{
		pexp.append(getString(pop()));
	}
	
	for (int i=0;pexp[i] != '\0'; i++)
	{
		if(isOperator(pexp[i]))
		{
			int temp=0;
			if(i == pexp.length()-1)
			{
				t[terms].append(tac_stack[temp]);
				t[terms].append(getString(pexp[i]));
				t[terms].append(tac_stack[temp+1]);
				tac_stack[terms].append("a");
				terms++;
				break;
			}
			t[terms].append(getString(pexp[i-2]));
			t[terms].append(getString(pexp[i]));
			t[terms].append(getString(pexp[i-1]));
			tac_stack[terms].append("t" + IntToString(terms+1));
			terms++;
		}
	}
	cout<<"The three address code is:"<<endl;
	for(int i=0; terms != 0; i++)
	{
		cout<<tac_stack[i]<<" = "<<t[i]<<endl;
		terms--;
	}
}