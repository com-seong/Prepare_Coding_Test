#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

//구현법 익혀두기.. 
vector<string> split(string input,char del){
	vector<string> result;
	stringstream mstream(input);
	string splitdata;
	while(getline(mstream,splitdata,del))
		result.push_back(splitdata);
	return result;
}
int Sum(string a){
	int sum = 0;
	vector<string> temp = split(a,'+');
	for(int i = 0; i < temp.size(); i++) sum += stoi(temp[i]);
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int ans = 0;
	string exp;
	cin >> exp;
	vector<string> str = split(exp,'-');
	for(int i = 0; i < str.size(); i++){
		int temp = Sum(str[i]);
		if(i == 0) ans += temp;
		else ans -= temp;
	}
	cout << ans << "\n";
	return 0;
}
