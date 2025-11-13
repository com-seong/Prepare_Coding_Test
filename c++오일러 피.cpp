#include<iostream>
#include<cmath>
using namespace std;
//정해진 범위 내에서 서로소의 개수를 구할 때 사용 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin >> n;
	long long result = n;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){ //소인수라면  
			result = result - result / i; //결과값 업데이트 
			while(n % i == 0) //소인수 지우기 
			 	n /= i;
		}
	}
	if(n > 1){ //제곱근까지만 반복했기 때문에 1개의 소인수 누락경우 
		result = result - result / n;
	}
	cout << result;
	return 0;
} 
