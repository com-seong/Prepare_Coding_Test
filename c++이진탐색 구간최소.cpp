#include<iostream>
#include<vector>
using namespace std;
static vector<int> A;
int max_val(int n)
{
	int max = 0;
	for(int i = 0; i < n; ++i){
		if(A[i] > max){
			max = A[i];
		}
	}
	return max;
}
int sum_val(int n)
{
	int sum = 0;
	for(int i = 0; i < n; ++i)
		sum += A[i];
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N,M;
	cin >> N >> M;
	A.resize(N,0);
	for(int i = 0; i < N; ++i)
		cin >> A[i];
	int start = max_val(N);
	int end = sum_val(N);
	int ans = 0;
	while(start <= end) { //최소 찾을때까지 
		int mid = (start + end)/2; //범위를 나누는 기준은 mid
		int total = 0;
		int count = 1;
		for(auto i : A){
			if(total + i > mid){ //가능한 최소 
				count += 1;  //mid를 기준으로 구간을 나누고
				total = 0; //나눴다는걸 표시하기 위해 0으로 초기화
			}
			total += i;
		}
		if(count <= M){ //개수 맞추기 
			ans = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}
	cout << ans;
	return 0;
}
