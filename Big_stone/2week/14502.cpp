// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m;
vector<int> res;	// �������� ���� ���� ����

void solve_bfs(int row, int col, vector<vector<int>>& tmp_grid, vector<vector<int>>& visited) {
	visited[row][col] = 1;	// �湮ó��
	queue<pair<int, int>> q;
	const int dr[4] = {0, 1, 0, -1};
	const int dc[4] = {1, 0, -1, 0};
	q.push({ row, col });

	while (q.size()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + dr[i];
			int next_col = cur_col + dc[i];
			if(next_row >= 0 && next_row < n && next_col >= 0 && next_col < m){
				// tmp_grid[next_row][next_col] == 0 �� �ƴ϶� != 1�� �� ������
				// 1(��)�� �ƴҶ��� ���ϰ�, 0(�� ����)�� 2(���̷���)�� 2�� ������ �湮�Ͽ� �湮ó���� �Ѵ�.
				// �湮ó���� bfs ���ο��� ���ָ� ���� main ���� for�� ���� �ٽ� bfs�ϴ� ���� ���� �� �ִ�.   
				if (tmp_grid[next_row][next_col] != 1 && visited[next_row][next_col] == 0) {
					visited[next_row][next_col] = 1;	// �湮ó��
					tmp_grid[next_row][next_col] = 2;
					q.push({ next_row, next_col });
				}
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	vector<pair<int, int>> zero_rc;

	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int in_tmp = 0;
			cin >> in_tmp;
			grid[i][j] = in_tmp;
			if (in_tmp == 0) zero_rc.push_back({ i, j });
		}
	}

	// 3�� �̴� ���� �ϼ�
	for (int i = 0; i < zero_rc.size(); i++) {
		for (int j = i + 1; j < zero_rc.size(); j++) {
			for (int k = j + 1; k < zero_rc.size(); k++) {
				vector<vector<int>> tmp_grid(n, vector<int>(m, 0));
				vector<vector<int>> visited(n, vector<int>(m, 0));
				tmp_grid = grid;	// ���� ����

				int row1 = zero_rc[i].first; int col1 = zero_rc[i].second;
				int row2 = zero_rc[j].first; int col2 = zero_rc[j].second;
				int row3 = zero_rc[k].first; int col3 = zero_rc[k].second;
				// ���� �˻�� �Է� ���� grid�� �̹� 0�� �ƴϸ� �ش� Ƚ���� �ǳʶڴ�. ��� 0�϶��� ����.
				// 1�� �ٲ۴�.
				if (tmp_grid[row1][col1] == 0 && tmp_grid[row2][col2] == 0 && tmp_grid[row3][col3] == 0) {
					tmp_grid[row1][col1] = 1;
					tmp_grid[row2][col2] = 1;
					tmp_grid[row3][col3] = 1;

					// dfs Ȥ�� bfs�� �̿��Ͽ� ���̷��� ������Ű�� 0���� ����.
					for (int r = 0; r < n; r++) {
						for (int c = 0; c < m; c++) {
							if (tmp_grid[r][c] == 2 && visited[r][c] == 0) {
								solve_bfs(r, c, tmp_grid, visited);
							}
						}
					}
					// tmp_grid���� 0���� ���� rec ���Ϳ� �ֱ�.
					int cnt = 0;
					for (int r = 0; r < n; r++) {
						for (int c = 0; c < m; c++) {
							if (tmp_grid[r][c] == 0) {
								cnt++;
							}
						}
					}
					res.push_back(cnt);
				}

			}
		}
	}
	// rec ���� �������� ���� ��, ������ ���� �� ����ϱ�.
	sort(res.begin(), res.end());
	cout << *(res.end() - 1) << "\n";
	return 0;
}