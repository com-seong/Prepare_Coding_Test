#include<iostream>
#include<vector>
using namespace std;

static vector<int> A;
static vector<int> sorted;

void merge(int first,int mid, int end);
void merge_sort(int first,int end);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	A = vector<int>(N,0);
	sorted = vector<int>(N,0);
	
	for(int i = 0; i < N; ++i)
		cin >> A[i];
	merge_sort(0,N-1);
	for(int i = 0; i < N; ++i)
		cout << A[i] << "\n";
}
void merge_sort(int first,int end)
{
	int mid;
	if(first < end){
		mid = (first + end) / 2;
		merge_sort(first,mid);
		merge_sort(mid+1,end);
		merge(first,mid,end);
	}
}
void merge(int first,int mid,int end)
{
	int i,j,k;
	i = first; j = mid+1; k = first;
	while(i <= mid && j <= end){
		if(A[i] <= A[j]) sorted[k++] = A[i++];
		else sorted[k++] = A[j++];
	}
	if(i > mid)
		for(int l = j; l <= end; ++l)
			sorted[k++] = A[l];
	else 
		for(int l = i; l <= mid; ++l)
			sorted[k++] = A[l];
	for(int l = first; l <= end; ++l)
		A[l] = sorted[l];
}
