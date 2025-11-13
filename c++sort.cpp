#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	cin >> N;
	vector<pair<int,int>> A(N);
	for(int i = 0; i < N; ++i){
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(),A.end()); //배열 A정렬 시간 복잡도 O(nlogn)
	int max = 0;
	for(int i = 0; i < N; ++i){
		//정렬전 index - 정렬 후 index를 계산한 값 중 최댓값을 찾아 저장
		if(max < A[i].second - i)
			max = A[i].second - i; 
	} 
	cout << max + 1;
	return 0;
}
