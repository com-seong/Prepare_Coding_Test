#include<stdio.h>

int main(void)
{	
	long long n,want;
	int i;
	scanf("%lld %lld",&n,&want);
	long long arr[n];
	long long max = 0;
	for(i = 0; i < n; i++)
	{
		long long treelong;
		scanf("%lld",&treelong);
		arr[i] = treelong;
		if(treelong > max)
		{
			max = treelong;
		}
	}
	long long min = 0;
	long long result = 0;
	while(min <= max)
	{	
		long long mid = min + (max - min) / 2; // 오버플로우 방지 기법 
		long long length = 0;
		for(i = 0; i < n; i++)
		{	
			if(arr[i] > mid)
			{
				length += arr[i] - mid;
			}
		}
		if(length >= want)
		{
			result = mid;
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
	}
	printf("%lld",result);
	return 0;
}
