// https://www.acmicpc.net/problem/6593
// �Է¿��� ���� start ��ǥ�� row, col, hei�� ����� �Է��� �ȵǾ ������� �κ��̴�... 
// �ǵ��� ���� r�� ����, ���� c��, ���̴� h�� �Ἥ ���� �߶�� ����....

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int L = 0, R = 0, C = 0;
char grid[34][34][34];
int visited[34][34][34] = { 0, };

const int dr[6] = { -1, 0, 1, 0, 0, 0 };
const int dc[6] = { 0, 1, 0, -1, 0, 0 };
const int dh[6] = { 0, 0, 0, 0, 1, -1 };

int solve_bfs(int row, int col, int hei) {
	visited[row][col][hei] = 1; // �ʱ� �湮ó��
	queue<tuple<int, int, int>> q;
	q.push({row, col, hei});

	int cur_row = 0, cur_col = 0, cur_hei = 0, next_row = 0, next_col = 0, next_hei = 0;
	while (q.size()) {
		tie(cur_row, cur_col, cur_hei) = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			next_row = cur_row + dr[i];
			next_col = cur_col + dc[i];
			next_hei = cur_hei + dh[i];

			// '.', 'E'�� ������ �� �ִ� ĭ�̴�. = '#'�� �ƴϸ� ��������.
			if (next_row < 0 || next_row >= R || next_col < 0 || next_col >= C || next_hei < 0 || next_hei >= L) continue;
			if (visited[next_row][next_col][next_hei] > 0) continue; // �湮�߾�� ���. 
			
			if (grid[next_row][next_col][next_hei] != '#') {
				visited[next_row][next_col][next_hei] = visited[cur_row][cur_col][cur_hei] + 1; // �湮ó��
				q.push({ next_row, next_col, next_hei });

				if (grid[next_row][next_col][next_hei] == 'E') {
					// �������� -1�ؼ� return.
					return (visited[next_row][next_col][next_hei] - 1);
				}
			}
		}
	}

	return 0;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// ���� �׽�Ʈ ���̽� �Է�
	while (1) {
		// �ʱ�ȭ
		fill(&visited[0][0][0], &visited[0][0][0] + 34 * 34 * 34, 0);
		fill(&grid[0][0][0], &grid[0][0][0] + 34 * 34 * 34, 'a');

		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break; // �׽�Ʈ ���̽� ����.

		// grid �Է�
		int start_r = 0, start_c = 0, start_h = 0;
		for (int h = 0; h < L; h++) {
			for (int r = 0; r < R; r++) {
				string tmp;
				cin >> tmp;
				for (int c = 0; c < C; c++) {
					grid[r][c][h] = tmp[c];
					// bfs ���� ��ġ ����.
					if (grid[r][c][h] == 'S') {
						start_h = h;
						start_r = r; 
						start_c = c;
					}
				}
			}
		}

		int res = solve_bfs(start_r, start_c, start_h);
		if (res != 0) {
			cout << "Escaped in " << res << " minute(s)." << "\n";
		}
		else {
			cout << "Trapped!" << "\n";
		}
	}
	return 0;
}