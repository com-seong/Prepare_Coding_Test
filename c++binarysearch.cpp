#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>  A;
bool binarysearch(int num,int end)
{
	int start = 0;
	while(start <= end){
		int mid = (start+end)/2;
		if(A[mid] == num) return true;
		else if(num > A[mid]) start = mid+1;
		else if(num < A[mid]) end = mid-1;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N,M;
	cin >> N;
	A.resize(N);
	for(int i = 0; i < N; ++i)
		cin >> A[i];
	cin >> M;
	sort(A.begin(),A.end());
	for(int i = 0; i < M; ++i){
		int num;
		cin >> num;
		if(binarysearch(num,N-1)) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	
	return 0;
}
