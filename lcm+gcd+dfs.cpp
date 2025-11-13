#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
vector<tuple<int,int,int>> A[10];
long long lcm;
int visited[10];
long long D[10];
long long gcd(long long a,long long b){
	while(b){
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}
void dfs(int node){
	visited[node] = 1;
	
	for(tuple<int,int,int> i : A[node]){
		int next = get<0>(i);
		if(!visited[next]){
			D[next] = D[node] * get<2>(i) / get<1>(i);
			dfs(next);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	lcm = 1;
	for(int i = 0; i < N - 1; i++){
		int a,b,p,q;
		cin >> a >> b >> p >> q;
		A[a].push_back(make_tuple(b,p,q));
		A[b].push_back(make_tuple(a,q,p));
		lcm *= (p*q/gcd(p,q));
	}
	D[0] = lcm;
	dfs(0);
	long long  mgcd = D[0];
	for(int i = 1; i < N; i++){
		mgcd = gcd(mgcd,D[i]);
	}
	for(int i = 0; i < N; i++){
		cout << D[i] / mgcd << ' ';
	}
	return 0;
}
