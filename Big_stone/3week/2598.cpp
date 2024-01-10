// https://www.acmicpc.net/problem/2589
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n = 0, m = 0, res = 0;
int solve_bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
	visited[row][col] = 1; // �湮ó��
	queue<pair<int, int>> q;
	q.push({ row, col });
	const int dr[4] = { 0, 1, 0, -1 };
	const int dc[4] = { 1, 0, -1, 0 };
	int min_mxdis = 0;
	while (q.size()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + dr[i];
			int next_col = cur_col + dc[i];
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
				if (grid[next_row][next_col] == 'L' && visited[next_row][next_col] == 0) {
					visited[next_row][next_col] = visited[cur_row][cur_col] + 1;
					min_mxdis = visited[cur_row][cur_col];
					q.push({ next_row, next_col });
				}
			}
		}
	}
	return min_mxdis;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m, 'x'));
	vector<vector<int>> visited(n, vector<int>(m, 0));
	vector<pair<int, int>> land_idx;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			grid[i][j] = temp[j];
			if(grid[i][j] == 'L'){
				land_idx.push_back({ i, j });
			}
			else { ; }
		}
	}

	for (pair<int, int> it : land_idx) {
		// �׽�Ʈ ���̽��� �湮 ���� �ʱ�ȭ ���־�� �Ѵ�.
		fill(visited.begin(), visited.end(), vector<int>(m, 0));
		res = max(res, solve_bfs(it.first, it.second, grid, visited));
	}
	cout << res << "\n";
	return 0;
}