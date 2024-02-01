// https://www.acmicpc.net/problem/1926

// 1. dfs�� Ǯ��
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n = 0, m = 0, res_cnt = 0, res_area = 0;
int grid[504][504] = { 0, };
int visited[504][504] = { 0, };
const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

// 1. dfs Ǯ��
int dfs(int row, int col) {
	int size = 1;
	visited[row][col] = 1; // �湮ó��
	
	for (int i = 0; i < 4; i++) {
		int next_row = row + dr[i];
		int next_col = col + dc[i];
		if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
		if (visited[next_row][next_col]) continue;
		if (grid[next_row][next_col] == 0) continue;
		size += dfs(next_row, next_col);
	}
	return size;
}
// 2. bfs Ǯ��
int bfs(int row, int col) {
	visited[row][col] = 1; // �ʱ� �湮ó��
	queue<pair<int, int>> q;
	q.push({ row, col });
	int size = 1;
	while (q.size()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + dr[i];
			int next_col = cur_col + dc[i];
			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
			if (visited[next_row][next_col]) continue;
			if (grid[next_row][next_col] == 0) continue;
			visited[next_row][next_col] = 1; // �湮ó��
			size++;
			q.push({ next_row, next_col });
		}
	}
	return size;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || grid[i][j] == 0) continue;
			//res_area = max(res_area, dfs(i, j));
			res_area = max(res_area, bfs(i, j));
			res_cnt++;
		}
	}
	cout << res_cnt << "\n";
	cout << res_area << "\n";
	return 0;
}