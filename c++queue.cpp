#include<iostream>
#include<queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	queue<int> my_queue;
	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i)
	 my_queue.push(i);
	 
	while(my_queue.size() > 1){
		my_queue.pop();
		my_queue.push(my_queue.front());
		my_queue.pop();
	}
	cout << my_queue.front();
	return 0;
}
