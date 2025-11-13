#include<stdio.h>

int main(void)
{	
	int i,j,n,k;
	scanf("%d %d",&n,&k);
	int arr[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	int sum = 0;
	for(i = 0; i < k; i++)
	{
		sum += arr[i];
	}
	int max = sum;
	for(i = k; i < n; i++)
	{
		sum = sum - arr[i - k] + arr[i]; // 원래 더해놓은 값에다가 가장 왼쪽 값을 빼고, 가장 최신값을 더하는 방식 
		if(sum > max)
		{
			max = sum;
		}
	}
	printf("%d",max);
	return 0;
}
