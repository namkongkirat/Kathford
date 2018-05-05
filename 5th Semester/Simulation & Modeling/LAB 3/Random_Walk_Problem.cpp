#include<stdio.h>
#include<stdlib.h>
#include<ctime>
int main()
{
	int i,rn;
	int x=0,y=0,x1,y1;
	printf("Step\tCurrent Position\tRandom number\tMovement\tNew position\n");
	for(i=0;i<20;i++)
	{
		rn=(srand()%100)+1;
	
	if(rn>=0&& rn<=39){
		y1=y+1;
		printf("%d\t(%d,%d)\t\t\t%d\t\tForward\t\t(%d,%d)\n",i+1,x,y,rn,x,y1);
		y=y1;
	}
	else if(rn>=40 && rn<=69)
	{
		y1=y-1;
		printf("%d\t(%d,%d)\t\t\t%d\t\tBackward\t(%d,%d)\n",i+1,x,y,rn,x,y1);
		y=y1;
	}
	else if(rn>=70 && rn<=84)
	{
		x1=x-1;
		printf("%d\t(%d,%d)\t\t\t%d\t\tLeft\t\t(%d,%d)\n",i+1,x,y,rn,x1,y);
		x=x1;
	}
	else
	{
		x1=x+1;
		printf("%d\t(%d,%d)\t\t\t%d\t\tRight\t\t(%d,%d)\n",i+1,x,y,rn,x1,y);
		x=x1;
	}
}
printf("\nFinal position = (%d,%d)", x,y);
return 0;
}

