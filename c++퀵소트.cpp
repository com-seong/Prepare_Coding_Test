#include<iostream>
#include<vector>
#define SWAP(a,b,t) ((t)=(a), (a)=(b), (b)=(t))
using namespace std; 
void quick_sort(vector<int> &A,int S,int E,int K);
int partition(vector<int> &A,int S,int E);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N,K;
	cin >> N >> K;
	
	vector<int> A(N,0);
	for(int i = 0; i < N; ++i)
		cin >> A[i];
	quick_sort(A,0,N-1,K-1);
	cout << A[K-1];
	return 0;
}
void quick_sort(vector<int> &A,int S,int E,int K)
{
	int pivot = partition(A,S,E);
	if(pivot == K) return;
	else if(K < pivot) quick_sort(A,S,pivot-1,K);
	else quick_sort(A,pivot+1,E,K);
}
int partition(vector<int> &A,int S,int E)
{
	int temp = 0;
	if(S+1 == E){
		if(A[S] > A[E]) SWAP(A[S],A[E],temp);
		return E;
	}
	int middle = (S + E) / 2;
	SWAP(A[S],A[middle],temp);
	int pivot = A[S];
	int i = S+1,j = E;
	while(i <= j){
		while(j >= S+1 && pivot < A[j]) j--;
		while(i <= E && pivot > A[i]) i++;
		if(i < j){
			SWAP(A[i],A[j],temp);
			i++;
			j--;
		} 
		else break;
	}
	A[S] = A[j];
	A[j] = pivot;
	return j;
}
