#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stack>

using namespace std;

int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
 
string infixToPostfix(string exp){
std::stack<char> temp;
temp.push('N');
string op;
int l=exp.length();
for (int i=0;i<l;i++){
    if (isalpha(exp[i]) || exp[i]=='#'){
        op+=exp[i];
    }
    else if (exp[i]=='('){
        temp.push('(');
    }
    else if (exp[i]==')'){
        while(temp.top() != 'N' && temp.top() != '(')
            {
                char c = temp.top();
                temp.pop();
                op += c;
            }
            if(temp.top() == '(')
            {
                char c = temp.top();
                temp.pop();
            }
    }
    else{
            while(temp.top() != 'N' && prec(exp[i]) <= prec(temp.top()))
            {
                char c = temp.top();
                temp.pop();
                op += c;
            }
            temp.push(exp[i]);
        }
}
while(temp.top() != 'N')
    {
                char c = temp.top();
                temp.pop();
                op += c;
    }
	return op;
}


int main(){
    string exp, op;
	cout<< "Enter string:";
	cin>>exp;
    op=infixToPostfix(exp);
	cout << op << endl;
    return 0;
}
