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

void append(char* s, char e)
{
        int len = strlen(s);
        s[len] = e;
        s[len+1] = '\0';
}
 
char infixToPostfix(char exp[100]){
std::stack<char> temp;
temp.push('N');
char op[100];
op[0]='\0';
int l=strlen(exp);
for (int i=0;i<l;i++){
    if (isalpha(exp[i]) || exp[i]=='#'){
        append(op,exp[i]);
    }
    else if (exp[i]=='('){
        temp.push('(');
    }
    else if (exp[i]==')'){
        while(temp.top() != 'N' && temp.top() != '(')
            {
                char c = temp.top();
                temp.pop();
                append(op,c);
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
                append(op,c);
            }
            temp.push(exp[i]);
        }
}
while(temp.top() != 'N')
    {
                char c = temp.top();
                temp.pop();
                append(op,c);
    }
	strcpy(exp,op);
}

char tempCat(char exp[100]){
    int i,j=0;
    char temp[100];
    for(i=0; i<100; i++){
        if(i==0){
            temp[j]=exp[i];
            j++;
        }

        else if((isalpha(exp[i]) && isalpha(exp[i-1])) || (isalpha(exp[i]) && exp[i-1]=='*') || (exp[i]=='#' && (isalpha(exp[i-1]) || exp[i-1]=='*'))){
            temp[j]='.';
            temp[j+1]=exp[i];
            j=j+2;
        }

        else{
        temp[j]=exp[i];
        j++;
        }

    }
    strcpy(exp,temp);
}

int * nullfplp(char exp[100]){
    int l,i;
    int nullb[100];
    l=strlen(exp);
    for(i=0; i<l; i++){
        if(isalnum(exp[i]) || exp[i]=='#'){
            nullb[i]=0;
        }
        else if(exp[i]=='*'){
            nullb[i]=1;
        }
        else if(exp[i]=='+'){
            if(nullb[i-2]==1 || nullb[i-1]==1){
            nullb[i]=1;
            }
            else
            nullb[i]=0;
        }
        else if(exp[i]=='.'){
            if(nullb[i-2]==1 && nullb[i-1]==1){
            nullb[i]=1;
            }
            else
            nullb[i]=0;
        }
    }
    
    cout<<"Nullable:"<<endl;
    for(i=0; i<l; i++){
        cout<<exp[i]<<": ";
        if(nullb[i]==0){
            cout<<"False"<<endl;
        }
        else if(nullb[i]==1){
            cout<<"True"<<endl;
        }
    }
    
	int fp[100][100], lp[100][100], pos[100];
	int j=0,k=0, val=1;
    for(i=0; i<l; i++){
		if(isalnum(exp[i]) || exp[i]=='#'){
			pos[i]=val;
			val=val+1;
		}
	}
    /*-------------------------------------------FIRSTPOS---------------------------------------------*/	
	
	for(i=0; i<l; i++){
		if(isalnum(exp[i]) || exp[i]=='#'){
			fp[i][0]=pos[i];
		}
		
		else if(exp[i]=='+'){
			j=0;k=0;
			while((fp[i-2][j])!='\0'){
				fp[i][k]=fp[i-2][j];
				j=j+1;
				k=k+1;
			}
			j=0;
			while((fp[i-1][j])!='\0'){
				fp[i][k]=fp[i-1][j];
				j=j+1;
				k=k+1;
			}
		}
		else if(exp[i]=='*'){
			for(j=0; j<l; j++){
				fp[i][j]=fp[i-1][j];
			}
		}
		else if(exp[i]=='.'){
			if(nullb[i-2]==1){
					j=0;k=0;
				while((fp[i-2][j])!='\0'){
					fp[i][k]=fp[i-2][j];
					j=j+1;
					k=k+1;
				}
				j=0;
				while((fp[i-1][j])!='\0'){
					fp[i][k]=fp[i-1][j];
					j=j+1;
					k=k+1;
				}
			}
			else{
			for(j=0; j<l; j++){
				fp[i][j]=fp[i-2][j];
			}
			}
		}
	}
	
	cout<<endl<<"Firstpos:"<<endl;
	for(i=0; i<l; i++){
		cout<<exp[i]<<": ";
        for(j=0; j<l; j++){
        	if(fp[i][j]=='\0'){
        		continue;
			}
			else
        	cout<<fp[i][j]<<" ";
		}
		cout<<endl;
    }
    
    /*-------------------------------------------LASTPOS---------------------------------------------*/
    
    for(i=0; i<l; i++){
		if(isalnum(exp[i]) || exp[i]=='#'){
			lp[i][0]=pos[i];
		}
		
		else if(exp[i]=='+'){
			j=0;k=0;
			while((lp[i-2][j])!='\0'){
				lp[i][k]=lp[i-2][j];
				j=j+1;
				k=k+1;
			}
			j=0;
			while((lp[i-1][j])!='\0'){
				lp[i][k]=lp[i-1][j];
				j=j+1;
				k=k+1;
			}
		}
		else if(exp[i]=='*'){
			for(j=0; j<l; j++){
				lp[i][j]=lp[i-1][j];
			}
		}
		else if(exp[i]=='.'){
			if(nullb[i-1]==1){
					j=0;k=0;
				while((lp[i-2][j])!='\0'){
					lp[i][k]=lp[i-2][j];
					j=j+1;
					k=k+1;
				}
				j=0;
				while((fp[i-1][j])!='\0'){
					lp[i][k]=lp[i-1][j];
					j=j+1;
					k=k+1;
				}
			}
			else{
			for(j=0; j<l; j++){
				lp[i][j]=lp[i-1][j];
			}
			}
		}
	}
	
	cout<<endl<<"Lastpos:"<<endl;
	for(i=0; i<l; i++){
		cout<<exp[i]<<": ";
        for(j=0; j<l; j++){
        	if(lp[i][j]=='\0'){
        		continue;
			}
			else
        	cout<<lp[i][j]<<" ";
		}
		cout<<endl;
    }
    
    /*-------------------------------------------FOLLOWPOS---------------------------------------------*/
	
	int folp[100][100];
	int pt=0,n=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<5;j++)
		{
			folp[i][j]='\0';
		}
	}
	for(j=0;j<l;j++)
	{
		folp[j][0]=j+1;
	}
	while(exp[n]!='\0')
	{
		if(exp[n]=='*')
		{
			for(i=0;lp[n][i]!='\0';i++)
			{
				pt=0;
				for(j=0;fp[n][j]!='\0';j++)
				{
					while(folp[(lp[n][i])-1][pt]!='\0')
						pt++;
					folp[(lp[n][i])-1][pt++]=fp[n][j];
				}
			}
		}
		if(exp[n]=='.')
		{
			for(i=0;lp[n-2][i]!='\0';i++)
			{
				pt=0;
				for(j=0;fp[n-1][j]!='\0';j++)
				{
					while(folp[(lp[n-2][i])-1][pt]!='\0')
						pt++;
					folp[(lp[n-2][i])-1][pt++]=fp[n-1][j];
				}
			}
		}n++;	
	}
	folp[l-1][1]='d';
	
	int alp=0;
	for(i=0; i<l; i++){
		if(isalnum(exp[i]) || exp[i]=='#')
		alp++;
	}
	 	
	cout<<endl<<"Followpos: "<<endl;
	for(i=0;i<alp;i++)
	{
		cout<<folp[i][0]<<"\t";
		for(j=1;j<5;j++)
		{
			if(folp[i][j]=='\0')
				break;
			cout<<folp[i][j]<<" ";
		}
		cout<<endl;
	}
	

}


int main(){
    char exp[100], con[100], op[100];
    int * nullb;
	cout<< "Enter Regular Expression:";
	cin>>exp;
    strcat(exp,"#");
    tempCat(exp);
    cout<<endl<<"Regular Expression with concatenation:"<<endl<<exp<<endl;
    infixToPostfix(exp);
    cout<<endl<<"The syntax tree is: "<<endl<<exp<<endl<<endl;
    nullfplp(exp);
    return 0;
}