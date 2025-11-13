#include <iostream>
#include <string>

using namespace std;

class WordUtility {
public:
	static int wordCount(string str);
	static string getWord(string str, int cnt);
};

int WordUtility::wordCount(string str) {
	int cnt = 1;
	int offset = 0;
	if (str == "") return 0;
	while (offset != -1) {
		offset = str.find(" ", offset + 1); //" "찾기 , offset+1 = 탐색위치->찾으면 찾은곳 index반환 
		if (offset != -1) {
			cnt++;
		}
	}
	return cnt;
}
string WordUtility::getWord(string str, int cnt) {
	int offset = 0;
	if (cnt == 0) {
		return "";
	}
	//단어 위치 측정. 
	for (int i = 0; i < cnt - 1; i++) {
		offset = str.find(" ", offset); //offset부터 탐색, 빈칸 idx반환 
		if (offset == -1) {
			return "";
		}
		offset += 1; 
	}
	str = str.substr(offset, str.length()); //cnt번째 부터 str길이 만큼 자르기. 

	offset = str.find(" "); //offset은 빈칸 위치 
	if (offset != -1) { //빈칸 위치가 문자 끝이 아니라면 
		str = str.substr(0, offset);  //str 의 첫번째 인덱스부터 offset까지 (다음빈칸)까지 자르기 
	}
	
	return str;
}

int main() {
	string str;
	getline(cin,str,'\n'); 
	int n = WordUtility::wordCount(str);
	cout << "단어 개수는 " << n << endl;
	string word = WordUtility::getWord(str, 3);
	if (word == "")
		cout << "3번째 단어는 없습니다." << endl;
	else
		cout << "3번째 단어는 " << word << endl;

	return 0;
}
