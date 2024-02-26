// https://www.acmicpc.net/problem/2294
#include <iostream>
#include <algorithm>
using namespace std;

#define max_n 987654321
int n = 0, k = 0, dp[10'004] = { 0, }, coins[10'004] = { 0, };

int solve_dp() {
	// �ʱ�ȭ
	fill(&dp[0], &dp[0] + 10004, max_n);

	// �������
	dp[0] = 0;

	// �޸����̼�, ��������
	for (int i = 1; i <= k; i++) {
		int min_tmp = max_n;
		for (int j = 1; j <= n; j++) {
			int idx = i - coins[j];
			if (idx < 0) continue;
			min_tmp = min(min_tmp, dp[idx]);
		}
		dp[i] = min_tmp + 1;
	}

	// ��� ��ȯ.
	if (dp[k] >= max_n) return -1; // �־��� �������� ������ �� ���� ���.
	return dp[k];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}
	cout << solve_dp() << "\n";
	return 0;
}