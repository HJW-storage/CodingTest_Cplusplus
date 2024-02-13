// https://www.acmicpc.net/problem/12852

#include <iostream>
#include <algorithm>
using namespace std;

// n���� -> 1�� ���°����� �����ϸ� ��ƴ�.
// ������ �����ؼ�
// 1���� -> n�� ����� ������ ����.
// (1). 3�� ����̸� dp[i/3] ���� 3�� ���ؼ� ���� ���
// (2). 2�� ����̸� dp[i/2] ���� 2�� ���ؼ� ���� ���
// (3). 1�� ���ϴ� ���

int n = 0;
int dp[1000004] = { 0, };

void solve_dp() {
	// �������
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	// �޸����̼�, ���� ����
	for (int i = 4; i <= n; i++) {
		// (0). i�� 3�� ����̸鼭 2�� ����� ��쵵 ������־�� �Ѵ�.... !! 
		if (i % 3 == 0 && i % 2 == 0) {
			dp[i] = min(min(dp[i - 1] + 1, dp[i / 3] + 1), dp[i / 2] + 1);
		}
		// (1). i�� 3�� ����̸�
		else if(i % 3 == 0){
			dp[i] = min(dp[i - 1] + 1, dp[i / 3] + 1);
		}
		// (2). i�� 2�� ����̸�
		else if (i % 2 == 0) {
			dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
		}
		// (3). ������
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	solve_dp();
	cout << dp[n] << "\n";
	while (n >= 1) {
		cout << n << " ";
		if (n % 3 == 0 && n % 2 == 0) {
			if (dp[n / 3] <= dp[n - 1] && dp[n / 3] <= dp[n / 2]) {
				n = n / 3;
			}
			else if (dp[n / 2] <= dp[n - 1] && dp[n / 2] <= dp[n / 3]) {
				n = n / 2;
			}
			else if (dp[n - 1] <= dp[n / 3] && dp[n - 1] <= dp[n / 2]) {
				n--;
			}
		}
		else if (n % 3 == 0) {
			n = dp[n / 3] <= dp[n - 1] ? n / 3 : n - 1;
		}
		else if (n % 2 == 0) {
			n = dp[n / 2] <= dp[n - 1] ? n / 2 : n - 1;
		}
		else {
			n--;
		}
	}

	return 0;
}