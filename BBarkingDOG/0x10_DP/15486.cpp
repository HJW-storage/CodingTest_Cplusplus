// https://www.acmicpc.net/problem/15486

#include <iostream>
#include <algorithm>
using namespace std;

#define max_n 1'500'004
int n = 0, T[max_n] = { 0, }, P[max_n] = { 0, }, dp[max_n] = { 0, };

// dp �迭���� �ִ� ���� ������ ������.
int solve_dp() {
	// �������
	if (T[n] == 1) dp[n] = P[n];
	else dp[n] = 0;

	// �޸����̼�, ���� ����
	// dp �迭 �ڿ��� ���� ä��°� �� ���� ������ �ȴ�.
	for (int j = n - 1; j > 0; j--) {
		// n+1 ���� ũ�� �� ���� -> ���� �Ʒ� ���ÿ��� 6������ �ϸ� 7������ ���ϴ� ����.
		// 1 2 3 4 5 6 7
		// - - - - - 2 1
		// - - - - - 9 5
		// n+1 ������ ���ȴ�. 
		// dp[n+1 = 8] �� 0�̱⿡ -> dp[6] = dp[8] (0) + P[6] �� dp[7]�� �ִ� ���� ����ǰԵȴ�.
		if (T[j] + j > n + 1) {
			dp[j] = dp[j + 1]; // �ش� ��¥�� �� ���ϹǷ� ������ �״�� ��������.
		}
		else {
			dp[j] = max(dp[T[j] + j] + P[j], dp[j + 1]);
		}
	}
	return dp[1];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}

	cout << solve_dp() << "\n";
	return 0;
}