#include <stdio.h>

int firstKeyGeneration(int k[10]){
    int i,  P10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6}, P10k[10], P8[8] = {6, 3, 7, 4, 8, 5, 10, 9}, P8k1[8], LS1[10], LS2[10];

    for (i = 0; i <= 9; i++)
	{
		P10k[i] = K[P10[i] - 1]; //1st key 10bits
	}

	int LS11 = K[0], LS12 = K[5];
	for (i = 0; i <= 9; i++)
	{
		LS1[i] = P10k[i + 1]; //Left Shift 1 bit
		if (i == 4)
			LS1[i] = LS11;
		else if (i == 9)
			LS1[i] = LS12;
	}

	for (i = 0; i <= 7; i++)
	{
		P8k1[i] = LS1[P8[i] - 1]; //1st key permuted 8 bits
	}
    return P8k1[8];
}

int secondKeyGeneration(int K[10]){
    int i,  P10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6}, P10k[10], P8[8] = {6, 3, 7, 4, 8, 5, 10, 9}, P8k1[8], P8k2[8], LS1[10], LS2[10];

    for (i = 0; i <= 9; i++)
	{
		P10k[i] = K[P10[i] - 1]; //1st key 10bits
	}

	int LS11 = K[0], LS12 = K[5];
	for (i = 0; i <= 9; i++)
	{
		LS1[i] = P10k[i + 1]; //Left Shift 1 bit
		if (i == 4)
			LS1[i] = LS11;
		else if (i == 9)
			LS1[i] = LS12;
	}
    
	LS11 = LS1[0], LS12 = LS1[5];
	for (i = 0; i <= 4; i++)
	{
		LS2[i] = LS1[(i + 2) % 5]; //left shift 2 bits first 5 bits
		if (i == 4)
			LS2[i] = LS11;
	}
	for (i = 6; i < 10; i++)
	{
		LS2[i] = LS1[((i + 2) % 5) + 5]; //left shift 2 bits second 5 bits
		if (i == 9)
			LS2[i] = LS12;
	}
	for (i = 0; i < 8; i++)
	{
		P8k2[i] = LS2[P8[i] - 1];  //2nd key permuted to 8 bits
	}
    return P8k2[8];
	
}

int main()
{
	int i, K[10],k1[8],k2[8];

	printf("Enter key (10 bit):\n");
	for (i = 0; i < 10; i++)
	{
		printf("K[%d]:", i + 1);
		scanf("%d", &K[i]);
	}
	k1[8]=firstKeyGeneration(K);
    k2[8]=secondKeyGeneration(K);

    printf("First key is : ");
	for (i = 0; i < 8; i++)
	{
		printf("%d ", k1[i]);
	}
	printf("\nSecond key is : ");
	for (i = 0; i < 8; i++)
	{
		printf("%d ", k2[i]);
	}
}
