// https://www.acmicpc.net/problem/11655

// 해당 문제에서 if(조건문)  조건문 형식을 실수해서 해멨다. 
// 파이썬에서 사용하는  a <= x <= b 이렇게 쓰면 안된다. 
// C문법에서는         (a <= x) && (x <= b) and로 묶어줘야 한다.  

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string ROT13_str;
string ROT13_output;

#define BIG_A 65
#define BIG_Z 90
#define Small_a 97
#define Small_z 122

int main() {
	// 공백을 포함해서 입력을 받아야 하므로. 
	getline(cin, ROT13_str);

	// 아스키 코드 A : 65 ~ Z : 90,	a : 97 ~ z : 122
	for (char it : ROT13_str) {
		// 대문자인 경우
		if ( (65 <= int(it)) &&  (int(it)<= 90)) {
			int cmp = int(it) + 13;
			if (cmp > 90) {
				ROT13_output += char(65 + (cmp - 90 - 1));
			}
			else {
				ROT13_output += char(cmp);
			}
		}

		// 소문자인 경우
		else if ((97 <= int(it)) && (int(it) <= 122)) {
			int cmp = int(it) + 13;
			if (cmp > 122) {
				ROT13_output += char(97 + (cmp - 122 - 1));
			}
			else {
				ROT13_output += char(cmp);
			}
		}

		// 그 이외의 경우는 그냥 출력
		else {
			ROT13_output += it;
		}
	}

	cout << ROT13_output << "\n";

	return 0;
}