// https://www.acmicpc.net/problem/3986

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, result = 0;
	string ab_word;

	cin >> n; 

	//v_word.push_back('abc');
	//cout << v_word.empty() << endl; // ��� �ִٸ� 1�� ���, �ƴϸ� 0�� ���.
	//cout << *(v_word.end() - 1) << endl;

	for (int i = 0; i < n; i++) {
		vector<char> v_word;
		cin >> ab_word;
		// stack�� �̿��Ͽ� ���� ���ߴ� ��.
		// stack�� ����ְų� ���� ���� stack�� �ֻ�� ���� ���ٸ� 
		// �ֻ�� ���� ���� pop_back()
		// �ٸ� ���� ���ÿ� �ٽ� �ִ´� push_back()
		for (char it : ab_word) {
			if ( (v_word.empty()) || (it != *(v_word.end() - 1)) ) {
				v_word.push_back(it);
			}
			else {
				v_word.pop_back();
			}
		}

		if (v_word.empty()) {
			result++;
		}
	}

	cout << result << "\n";

	return 0;
}