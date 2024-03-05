// https://www.acmicpc.net/problem/16236

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int n = 0, grid[24][24] = { 0, }, visited[24][24] = { 0, }, res = 0, shark_size = 2;
const int dr[4] = { -1, 0, 0, 1 };
const int dc[4] = { 0, -1, 1, 0 };
pair<int, int> baby_shark;
vector<tuple<int, int, int>> shark_v; // �Ʊ�� ��� ���� �� �ִ� ����� ���� ���� ����.

void Qclear(queue<pair<int, int>> &vq) {
	queue<pair<int, int>> emptyq;
	swap(vq, emptyq);
	return;
}
void solve_bfs(int row, int col) {
	// �Ʊ�� ����⸦ ��� �Ծ����� visited �ʱ�ȭ. 
	// ���� ũ��� �׳� ���. ū ũ��� ��� x

	visited[row][col] = 0; // �ʱ� �湮ó��
	queue<tuple<int, int, int>> q;
	q.push({ 0, row, col }); // ó�� �Ʊ� ��� ���� 0. 

	int eat_cnt = 0;
	int cur_dis = 0, cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	while(1){
		if (q.size() == 0) break;

		while (q.size()) {
			tie(cur_dis, cur_row, cur_col) = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				next_row = cur_row + dr[i];
				next_col = cur_col + dc[i];

				if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n) continue;
				if (visited[next_row][next_col] != -1) continue;
			
				if (grid[next_row][next_col] <= shark_size ) {
					visited[next_row][next_col] = visited[cur_row][cur_col] + 1; // �湮ó��
					q.push({ cur_dis + 1, next_row, next_col });
					// ��ĭ�̰ų� �Ʊ� ���� ũ�Ⱑ ���� ��� ĭ�� ����� ����. 
					if (grid[next_row][next_col] == 0 || grid[next_row][next_col] == shark_size) continue;

					// ��� �Ծ���. ��� ũ�� ������Ʈ ���� ������ Ű���, �湮�迭 �ʱ�ȭ.
					shark_v.push_back({ cur_dis + 1, next_row, next_col });
				}
			}
		}

		if (shark_v.size()) {
			eat_cnt++;
			if (eat_cnt == shark_size) {
				shark_size++;
				eat_cnt = 0;
			}

			sort(shark_v.begin(), shark_v.end()); // ����. �Ÿ� -> row -> col ������ �������� ����.
			int d = 0, r = 0, c = 0;
			tie(d, r, c) = shark_v[0];
			grid[r][c] = 0; // ����� ��ƸԾ ��ĭ����. 
			res += d;
			fill(&visited[0][0], &visited[0][0] + (24 * 24), -1); // �湮 �迭 �ʱ�ȭ

			// ���Ӱ� �Ʊ����� ������ġ�� ť�� ä���ְ� ���� �Ÿ��� 0.  
			q.push({ 0, r, c });
			visited[r][c] = 0; // �ʱ� ������ġ 0.
			shark_v.clear(); // ��� ���� �� �ִ� ����� ���� ����ֱ�.
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 9) {
				baby_shark = { i, j }; // �Ʊ��� ��ġ
				grid[i][j] = 0; // �Ʊ���� ������ �����̴� ��ü�ϱ� �����̸� �����.
			}
		}
	}

	fill(&visited[0][0], &visited[0][0] + 24 * 24, -1);
	solve_bfs(baby_shark.first, baby_shark.second);

	cout << res << "\n";
	return 0;
}