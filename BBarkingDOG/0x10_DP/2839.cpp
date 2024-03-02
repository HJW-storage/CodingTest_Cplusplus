// https://www.acmicpc.net/problem/2839
#include <iostream>
#include <algorithm>
using namespace std;

int n = 0, dp[5004] = { 0, };
void solve_dp() {
	// �ʱ�ȭ
	fill(&dp[0], &dp[0] + 5004, 10000);

	// �������
	dp[3] = 1;
	dp[5] = 1;

	// �޸����̼�, ��������
	for (int i = 6; i <= n; i++) {
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
	}

	if (dp[n] >= 10000) cout << "-1" << "\n";
	else cout << dp[n] << "\n";
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	solve_dp();
	return 0;
}