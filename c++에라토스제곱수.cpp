#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll min, max;
	cin >> min >> max;
	vector<int> check((max - min) + 1);
	for (ll i = 2; i * i <= max; i++) {
		ll pow = i * i;
		ll start = min / pow;
		if (min % pow != 0) start++;
		for (ll j = start; j * pow <= max; j++)
			check[(j * pow) - min] = 1;
	}
	int cnt = 0;
	for (int i = 0; i <= max-min; i++)
		if (!check[i]) cnt++;
	cout << cnt;
	return 0;
}
