// https://www.acmicpc.net/problem/1941

// 1. ����Ž�� -> ������ Ȱ��. combi(25, 7) -> 480,000 ����. 
// 2. �������� 7���� ����� -> bfs�� ���� �̾��� �ִ� ���� �˻�.
// 3. �̾��� �ִ� ������ ���, �ټ��� �л��� �� >= 4 �̻����� �˻�.
// ���� �ð� ���⵵ : 480,000 x 5*5 = 10,000,000 

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

char grid[5][5];
int combi_[5][5] = { 0, }, visited_[5][5] = {0,}, res = 0;
pair<int, int> grid_idx[25];	// ������ ���� ��, grid�� row, col�� �����Ϸ��� pair �迭.
const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 };

bool solve_bfs(int row, int col) {
	queue<pair<int, int>> q;
	q.push({ row, col });
	visited_[row][col] = 1; // �ʱ� �湮ó��

	int cnt = 0, s_cnt = 0, cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	bool flag = false;

	while (q.size()) {
		tie(cur_row, cur_col) = q.front();
		q.pop();

		if (grid[cur_row][cur_col] == 'S') s_cnt++;

		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];

			if (next_row < 0 || next_row > 4 || next_col < 0 || next_col > 4) continue;
			if (visited_[next_row][next_col] == 1) continue;
			if (combi_[next_row][next_col] == 1) {
				visited_[next_row][next_col] = 1; // �湮ó��
				q.push({ next_row, next_col });
			}
		}
		cnt++;
	}
	if (cnt >= 7 && s_cnt >= 4) flag = true;
	return flag;
}
void combi(int start, int r, vector<int> v) {
	if (v.size() == r) {
		fill(&combi_[0][0], &combi_[0][0] + 5 * 5, 0); // �ʱ�ȭ
		fill(&visited_[0][0], &visited_[0][0] + 5 * 5, 0); // �ʱ�ȭ

		int row = 0, col = 0;
		for (int it : v) {
			tie(row, col) = grid_idx[it];
			combi_[row][col] = 1; // ǥ��.
		}

		if (solve_bfs(row, col)) res++;
		return;
	}

	for (int i = start + 1; i < 25; i++) {
		v.push_back(i);
		combi(i, r, v);
		v.pop_back();
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int tmp = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> grid[i][j];
			grid_idx[tmp++] = { i, j };
		}
	}

	vector<int> b;
	combi(-1, 7, b);
	cout << res << "\n";
	return 0;
}