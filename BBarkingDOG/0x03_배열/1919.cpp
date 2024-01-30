// https://www.acmicpc.net/problem/1919

// 1. ���� ���ĺ��� ���� �迭�� �������� ī����
// 2. �迭�� �� 2��. (1st ���ڿ�, 2nd ���ڿ�)
// 3. �迭 2���� ���Ͽ� �� ������ ������ ����, ������ ���� �ٸ� ���� �����ؾ��ϴ� �� ī��Ʈ �� ����.

#include <iostream>
#include <algorithm>

using namespace std;
string first_str, second_str;
int first_alpha[26], second_alpha[26], res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> first_str;
	for (char it : first_str) {
		first_alpha[it - 'a']++;
	}
	cin >> second_str;
	for (char it : second_str) {
		second_alpha[it - 'a']++;
	}

	// Ǯ�� ���� ����
	for (int i = 0; i < 26; i++) {
		if (first_alpha[i] == second_alpha[i]) {
			continue;
		}
		else { // ���ĺ� ������ �ٸ� ���, ���ĺ� ���� ���̸�ŭ ������� ���Ѵ�.
			res += abs(first_alpha[i] - second_alpha[i]);
		}
	}
	cout << res << "\n";

	return 0;
}