#include<stdio.h>

int main(void)
{	
	int a,b,c;
	int insert_h , insert_m;
	scanf("%d %d",&a,&b);
	scanf("%d",&c);
	if(a < 0 || a > 23 || b < 0 || b > 59 || c < 0 || c > 1000)
	{
		return 0;
	}
	
		a += (b + c) / 60;
		b = (b + c) % 60;
		a %= 24;
	
	
	printf("%d %d",a,b);
	
	return 0;	
} 
