#include<iostream>
#include<deque>
using namespace std;
typedef pair <int,int> Node;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N,L;
	cin >> N >> L;
	deque<Node> mydeque;
	for(int i = 0; i < N; ++i){
		int now;
		cin >> now;             //덱의 마지막 원소의 첫번째 값 = value
		while(mydeque.size() && mydeque.back().first > now){
			mydeque.pop_back();
		}
		mydeque.push_back(Node(now,i));
		if(mydeque.front().second <= i - L){  //덱의 첫번째 원소의 두번째 값 = index 
			mydeque.pop_front();
		}
		cout << mydeque.front().first << " ";
	}
	
	return 0;
}
