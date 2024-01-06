// https://www.acmicpc.net/problem/2636
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
int n = 0, m = 0, cheese_cnt = 0, res_hour = 0, check = 3;

void solve_dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
	visited[row][col] = true; // �湮ó��

	// ���� ����
	grid[row][col] = check;	// ġ� ���۰� �����ϱ� ���� 99�� ����. 
	int next_row = 0, next_col = 0;
	for (int i = 0; i < 4; i++) {
		next_row = row + dr[i];
		next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			if (grid[next_row][next_col] == 0 && visited[next_row][next_col] == false) {
				solve_dfs(next_row, next_col, grid, visited);
			}
		}
	}
}

void delete_cheese(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>> &zero_idx) {
	for (int i = 0; i < 4; i++) {
		int next_row = row + dr[i];
		int next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			if (grid[next_row][next_col] == 1 && visited[next_row][next_col] == false) {
				grid[next_row][next_col] = check;
				visited[next_row][next_col] = true;	// �湮ó��
				cheese_cnt--;

				// ġ� �����ִ��� �˻��غô�.
				for (int i = 0; i < 4; i++) {
					int nnext_row = next_row + dr[i];
					int nnext_col = next_col + dc[i];
					if (nnext_row >= 0 && nnext_row < n && nnext_col >= 0 && nnext_col < m) {
						if (grid[nnext_row][nnext_col] == 0 && visited[nnext_row][nnext_col] == false) {
							zero_idx.push_back({ nnext_row, nnext_col });
						}
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) cheese_cnt++;
		}
	}

	// int prev_cheese_cnt = 0; <- �� ó�� 0���� �����ߴµ�, 
	// �̷��� �Ǹ� �� �ڵ�� 1�ð� ���� ��� �������� ġ���� ���� ��ó�� ġ�� ���� ��µǾ���ϴµ� 0�� ��µǴ� �����̴�.
	int prev_cheese_cnt = cheese_cnt;

	// ���� ���ǿ��� ���� �ڸ����� ġ� ���ٰ� �߱⿡ dfs�� 0,0���� �����ϰ� ����.
	solve_dfs(0, 0, grid, visited);

	while (cheese_cnt) {
		vector<pair<int, int>> zero_idx;	// �Ź� �ʱ�ȭ. ġ�� ������ �շ��� ��, �ش� �κ� ����� ä��� ���� �ʿ��� ����.
		int prev_check = check;
		check++;

		// ġ�� ��������
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == prev_check) {
					delete_cheese(i, j, grid, visited, zero_idx);
				}
			}
		}
		res_hour++;
		if (cheese_cnt == 0) break;
		prev_cheese_cnt = cheese_cnt;

		// ġ�� ���ۿ� ��ƴ�� ���ܼ� ���Ⱑ ����ٸ� dfs ������ ���Ⱑ �����ߴٴ� ���� �����.
		if (zero_idx.size() != 0) {
			for (pair<int, int> it : zero_idx) solve_dfs(it.first, it.second, grid, visited);
		}
	}

	cout << res_hour << "\n";
	cout << prev_cheese_cnt << "\n";
	return 0;
}