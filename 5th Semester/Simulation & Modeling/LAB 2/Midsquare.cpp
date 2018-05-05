#include<stdio.h>

int main(){
	int m, n;
	printf("Enter the initial value:");
	scanf("%d", &n);
	printf("\nThe ramdom numbers are:\n");
	while(1){
		n=n*n;
		n=n%1000;
		n=n/10;
		m++;
		if(m>100 || n<=0){
			break;
		}
		printf("%d\t", n);
	}
}
