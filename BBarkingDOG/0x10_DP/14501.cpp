// https://www.acmicpc.net/problem/14501

// �Ｚ SW ���� �׽�Ʈ ���⹮��.
// dp�� �ڿ������� �ؿ��°� ���� ������ ����Ǯ���� ���ο� �ð��� �� ������..
// dp�� �ݵ�� �տ������� �϶�� ���������� �ƶ߸� ����!!

#include <iostream>
#include <algorithm>
using namespace std;

int n = 0, T[20] = { 0, }, P[20] = { 0, }, dp[20] = {0,};

void solve_dp() {
	// �޸����̼�, ���� ����
	for (int i = n; i > 0; i--) {
		int dealline = i + T[i];
		if (dealline > n + 1) {
			// ��� �Ұ�
			dp[i] = dp[i + 1];
		}
		else {
			// ��� ����
			dp[i] = max(dp[i + 1], dp[dealline] + P[i]);
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}

	solve_dp();
	cout << dp[1] << "\n";

	return 0;
}