#include<iostream>
#include<cmath>
#include<string>

using namespace std;
bool isPalindrome(string val) {
	int s = 0; int e = val.size() - 1;
	while (s <= e) {
		if (val[s] != val[e]) {
			return false;
		}
		else s++; e--;
	}
	return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long n;
    cin >> n;
    long a[10000001];
    for (int i = 2; i < 10000001; i++)
        a[i] = i;
    for (int i = 2; i <= sqrt(10000001); i++) {
        if (a[i] == 0) continue;
        for (int j = i + i; j < 10000001; j += i) {
            a[j] = 0;
        }
    }
    int i = n;
    while(1){
    	if(a[i] != 0){
    		int result = a[i];
    		if(isPalindrome(to_string(result))){
    			cout << result << "\n";
    			break;
			}
		}
		i++;
	}
    return 0;
}
