#include<stdio.h>

int main(void)
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	if(n <= 1)
	{
		printf("%d",n);
		return 0;	
	}
	int not_dec = 1;
	int not_inc = 1;
	int max = 1;
	for(i = 1; i < n; i++)
	{
		if(arr[i - 1] <= arr[i])
		{
			not_dec++;
		}
		else
		{
			not_dec = 1;
		}
		if(arr[i - 1] >= arr[i])
		{
			not_inc++;
		}
		else
		{
			not_inc = 1;
		}
		if(max < not_inc)
		{
			max = not_inc;
		}
		if(max < not_dec)
		{
			max = not_dec;
		}
	}
	printf("%d",max);
	return 0;
}
