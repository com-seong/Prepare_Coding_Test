#include<iostream>
#include<queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N,data;
	cin >> N;
	//insert data in priority_queue
	//if data is plus maxheap
	priority_queue<int> plusheap;
	//if data is minus minheap
	priority_queue<int,vector<int>,greater<int>> minusheap;
	//if data is one
	int one = 0;
	//if data is zero
	int zero = 0;
	for(int i = 0; i < N; ++i){
		cin >> data;
		//if plus
		if(data > 1)
			plusheap.push(data);
		else if(data == 1)
			one++;
		else if(data == 0)
			zero++;
		else minusheap.push(data);
	}
	int sum = 0;
	//plus 
	while(plusheap.size() > 1){
		int first = plusheap.top();
		plusheap.pop();
		int second = plusheap.top();
		plusheap.pop();
		
		sum += first*second;
	}
	if(!plusheap.empty()){
		sum += plusheap.top();
		plusheap.pop();
	}
	//minus
	while(minusheap.size() > 1){
		int first = minusheap.top();
		minusheap.pop();
		int second = minusheap.top();
		minusheap.pop();
		
		sum += first*second;
	}
	if(!minusheap.empty()){
		//if there is no zero in minusheap
		if(zero == 0){
			sum += minusheap.top();
			minusheap.pop();
		}
		//if zero sum += 0
	}
	//one
	sum += one;
	cout << sum << "\n";
	return 0;
}
