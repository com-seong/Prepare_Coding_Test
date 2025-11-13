#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin >> N;
	vector<pair<int,int>> A(N);
	for(int i = 0; i < N; i++){
		cin >> A[i].second;
		cin >> A[i].first;
	}
	int cnt = 0;
	int end = -1;
	sort(A.begin(),A.end());
	
	for(int i = 0; i < N; i++){
		if(A[i].second >= end){
			end = A[i].first;
			cnt++;
		} 
	}
	cout << cnt;
	return 0;
}
