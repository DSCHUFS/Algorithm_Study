#include <iostream>
#include <string>
#include <algorithm>
//백준 9251번
//LCS
using namespace std;

int length[1001][1001];

int main(){

	string s1, s2; //문자열1, 문자열2
	cin >> s1;
	cin >> s2;
	s1.insert(0, " "); //문자열 앞에 공백을 넣어줌. 다른 문자여도 상관없음.
	s2.insert(0, " ");

	for(int i=0; i<s1.length(); i++){

		for(int j=0; j<s2.length(); j++){

			if(i == 0 || j == 0){ //문자열이 시작하기 전 칸들을 0으로 맞춰줌
				length[i][j] = 0;
			}
			else if(s1[i] == s2[j]) { //같은 문자일때,
				length[i][j] = length[i-1][j-1] + 1; //왼쪽 대각선 위 + 1
			}
			else{ //서로 다른 문자일땐, 왼쪽이나, 위에서 더 큰 값을 가져다 씀.
				length[i][j] = max((length[i][j-1]),(length[i-1][j]));
			}
		}
	}

	cout << length[s1.length()-1][s2.length()-1];

	return 0;
}
