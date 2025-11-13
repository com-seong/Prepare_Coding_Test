#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct People
{
	char name[21];
}People;
int compare(const void* a, const void* b)
{
	return strcmp(((People *)a)->name, ((People *)b)->name);
}
int compare_string(const void* a, const void* b)
{
	return strcmp(*(char **)a, *(char **)b);
}
int main(void)
{	
	int n,m,i,j;
	int count = 0;
	scanf("%d %d",&n,&m);
	People arr[n];
	char* result[m];
	for(i = 0; i < n; i++)
	{
		scanf("%s",arr[i].name);
	}
	qsort(arr,n,sizeof(People),compare);
	for(i = 0; i < m; i++)
	{
		char notseen[21];
		scanf("%s",notseen);
		if(bsearch(&notseen,arr,n,sizeof(People),compare))
		{
			result[count] = strdup(notseen);
			count++;
		}
	}
	qsort(result,count,sizeof(char *),compare_string);
	printf("%d\n",count);
	for(i = 0; i < count; i++)
	{
		printf("%s\n",result[i]);
		free(result[i]);
	}
	return 0;
}
