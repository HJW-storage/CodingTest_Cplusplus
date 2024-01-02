// https://www.acmicpc.net/problem/3474

#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case = 0;
	cin >> test_case;

	// ���μ� ������ ���信�� 2�� 5�� �����θ� 10�� ���������.
	// ������ �м��ϴٺ��� 2�� ������ 5�� ���� ���� �׻� ����. 
	// ���� 5�� ���� ������ ���ص� �ȴ�.
	for (int i = 0; i < test_case; i++) {
		int n = 0;
		cin >> n;

		ll sqrt_5 = 1;
		ll res = 0;
		while (sqrt_5 < n) {
			sqrt_5 = sqrt_5 * 5;
			res += n / sqrt_5;
		}
	cout << res << "\n";
	}

	return 0;
}