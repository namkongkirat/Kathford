#include <stdio.h>

int main(){
	float RN[20], a, b, c, d, dp = 0, dm = 0, dd = 0, temp;
	int n, i, j;
	printf("Enter the number of random number to input:");
	scanf("%d", &n);
	printf("\nEnter the random numbers:\n");
	for(i = 0; i < n; i++){
		printf("%d: ", i+1);
		scanf("%f", &RN[i]);
	}
	
	printf("\nIn Ascending order:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if (RN[j] > RN[i])                
			{
				temp = RN[i];        
				RN[i] = RN[j];           
				RN[j] = temp;      
			}  
		}
	}
	for (i = 0; i < n; i++)         
	{
		printf(" %.2f   ", RN[i]);
	}
	printf("\n\nR[i]\ti/N\t(i-1)/N\t(i/N)-R[i]\tR[i]-((i-1)/N)\n");
	for (i = 0; i < n; i++)         
	{
		printf("%.2f\t", RN[i]);
		a = (float)(i-1) / n;
		printf("%.2f\t", a);
		b = (float) i / n;
		printf("%.2f\t", b);
		c = (float) b - RN[i];
		printf("%.2f\t\t", c);
		if(dp < c)
			dp = c;
		d = (float) RN[i] - a;
		printf("%.2f\n", d);
		if(dm < d)
			dm = c;
		if(dm<dp)
			dd = dp;	
	}
	printf("\n\nD+ = %.2f\nD- = %.2f\nD = %.2f",dp, dm, dd);
	
	if(dd<0.565){
		printf("\nSince D calculated is smaller than D tabulated, The generated random number are uniform.");
	}
	else{
		printf("\nSince D calculated is greater than D tabulated, The generated random number are not uniform.");
	}
	
}
