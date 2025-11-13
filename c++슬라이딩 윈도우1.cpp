#include<iostream>

using namespace std;
int myarr[4];
int checkarr[4];
int check;
void Add(char c)
{
	switch(c){
		case 'A':
			myarr[0]++;
			if(myarr[0] == checkarr[0])
				check++;
			break;
		case 'C':
			myarr[1]++;
			if(myarr[1] == checkarr[1])
			 	check++;
			break;
		case 'G':
			myarr[2]++;
			if(myarr[2] == checkarr[2])
			 	check++;
			break;
		case 'T':
			myarr[3]++;
			if(myarr[3] == checkarr[3])
			 	check++;
			break;
	}
}
void Remove(char c)
{
	switch(c){
		case 'A':
			if(myarr[0] == checkarr[0])
				check--;
			myarr[0]--;
			break;
		case 'C':
			if(myarr[1] == checkarr[1])
			 	check--;
			myarr[1]--;
			break;
		case 'G':
			if(myarr[2] == checkarr[2])
			 	check--;
			myarr[2]--;
			break;
		case 'T':
			if(myarr[3] == checkarr[3])
			 	check--;
			myarr[3]--;
			break;
	}
}
int main()
{
	int S,P,result = 0;
	cin >> S >> P;
	string A;
	cin >> A;
	for(int i = 0; i < 4; ++i){
		cin >> checkarr[i];
		if(checkarr[i] == 0)
			check++;
	}
	for(int i = 0; i < P; ++i)
		Add(A[i]);
	if(check == 4)
		result++;
	for(int i = P; i < S; ++i){
		int j = i - P;
		Add(A[i]);
		Remove(A[j]);
		if(check == 4)
			result++;
	}
	cout << result << "\n";
	return 0;
} 
