// https://www.acmicpc.net/problem/16234
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int n = 0, l = 0, r = 0, result = 0;
const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

bool solve_bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) {
	visited[row][col] = 1; // �湮ó��
	queue<pair<int, int>> q;
	q.push({ row, col });
	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	int part_sum = grid[row][col];
	int part_cnt = 1;
	bool part_flag = false;
	vector<pair<int, int>> part_house;	// �ʱ�ȭ. 
	part_house.push_back({ row, col });

	while (q.size()) {
		cur_row = q.front().first;
		cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
				// �湮ó���� �˻��ϱ� ������ �Ʒ��ʿ��� bfs ����� �ٷ� ������Ʈ �ص� �ȴ�. 
				if (visited[next_row][next_col] == 0) {
					if (abs(grid[cur_row][cur_col] - grid[next_row][next_col]) >= l && abs(grid[cur_row][cur_col] - grid[next_row][next_col]) <= r) {
						part_flag = true;	// ���漱 ����
						part_sum += grid[next_row][next_col];
						part_cnt++;
						part_house.push_back({ next_row, next_col });
						visited[next_row][next_col] = 1; // �湮ó��
						q.push({ next_row, next_col });
					}
				}
			}
		}
	}

	// �α� �̵��� �߻����� ��� ������Ʈ �غ���. 
	if (part_flag == true) {
		// ���ʿ��� visited�� �˻��ϱ⿡ �ٷ� ������Ʈ�ص� ������� �����̰��� �ʴ´�. 
		int new_sum = part_sum / part_cnt;
		for (pair<int, int> it : part_house) {
			grid[it.first][it.second] = new_sum;	// ���ο� ������ �α��̵� �Ϸ�. 
		}
	}
	else { ; }
	return part_flag;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool check_flag = true;

	cin >> n >> l >> r;
	vector<vector<int>> grid(n, vector<int>(n, 0));
	vector<vector<int>> visited(n, vector<int>(n, 0));
	// ���� ���� �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int check_cnt = 0;
	// ���� ����
	while (check_flag){
		check_cnt = 0;
		// visited �ʱ�ȭ
		fill(visited.begin(), visited.end(), vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// bfs 
				if (visited[i][j] == 0) {
					bool check_bool = solve_bfs(i, j, grid, visited);
					if (check_bool == true) check_cnt++;
				}
			}
		}
		// �α� �̵��� �ѹ� �� ���� ���� check_cnt == 0 �� ����. 
		if (check_cnt == 0) {
			break;
		}
		else {
			result++;
		}
	}

	cout << result << "\n";
	return 0;
}