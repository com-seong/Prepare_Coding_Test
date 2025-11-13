#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	//»ğÀÔ Á¤·Ä version1 
	for(int i = 1; i < N; ++i){
		int key = A[i];
		for(int j = i - 1; j >= 0; && A[j] > key; --j)
			A[j+1] = A[j];
		A[j+1] = key;
	}
	
	//»ğÀÔ Á¤·Ä version2 
	for(int i = 1; i < N; ++i){
		int insert_point = i;
		int insert_value = A[i];
		for(int j = i - 1; j >= 0; --j){
			if(A[j] < A[i]){
				insert_point = j+1;
				break;
			}
			if(j == 0)
				insert_point = 0;
		}
		for(int j = i; j > insert_point; --j)
			A[j] = A[j-1];
		A[insert_point] = insert_value;
	}
	
	return 0;
}
