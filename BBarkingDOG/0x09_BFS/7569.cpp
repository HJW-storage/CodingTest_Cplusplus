// https://www.acmicpc.net/problem/7569

#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;

const int dr[6] = {0, 0, 1, -1, 0, 0};
const int dc[6] = {1, -1, 0, 0, 0, 0};
const int dh[6] = {0, 0, 0, 0, 1, -1};
int grid[104][104][104] = { 0, }, visited[104][104][104] = { 0, };
int M = 0, N = 0, H = 0;
queue<tuple<int, int, int>> q;

void Qclear(queue<tuple<int, int, int>> &tq) {
	queue<tuple<int, int, int>> emptyq;
	swap(tq, emptyq);
	return;
}

bool check(int chk) {
	for (int h = 0; h < H; h++) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				// test case #3 -> abs �߰�. 
				if (abs(grid[r][c][h]) != chk) return false;
			}
		}
	}
	return true;
}

int solve_bfs() {
	int cur_row = 0, cur_col = 0, cur_hei = 0, next_row = 0, next_col = 0, next_hei = 0;
	int cnt = 0;
	queue<tuple<int, int, int>> tmpq;
	while (1) {

		while (q.size()) {
			tie(cur_row, cur_col, cur_hei) = q.front();
			q.pop();

			for (int i = 0; i < 6; i++) {
				next_row = cur_row + dr[i];
				next_col = cur_col + dc[i];
				next_hei = cur_hei + dh[i];

				// 0�̸� ������ �� �ִ�. -1 �̸� �������� ����. �������� 1�� update�����ش�.
				if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= M || next_hei < 0 || next_hei >= H) continue;
				if (visited[next_row][next_col][next_hei] == 1) continue; // �湮 �ߴ� ���̶��

				if (grid[next_row][next_col][next_hei] == 0) {
					visited[next_row][next_col][next_hei] = 1; // �湮ó��
					tmpq.push({ next_row, next_col, next_hei });
					grid[next_row][next_col][next_hei] = 1; // ������Ʈ. 
				}
			}
		}

		if (tmpq.size() == 0) break; //  Ż�� ����
		q = tmpq;
		Qclear(tmpq);	// ť ����. 
		cnt++;

	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// N : ��, M : ��, H : ����
	cin >> M >> N >> H;
	for (int h = 0; h < H; h++) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				cin >> grid[r][c][h];
				if (grid[r][c][h] == 1) {
					q.push({ r, c, h });
					visited[r][c][h] = 1; // �湮ó��
				}
			}
		}
	}

	// ó�� �־��� �丶�䰡 ��� �;��ִ� ���� '0' ����ϰ� ����. 
	if (check(1)) {
		cout << "0" << "\n";
		return 0;
	}

	int res = solve_bfs();
	// bfs ��ġ�� ���� ��� �;����� ���� ��츦 �˻��ϰ� ��� �;����� ������ -1 ���.
	if (check(1)) {
		cout << res << "\n";
	}
	else {
		cout << "-1" << "\n";
	}

	return 0;
}