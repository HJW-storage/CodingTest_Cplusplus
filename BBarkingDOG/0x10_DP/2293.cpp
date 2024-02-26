// https://www.acmicpc.net/problem/2293
#include <iostream>
#include <algorithm>
using namespace std;

int n = 0, k = 0, dp[10004] = { 0, }, coins[10004] = {0,};

// ������ �޶� ���� ������ ����. -> ���� k1 ���� ä���, k2 ä���, k3 ���� ä��� ������ dp �׾ư���.
int solve_dp() {
	// �������
	dp[0] = 1; // ����, �޸����̼� ���ϰ� �ϱ����� dp[0] = 1�� �صд�.
	
	// �޸����̼�, ��������
	for (int t = 1; t <= n; t++) {
		for (int j = coins[t]; j <= k; j++) {
			dp[j] = dp[j - coins[t]] + dp[j];
		}
	}
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