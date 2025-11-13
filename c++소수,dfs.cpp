#include<iostream>
using namespace std;
static int N;
bool isPrime(int num)
{
	for(int i = 2; i <= num / 2; ++i)
		if(num % i == 0)
			return false;
		
	return true;
}
void dfs(int num,int jarisu)
{
	if(jarisu == N){
		if(isPrime(num))
			cout << num << "\n";
		return;
	}
	for(int i = 1; i < 10; ++i){
		if(i % 2 == 0)
			continue;
		if(isPrime(num*10 + i))
			dfs(num*10+i,jarisu+1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N;
	dfs(2,1);
	dfs(3,1);
	dfs(5,1);
	dfs(7,1);
	
	return 0;
}
