#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int cnt[26] = { 0, };	// ���ĺ� a~z�� 26���̴�. 

int main() {

	string alphabet_str;
	cin >> alphabet_str;

	// char it : alphbet_str
	for (char it : alphabet_str) {
		cnt[it - 'a']++;
	}

	for (int it : cnt) {
		cout << it << " ";
	}

	return 0;
}