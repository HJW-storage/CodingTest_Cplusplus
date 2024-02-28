// https://www.acmicpc.net/problem/1520
// bfs + dp(�ߺ� ���� -> �켱���� ť)�� �̿��ϴ� �������� ��������!!!

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> P; // grid[][], ��, �� 

int m = 0, n = 0, grid[504][504] = { 0, }, dp[504][504] = { 0, };
const int dr[4] = {0, 0, 1, -1};
const int dc[4] = { 1, -1, 0, 0 };

// dp �迭�� �湮ó���� �ϰ� �ߺ��Ǵ� ���� ����(�켱���� ť�� ���� �ߺ��� ����).
priority_queue<P, vector<P>, less<P>> pq; //priority queue(�ڷ���, ����ü, �񱳿�����(=less)) greater�� �ּ���
int solve_bfs_dp() {
	// �������
	dp[0][0] = 1;
	pq.push({ grid[0][0], 0, 0 });

	// ���� ����
	int info = 0, cur_row = 0, cur_col = 0;
	while (pq.size()) {
		tie(info, cur_row, cur_col) = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + dr[i];
			int next_col = cur_col + dc[i];

			if (next_row < 0 || next_row >= m || next_col < 0 || next_col >= n) continue;
			if (grid[next_row][next_col] >= info) continue;

			// �ߺ� ���� (�̹� �湮ó���� �� ���� pq�� ���� �ʰ�, ����Ǽ��� �����ֱ⸸ ����.)
			if (dp[next_row][next_col] == 0) {
				pq.push({ grid[next_row][next_col], next_row, next_col });
			}
			dp[next_row][next_col] += dp[cur_row][cur_col];
		}
	}
	return dp[m - 1][n - 1];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	cout << solve_bfs_dp() << "\n";

	return 0;
}