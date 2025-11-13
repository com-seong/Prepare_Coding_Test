#include<iostream>
#include<queue>
using namespace std;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq; //greater->오름차순, less-> 내림차순 
	int data;
	for(int i = 0; i < N; ++i){
		cin >> data;
		pq.push(data);
	}
	int data1 = 0;
	int data2 = 0;
	int sum = 0;
	while(pq.size() != 1){
		data1 = pq.top();
		pq.pop();
		data2 = pq.top();
		pq.pop();
		sum += data1 + data2;
		pq.push(data1 + data2);
	}	
	cout << sum << "\n"; 
	return 0;
} 
