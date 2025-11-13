#include<iostream>
#include<cstdio>
#define MAX 9
using namespace std;
int arr[MAX];
int visited[MAX];
int n,m;
void dfs(int depth)
{	
	int i;
	if(depth == m){
		for(i=0; i < m; ++i)
			printf("%d ",arr[i]);
		printf("\n");
		return;
	}
	for(i=1; i <= n; ++i){
		if(!visited[i]){
			visited[i] = 1;
			arr[depth] = i;
			dfs(depth+1);
			visited[i] = 0;
		}
	}
}
int main(int argc,char *argv[])
{	
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	scanf("%d %d",&n,&m);
	dfs(0);
	return 0;
}
