#include<iostream>
#include<queue>
using namespace std;
struct compare{
	bool operator()(int o1,int o2){
		int first_abs = abs(o1);
		int second_abs = abs(o2);
		if(first_abs == second_abs)
			return o1 > o2;    //절댓값이 같을 때는 음수 우선 정렬 
		else
			return first_abs > second_abs; // 절댓값을 기준으로 정렬 
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	//우선순위 큐 선언 방식:<자료형,구현체,비교 함수명>
	priority_queue<int,vector<int>,compare> my_queue;
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i){
		int request;
		cin >> request;
		
		if(request == 0){
			if(my_queue.empty()) cout << "0" << "\n";
			else {
				cout << my_queue.top() << "\n";	
				my_queue.pop();
			} 
		}
		else my_queue.push(request);
	} 
	return 0;
}
