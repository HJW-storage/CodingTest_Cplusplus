// https://www.acmicpc.net/problem/9095

// n <= 10 ���. -> ���� Ž��, DP Ǯ�� ��� ����.
#include <iostream>
#include <algorithm>

using namespace std;
int n = 0, t = 0;
int dp[14];

// ����Ž��
int res = 0; 
void Full_Search(int idx, int sum) {
	// ���� ����
	if (idx > 10) return;
	if (sum == n) {
		res++;
		return;
	}

	// Ž�� (1, 2, 3���� ���� ���ϴ� ���)
	Full_Search(idx + 1, sum + 1);
	Full_Search(idx + 2, sum + 2);
	Full_Search(idx + 3, sum + 3);

	return;
}

// DP() Ǯ��
void solve_DP() {
	// ���� ���
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	// �޸����̼� (����)
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> t;
	//solve_DP();
	while (t--) {
		cin >> n; // �ʱ�ȭ. 
		//cout << dp[n] << "\n";

		res = 0; // �ʱ�ȭ
		Full_Search(0, 0); // 1���� ����
		cout << res << "\n";
	}

	return 0;
}