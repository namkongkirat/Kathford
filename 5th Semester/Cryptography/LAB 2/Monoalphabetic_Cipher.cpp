#include<stdio.h>
#include<strings.h>
char *encryption(char []);
void *decryption(char []);
char alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char key[26];
int main()
{
	int i,choice,flag=0;
	char *c_text,msg[100];
	printf("Enter plain text :");
	scanf("%s",&msg);
	printf("\nYour plain text message is : %s",msg);
	do{
		printf("\n1. Encryption\n2. Decryption \n0. for Exit \n");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				c_text=encryption(msg);
				flag=1;
			break;
			case 2 :
				if(flag==1)
				decryption(c_text);
				else
				printf("First perform encryption process");
			break;
			case 0 :
			break;
			default :
				printf("\nPlease enter valid choice\n");
			break;
		}
	}while(choice!=0);
}
char *encryption(char cipher_text[]){
	int i,j;
	printf("Enter the unique 26 characters key :");
	scanf("%s",key);
	for(i=0;i<strlen(cipher_text);i++){
		for(j=0;j<26;j++)
		{
			if(alpha[j]==cipher_text[i]){
				cipher_text[i]=key[j];
				break;
			}
		}
	}
	printf("\nCipher text: %s",cipher_text);
	return cipher_text;
}
void *decryption(char cipher_text[]){
	int i,j;
	char cipher[100];
	strcpy(cipher,cipher_text);
	for(i=0;i<strlen(cipher);i++){
		for(j=0;j<26;j++)
		{
			if(cipher[i]==key[j])
			{
				cipher[i]=alpha[j];
				break;
			}
		}
	}
	printf("\nDecrypted Text: %s",cipher);
}
