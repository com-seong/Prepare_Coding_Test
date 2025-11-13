#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	cin >> N;
	
	vector<int> A(N,0);
	vector<int> result(N,0);
	
	for(int i = 0; i < N; ++i)
		cin >> A[i];
	
	stack<int> my_stack;
	my_stack.push(0);
	
	for(int i = 1; i < N; ++i){
		while(!my_stack.empty() && A[my_stack.top()] < A[i]){
			result[my_stack.top()] = A[i];
			my_stack.pop();
		}
		my_stack.push(i);
	}
	while(!my_stack.empty()){
		result[my_stack.top()] = -1;
		my_stack.pop();
	}
	for(int i = 0; i < N; ++i)
	   	cout << result[i] << " ";
	
	return 0;
}
