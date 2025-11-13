#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//(a + b) % c = ((a % c) + (b % c)) % c 모듈러 합동 성질
	//따라서 s[j] % m = s[i] % m 이면 (s[j] - s[i]) % m = 0   
	//s[j]-s[i] = s[i+1,j]
	//같은 나머지를 가진 누적합 2개 사이의의 구간합은 m으로 나누어 떨어진다. 
	int N,M;
	cin >> N >> M;
	vector<long> S(N,0);
	vector<long> C(M,0);
	long answer = 0;
	cin >> S[0];
	for(int i = 1; i < N; ++i){
		int temp = 0;
		cin >> temp;
		S[i] = S[i-1] + temp;
	}
	for(int i = 0; i < N; ++i){
		int remain = S[i] % M;
		if(remain == 0)
			answer++;
		
		C[remain]++;
	}
	for(int i = 0; i < M; ++i){
		if(C[i] > 1)
			//c[i]개 중에 2개를 뽑는 경우의 수의 계산 공식 nC2 
			answer = answer + (C[i]*(C[i]-1)/2);
		
	}
	cout << answer << "\n";
	return 0;
} 
