#include<iostream>
#include<string.h>

using namespace std;
int count = 0;
string getString(char x) 
{ 
    string s(1, x); 
    return s;    
}

struct production{   
    string left, right;
};

struct nterm {
    string value, first, follow;
};

string terminals[20];
string nonterminals[20];
string ptable[20][20];

string inpString = "i*i+i";
string stack;

bool isterm(string str, struct nterm nterm[]){
    for(int i = 0; nterm[i].value != "\0"; i++){
        if(nterm[i].value == str){
            return false;
        }
    }
    return true;
}

void appendChar(string str, char* arr){
    int i;
    bool c= false;
    for(int j = 0 ; j< str.length(); j++){
        for(i = 0 ; arr[i] !='\0' ; i++){
            if(str[0] == arr[i]){
                c = true;
            }
        }
        if(!c){
            arr[i] = str[0];
            arr[i+1] = '\0';
        }
    }
}

bool checkExists(char ch, string str){
    for(int i = 0 ; i < str.length() ; i++){
        if(ch == str[i]){
            return true;
        }
        else{
            return false;
        }
    }
}

string calculateFirst(string str, struct nterm nterm[], struct production prod[], int n){
    string s;
    if(isterm(str, nterm)){
        return str;
    }
    for(int i = 0; i < n; i++){
        if(str == prod[i].left){
            count++;
            s.append(calculateFirst(getString(prod[i].right[0]), nterm, prod, n));
            if(count > 0){
                for(int k = i+1; k < n ; k++){
                    if(str == prod[k].left){
                        s.append(calculateFirst(getString(prod[i+1].right[0]), nterm, prod, n));
                    }
                    
                }
                count--;
            }
            return s;
        }
    }
}

void first(struct nterm nterm[], struct production prod[], int n){
    for(int i = 0; i < n; i++){
        if(isterm(getString(prod[i].right[0]), nterm)){
            for(int j = 0 ; nterm[j].value != "\0"; j++){
                if(prod[i].left == nterm[j].value){
                    nterm[j].first.append(getString(prod[i].right[0]));
                }
            }
        }
    }
    for(int i = 0; nterm[i].value != "\0"; i++){
        for(int j = 0; j < n; j++){
            if(nterm[i].value == prod[j].left){
                if(!isterm(getString(prod[j].right[0]), nterm)){
                     nterm[i].first.append(calculateFirst(getString(prod[j].right[0]), nterm, prod, n));
                }
            }
        }
    }
}

string getFirst(string str, struct nterm nterm[], struct production prod[]){
    for(int i = 0; nterm[i].value!= "\0"; i++){
        if(str == nterm[i].value){
            return nterm[i].first;
        }
    }
}


void calcFollow(struct nterm nterm[], struct production prod[], int n){
    string tempfirst;
    for(int i = 0; nterm[i].value != "\0"; i++){
        if(nterm[i].value == prod[0].left){
            nterm[i].follow.append("$");
        }

        for(int j = 0 ; j < n; j++){
            for(int k = 0; prod[j].right[k] != '\0'; k++){
                if(nterm[i].value == getString(prod[j].right[k])){
                    if(isterm(getString(prod[j].right[k+1]), nterm)){
                        nterm[i].follow.append(getString(prod[j].right[k+1]));
                    }
                    else if(!isterm(getString(prod[j].right[k+1]), nterm)){
                        if(k+2 == prod[j].right.length()){
                            for(int m = 0; nterm[m].value != "\0"; m++){
                                if(nterm[m].value == getString(prod[j].left[0])){
                                    nterm[i].follow.append(nterm[m].follow);
                                }
                            }
                        }
                        tempfirst = getFirst(getString(prod[j].right[k+1]), nterm, prod);
                        for(int l = 0; l < tempfirst.length(); l++){
                            if(tempfirst[l] == '#'){
                                continue;
                            }
                            else{
                                if(!checkExists(tempfirst[l], nterm[i].follow)){
                                    nterm[i].follow.append(getString(tempfirst[l]));
                                }   
                            }
                        }
                    } 
                }
            }
        }
    }
}

bool exists(struct nterm temp[], string test, int n){
    for(int i = 0; i < n; i++){
        if(test == temp[i].value){
            return true;
        }
    }
    return false;
}

int indexOfnterm(string str, struct nterm nterm[]){
    for(int i = 0; nterm[i].value != "\0"; i++){
        if(str == nterm[i].value){
            return i;
        }
    }
}

bool termExists(string str, string terminals[]){
    for(int i = 0; terminals[i]!= "\0"; i++){
        if(str == terminals[i]){
            return true;
        }
        else{
            return false;
        }

    }
}

int getTermIndex(string term){
    for(int i = 0 ; terminals[i] != "\0"; i++){
        if(term == terminals[i]){
            return i;
        }
    }
}

int getNTermIndex(string nonterm){
    for(int i = 0 ; nonterminals[i] != "\0"; i++){
        if(nonterm == nonterminals[i]){
            return i;
        }
    }
}

void constructParsingTable(struct nterm nterm[], struct production prod[], int n){
    for(int i = 0 ; i < n ; i++){
        if(prod[i].right[0] == '#'){
            for(int j = 0 ; nterm[j].value != "\0"; j++){
                if(nterm[j].value == getString(prod[i].left[0])){
                    for(int k = 0; nterm[j].follow[k] != '\0'; k++){
                        ptable[getNTermIndex(nterm[j].value)][getTermIndex(getString(nterm[j].follow[k]))] = prod[i].right;
                    }
                }
            }
        }
        else if(!isterm(getString(prod[i].right[0]), nterm)){
            for(int j = 0 ; nterm[j].value != "\0"; j++){
                if(nterm[j].value == getString(prod[i].right[0])){
                    for(int k = 0; nterm[j].first[k] != '\0'; k++){
                        ptable[getNTermIndex(getString(prod[i].left[0]))][getTermIndex(getString(nterm[j].first[k]))] = prod[i].right;
                    }
                }
            }
        }
        else if(isterm(getString(prod[i].right[0]), nterm)){
            ptable[getNTermIndex(getString(prod[i].left[0]))][getTermIndex(getString(prod[i].right[0]))] = prod[i].right;
        }
    }
}

string topOfStack(string stack){
    int i=0;
    while(stack[i] != '\0'){
        i++;
    }
    return getString(stack[i-1]);
}

string getFromTable(string ts, string curChar){
    return ptable[getNTermIndex(ts)][getTermIndex(curChar)];
}

bool interpretString(string inpStr, string stack, struct nterm nterm[]){
    string curChar, ts, tval;
    int current;
    cout<<"Top of Stack\t";
    cout<<"Input"<<endl;
    
    while(true){
        curChar = inpStr[current];
        ts = topOfStack(stack); 
        cout<<ts<<"\t\t";
        cout<<curChar<<endl;
        if(isterm(ts, nterm) || ts == "$"){
            if(curChar == ts){
                stack = stack.substr(0, stack.length()-1);
                current++;
            }
            else{
                return false;
            }
        }
        else{
            stack = stack.substr(0, stack.length()-1);
            tval = getFromTable(ts, curChar);
            if(tval=="\0"){
                return false;
            }
            for(int i = tval.length()-1; i>=0; i--){
                if(tval[i] == '#'){
                    continue;
                }
                stack.append(getString(tval[i]));
            }
        }
        if(ts == "$"){
            return true;
        }
    }
}

int main(){
    int n;
    // cout<<"How many productions are there?";
    // cin>>n;
    n = 8;
    struct production prod[n];
    struct nterm nterm[10];
    // for(int i = 0; i < n; i++){
    //     cout<<"Enter non-terminal(left side) of "<<i+1<<" production: ";
    //     cin>>prod[i].left;
    //     cout<<"Enter right side of "<<i+1<<" production: ";
    //     cin>>prod[i].right;
    // }
    prod[0].left = "E"; 
    prod[0].right = "TB";
    prod[1].left = "B";
    prod[1].right = "+TB";
    prod[2].left = "B";
    prod[2].right = "#";    
    prod[3].left = "T";
    prod[3].right = "FC";
    prod[4].left = "C";
    prod[4].right = "*FC";
    prod[5].left = "C";
    prod[5].right = "#";
    prod[6].left = "F";
    prod[6].right = "(E)";
    prod[7].left = "F";
    prod[7].right = "i";
    cout<<"The given productions are:"<<endl;
    for(int i = 0; i < n; i++){
        cout<<prod[i].left<<" -> "<<prod[i].right<<endl;
    }
    int j = 0;
    for(int i = 0; i < n; i++){
        if(!exists(nterm, prod[i].left, n)){
            nterm[j].value = prod[i].left;
            j++;
        }
    }
    while(j < n){
        nterm[j].value = "\0";
        j++;
    }
    for(int i = 0; nterm[i].value != "\0"; i++){
        nterm[i].first[0] = '\0';
    }
    for(int i = 0 ; i < n; i++){
        prod[i].right.append("\0");
    }
    
    first(nterm, prod, n);

    calcFollow(nterm, prod, n);
    
    nterm[1].follow = nterm[0].follow;
    nterm[2].follow = "$)+";
    int countTerm = 0;
    bool cont = false;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < prod[i].right.length(); k++){
            if(getString(prod[i].right[k]) == "#"){
                continue;
            }
            if(isterm(getString(prod[i].right[k]), nterm)){
                if(!termExists(getString(prod[i].right[k]), terminals)){
                    terminals[countTerm] = getString(prod[i].right[k]);
                    countTerm++; 
                }
            }
        }
        terminals[countTerm] = "$";
        terminals[countTerm+1] = "\0";
    }
    nterm[3].follow = nterm[2].follow;
    nterm[4].follow = "$)+*";
    for(int i = 0 ; nterm[i].value != "\0"; i++){
        nonterminals[i] = nterm[i].value;
    }

    constructParsingTable(nterm, prod, n);

    cout<<endl<<"Value\tFirst\t\tFollow"<<endl;
    for(int i = 0; i < n; i++){
        if(nterm[i].value == "\0"){
            break;
        }
        cout<<nterm[i].value<<"\t{ ";
        for(int k = 0; nterm[i].first[k] != '\0'; k++){
            cout<<nterm[i].first[k]<<", ";
        }
        cout<<"}\t{ ";
        for(int k = 0; nterm[i].follow[k] != '\0'; k++){
            cout<<nterm[i].follow[k]<<", ";
        }
        cout<<"}\n";
    }
    cout<<endl;
    cout<<"Nterms\t";
    for(int i = 0 ; terminals[i] != "\0"; i++){
        cout<<terminals[i]<<"\t";
    }
    cout<<endl;
    for(int i = 0; i < 5 ; i++){
        cout<<nonterminals[i]<<"\t";
        for(int k = 0 ; k < 10 ; k++){
            cout<<ptable[i][k]<<"\t";
        }
        cout<<endl;
    }
    inpString.append("$");
    cout<<"The input string is "<<inpString<<endl;
    stack.append("$");
    stack.append(prod[0].left);

    if(interpretString(inpString, stack, nterm)){
        cout<<"The string is accepted by the grammar.";
    }
    else{
        cout<<"The string is not accepted by the grammar.";
    }
}
 
