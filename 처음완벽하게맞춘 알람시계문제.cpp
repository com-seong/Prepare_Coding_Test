#include<stdio.h>

int main(void)
{	
	int h,m,t;
	int result_m = 0;
	scanf("%d %d",&h,&m);
	if(h < 0 || h > 23 || m < 0 || m > 59)
	{
		return 0;
	}
	if(m < 45)
	{	
		h = h - 1;
		if(h < 0)
		{
			h = h + 24;
		}
		t = 45 - m;
		result_m = 60 - t;
	}
	else
	{
		result_m = m - 45;
	}
	
	printf("%d %d",h,result_m);
	return 0;
}
