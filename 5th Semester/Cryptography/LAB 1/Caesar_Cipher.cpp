#include<stdio.h>
#include<string.h>
#include<conio.h>

void Caesar_Encrypt(char pt[], int key, char ct[])
{
     char temp;
     int i;
     for(i=0;i<strlen(pt);i++)
     {
          temp=pt[i];
          temp-=97;
          temp+=key;
          temp%=26;
          temp+=65;
          ct[i]=temp;
     }
     ct[i]='\0';
}

void Caesar_Decrypt(char ct[], int key, char pt[])
{
     char temp;
     int i;
     for(i=0;i<strlen(ct);i++)
     {
          temp=ct[i];
          temp-=65;
          temp-=key;
          if(temp<0){
          	temp+=26;
          	temp+=97;
          	pt[i]=temp;}
     }
     pt[i]='\0';
}

int  main()
{
     char plaintext[]="namkong";
     char key=15;
     char ciphertext[50];
     
     Caesar_Encrypt(plaintext, key, ciphertext);
     printf("Ciphertext=%s\n", ciphertext);
     
     Caesar_Decrypt(ciphertext, key, plaintext);
     printf("Plaintext=%s", plaintext);
     
     getch();
     return 0;
}

