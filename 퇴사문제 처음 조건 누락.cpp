#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N,max = 0;
	cin >> N;
	vector<pair<int,int>> tp(N+1);
	for(int i = 1; i <= N; i++)
		cin >> tp[i].first >> tp[i].second;
		
	for(int i = 1; i <= N; i++){
		int sum = 0;
		for(int j = i; j <= N; j = j + tp[j].first){ //이러면 건너뛰고 이득이 될 수 있는 경우 고려 못함 
			if((j + (tp[j].first - 1)) > N) break;
			sum += tp[j].second;	
		}
		if(max < sum) max = sum;
	}
	cout << max;
	return 0;
}
