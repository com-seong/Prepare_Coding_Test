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
	vector<char> resultV;
	
	for(int i = 0; i < N; ++i){
		cin >> A[i];
	}
	stack<int> myStack;
	int num = 1;
	bool result = true;
	for(int i = 0; i < A.size(); ++i){
		int su = A[i];
		if(su >= num){
			while(su >= num){
				myStack.push(num++);
				resultV.push_back('+');
			}
			myStack.pop();
			resultV.push_back('-');
		}
		else{
			int n = myStack.top();
			myStack.pop();
			if(n > su){
				cout << "NO";
				result = false;
				break;
			}
			else{
				resultV.push_back('-');
			}
		}
	}
	if(result){
			for(int i = 0; i < resultV.size(); ++i){
				cout << resultV[i] << "\n";
			}
		}
	return 0;
}
