// https://www.acmicpc.net/problem/2577

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int a, b, c, res;	// ����� �ִ� 10���̹Ƿ� int������ ǥ�� ����.
int alphabet_arr[10];

void solve(int res) {
	string res_str = to_string(res);	// int�� -> string���� ��ȯ
	for (char it : res_str) {
		alphabet_arr[it - '0']++;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a;
	cin >> b;
	cin >> c;
	res = a * b * c;
	solve(res);

	for (int i = 0; i < 10; i++) {
		cout << alphabet_arr[i] << "\n";
	}
	return 0;
}
