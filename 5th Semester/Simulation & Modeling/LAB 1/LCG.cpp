#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main(){
	int X[100], c, a, m, ch, n;
	float R[100];
	printf("Number of random numbers to generate:");
	scanf("%d",&n);
	printf("Enter value for Xo:");
	scanf("%d",&X[0]);
	printf("Enter value for a:");
	scanf("%d",&a);
	printf("Enter value for c:");
	scanf("%d",&c);
	printf("Enter value for m:");
	scanf("%d",&m);
	printf("\n1.Additive\n");
	printf("2.Multiplicative\n");
	printf("3.Mixed\n");
	printf("Select an option:");
	scanf("%d",&ch);
	printf("\nThe random integers are:\n");
	switch(ch){
		case 1:
			a=1;
			for(int i=1; i<=n; i++){
				X[i]=(X[i-1]+c)%m;
				R[i]=(float)X[i]/m;
				printf("%d\t",X[i]);
			}
			break;
		case 2:
			c=0;
			for(int i=1; i<=n; i++){
				X[i]=(a*X[i-1])%m;
				R[i]=(float)X[i]/m;
				printf("%d\t",X[i]);
			}
			break;
		case 3:
			for(int i=1; i<=n; i++){
				X[i]=(a*X[i-1]+c)%m;
				R[i]=(float)X[i]/m;
				printf("%d\t",X[i]);
			}
			break;
		default:
			printf("Choose the right option.");
			exit(0);
	}
	printf("\n\nThe random numbers are:\n");
	for(int i=1; i<=n; i++){
		printf("%.2f\t", R[i]);
	}
}
