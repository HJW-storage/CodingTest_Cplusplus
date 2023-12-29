// https://www.acmicpc.net/problem/2583

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m = 0, n = 0, k = 0;
int cnt = 1;	// cnt ���������� �����ؼ� dfs���� ���� ī��Ʈ�� ���.

void solve_dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
	visited[row][col] = true;	// �湮ó��
	const int dr[4] = {-1, 0, 1, 0};
	const int dc[4] = {0, 1, 0, -1};

	int next_row, next_col;
	for (int i = 0; i < 4; i++) {
		next_row = row + dr[i];
		next_col = col + dc[i];
		if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < n) {
			if (grid[next_row][next_col] == 0 && visited[next_row][next_col] == false) {
				cnt++;
				solve_dfs(next_row, next_col, grid, visited);
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> k;

	vector<vector<int>> grid(m, vector<int>(n, 0));
	vector<vector<bool>> visited(m, vector<bool>(n, false));

	for (int i = 0; i < k; i++) {
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		int row_len = y2 - y1;
		int col_len = x2 - x1;

		int start_row = m - y1 - row_len;
		int row_range = start_row + row_len;

		int start_col = x1;
		int col_range = start_col + col_len;

		//cout << start_row << "\t" << start_col << "\n";
		// ���簢�� ���̿� �ش��ϴ� grid �ε����� �°� 1�� ä���
		for (int i = start_row; i < row_range; i++) {
			for (int j = start_col; j < col_range; j++) {
				grid[i][j] = 1;
			}
		}

		/*for (int i = 0; i < grid.size(); i++) {
			for (auto it : grid[i]) {
				cout << it << " ";
			}
			cout << "\n";
		}*/
	}
	vector<int> res;

	int result = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 0 && visited[i][j] == false) {
				cnt = 1; // (cnt�� ���������� �����ߴ�.) dfs ������ �ߴٸ� �ּ� ���̴� 1�̱⿡ 1�� �ʱ�ȭ ���ش�. 
				// ���� ���� ���ǿ��� "�ԷµǴ� K���� ���簢������ ������ ��ü�� ä��� ���� ����."�̱⿡ 1�� �Ѵ�. 
				
				solve_dfs(i, j, grid, visited);
				result++;
				res.push_back(cnt);
			}
		}
	}

	cout << result << "\n";
	// ���� ������ ���� �ּ� 1�� �̻��� res ���Ϳ� ���� ������ �ȴ�.
	sort(res.begin(), res.end());
	for (int it : res) cout << it << " ";

	return 0;
}