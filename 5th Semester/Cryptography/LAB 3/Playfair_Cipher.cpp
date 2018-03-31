
#include <stdio.h>
#include <string.h>

int isPresent(char ch, char km[][5]){
	int r,c;
	for(r=0; r<5; r++){
		for(c=0;c<5;c++){
			if(ch==km[r][c])
			return(1);
		}
	}
	return(0);
}

void printKeyMatrix(char km[][5]){
	int r,c;
	for(r=0;r<5;r++){
		for(c=0;c<5;c++){
			if(km[r][c]=='\0')
			printf("0 \t");
			else
			printf("%c \t", km[r][c]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void insert(char ch, char km[][5]){
	int r,c;
	for(r=0;r<5;r++){
		for(c=0;c<5;c++){
			if(km[r][c]=='\0'){
			km[r][c]=ch;
			return;
			}
			
		}
	}
}

void createKeyMatrix(char km[][5], char kw[]){
	int i;
	char ch;
	for(i=0;i<strlen(kw);i++){
		if(!isPresent(kw[i],km))
		insert(kw[i],km);
	}
	printKeyMatrix(km);
	for(ch='A';ch<='Z';ch++){
		if(!isPresent(ch,km)){
			insert(ch,km);			
		}
		if(ch=='I')
		ch++;
	}
	
}

int main(){
	int r,c;
	char p[]="balxloon";
	char kw[]="KATHMANDU";
	char km[5][5]={'\0','\0','\0','\0','\0',
					'\0','\0','\0','\0','\0',
					'\0','\0','\0','\0','\0',
					'\0','\0','\0','\0','\0',
					'\0','\0','\0','\0','\0'};
	printKeyMatrix(km);
	createKeyMatrix(km,kw);
	printKeyMatrix(km);
}


