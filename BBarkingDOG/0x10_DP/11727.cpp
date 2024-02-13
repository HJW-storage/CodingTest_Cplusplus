// https://www.acmicpc.net/problem/11727

#include <iostream>
#include <algorithm>
using namespace std;

#define mod_n 10007
int n = 0, dp[1004] = {0,};
int solve_dp() {
	// �������
	dp[1] = 1;
	dp[2] = 3;

	// �޸����̼�, ���� ����
	for (int i = 3; i <= n; i++) {
		// ��ⷯ ���� ��Ģ : ���� �� ������ = ���� ������ ������ �������� �հ� ����.
		dp[i] = (dp[i - 1] % mod_n + (dp[i - 2] * 2) % mod_n) % mod_n;
	}
	return dp[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cout << solve_dp() << "\n";

	return 0;
}