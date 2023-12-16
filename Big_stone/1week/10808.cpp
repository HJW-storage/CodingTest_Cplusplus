// https://www.acmicpc.net/problem/10808
// map�� ����Ͽ� Ǯ���Ͽ���.

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
map<char, int> mp;

int main() {
	
	string alphbet_str;
	cin >> alphbet_str;

	// �ƽ�Ű�ڵ� a : 97 ~ z : 97+26 ���� ��� ���ĺ��� map�� Ű������ �̸� �־�д�.
	for (int i = 97; i < (97 + 26); i++) {
		mp[i] = 0;
	}

	for (int i = 0; i < alphbet_str.length(); i++) {
		mp[alphbet_str[i]] += 1;
	}

	// auto it -> pair<char, int>�� �ᵵ �ȴ�. 
	for (auto it : mp) {
		cout << it.second << " ";
	}

	return 0;
}