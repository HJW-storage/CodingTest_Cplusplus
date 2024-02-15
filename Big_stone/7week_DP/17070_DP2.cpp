#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int n = 0, grid[20][20] = { 0, }, dp[20][20][3] = { 0, };

int solve_dp() {
	// �������
	dp[1][2][0] = 1; // ó�� ��ġ ���ι���. 

	// �޸����̼�, ��������
	// 
	// 1�� ���ι��� �б� 
	for (int i = 3; i <= n; i++) {
		if (grid[1][i] == 1) break;
		dp[1][i][0] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (grid[i][j] != 1) {
				// ���� �������� (�о�����)���� �� �ִ� ��� = ���� dp�� ���� �������� ���� ��� �� + �밢�� �������� ���� ��� ��
				dp[i][j][0] += dp[i][j-1][0] + dp[i][j-1][1]; 

				// ���� �������� (�о�����)���� �� �ִ� ��� = ���� dp�� ���� �������� ���� ��� �� + �밢�� �������� ���� ��� ��
				dp[i][j][2] += dp[i-1][j][2] + dp[i-1][j][1]; 
				
				// �밢�� ������ �߰����� �˻� �ʿ�.
				if (grid[i - 1][j] != 1 && grid[i][j - 1] != 1) {
					// �밢�� �������� (�о�����)���� �� �ִ� ��� = ���� dp ���� + ���� + �밢�� �������� ���� ��� ��
					dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][2] + dp[i - 1][j - 1][1];
				}
			}
		}
	}

	// ���� ��� = ���� + �밢�� + ���� �������� �о����� ���� �� �ִ� ������� ��.
	int res = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}

	cout << solve_dp() << "\n";
	return 0;
}