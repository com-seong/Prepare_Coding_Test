#include<iostream>


//구간 합 배열 공식 s[i] = s[i-1]  + a[i]
//구간 합 구하는 공식 s[j] - s[i-1] 
 
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	int s[n+1];
	for(int i = 1; i <= n; ++i){
		int val;
		cin >> val;
		s[i] = s[i-1] + val;
	}
	for(int i = 0; i < m; ++i){
		int start,end;
		cin >> start >> end;
		cout << s[end] - s[start - 1] << "\n";
	}
	return 0;
}
