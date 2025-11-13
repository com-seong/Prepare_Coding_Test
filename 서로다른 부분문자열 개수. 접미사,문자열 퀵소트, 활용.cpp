#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 1000001
char *lcp[MAXLEN];
int compare(const void *a,const void *b)
{
	return strcmp(*(char**)a, *(char**)b); 
}
int main(void)
{	
	char str[MAXLEN];
	scanf("%s",str);
	int i,sum = 0;
	int len = strlen(str);
	for(i = 0; i < len; i++){
		lcp[i] = &str[i];
	}
	qsort(lcp,len,sizeof(char *),compare);
	for(i = 0; i < len - 1; i++){
		int j = 0;
		while(lcp[i][j] && lcp[i + 1][j] && lcp[i][j] == lcp[i + 1][j]){
			j++;
		}
		int length = strlen(lcp[i]);
		sum += length - j;
	}
	sum += strlen(lcp[len - 1]);
	printf("%d",sum);
	return 0;
}

