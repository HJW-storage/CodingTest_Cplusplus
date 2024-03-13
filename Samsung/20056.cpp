// https://www.acmicpc.net/problem/20056

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple< int, int, int, int, int > T;

const int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int N = 0, M = 0, K = 0, res = 0;
queue<T> grid[54][54];
queue<T> q;

void check_fireball() {
	// ������ ���̾�� ������ ��Ģ ����.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (grid[i][j].size() == 1) {
				//cout << "here" << "\n";
				q.push({ grid[i][j].front()});	// ���� Ž���� ���� ť�� �ֱ�.
				grid[i][j].pop();
			}
			else if (grid[i][j].size() > 1) { // ������ ���̾
				int r1 = 0, c1 = 0, m1 = 0, s1 = 0, d1 = 0;
				int next_m1 = 0, next_s1 = 0, prev_d1 = 0;
				int size = grid[i][j].size();
				bool flag = true;
				for (int p = 1; p <= size; p++) {
					tie(r1, c1, m1, s1, d1) = grid[i][j].front();
					grid[i][j].pop();
					next_m1 += m1;
					next_s1 += s1;
					if (p != 1) {
						if ((prev_d1 + d1) % 2 != 0) flag = false; // ¦Ȧ, Ȧ¦
					}
					prev_d1 = d1;
				}
				// ������ ���̾ 4���� ���̾�� ������.
				next_m1 = next_m1 / 5;
				next_s1 = next_s1 / size;
				int start_d = 0;
				if (flag) start_d = 0;
				else start_d = 1;
				// 4���� ���̾ ���� ������ �Ѹ��� ���� ť�� �ֱ�.
				// ��, ������ 0�̸� �Ҹ�.
				if (next_m1 != 0) {
					for (int a = 0; a < 4; a++) {
						q.push({ i, j, next_m1, next_s1, start_d });
						start_d += 2;
					}
				}
			}
		}
	}
	return;
}

void move_fireball() {
	int cur_r1 = 0, cur_c1 = 0, cur_m1 = 0, cur_s1 = 0, cur_d1 = 0;
	int next_r1 = 0, next_c1 = 0;
	while (q.size()) {
		tie(cur_r1, cur_c1, cur_m1, cur_s1, cur_d1) = q.front();
		q.pop();

		// �⺻ format�� ����.  
		// next_r1 = cur_r1 + (dr[cur_d1] * cur_s1);
		// next_c1 = cur_c1 + (dc[cur_d1] * cur_s1);
	
		// ����! -> �迭�� �����̶�� �����ؾ���. 
		// ---------------------------- �ε��� �����ֱ� -------------------------------
		int diff_row = dr[cur_d1] * cur_s1;
		int diff_col = dc[cur_d1] * cur_s1;

		if (diff_row > 0) {
			diff_row = diff_row % N;
			next_r1 = cur_r1 + diff_row;
		}
		else if (diff_row < 0) {
			diff_row = abs(diff_row) % N;
			next_r1 = cur_r1 - diff_row;
		}
		else if (diff_row == 0) {
			next_r1 = cur_r1;
		}

		if (diff_col > 0) {
			diff_col = diff_col % N;
			next_c1 = cur_c1 + diff_col;
		}
		else if (diff_col < 0) {
			diff_col = abs(diff_col) % N;
			next_c1 = cur_c1 - diff_col;
		}
		else if (diff_col == 0) {
			next_c1 = cur_c1;
		}

		if (next_r1 < 1) next_r1 = next_r1 + N;
		else if (next_r1 > N) next_r1 = next_r1 - N;
		if (next_c1 < 1) next_c1 = next_c1 + N;
		else if (next_c1 > N) next_c1 = next_c1 - N;
		// ----------------------------�ε��� �����ֱ�-------------------------------

		// ������Ʈ ����.
		grid[next_r1][next_c1].push({ next_r1, next_c1, cur_m1, cur_s1, cur_d1 });

	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int r = 0, c = 0, m = 0, s = 0, d = 0;
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		cin >> r >> c >> m >> s >> d;
		q.push({ r, c, m, s, d });
	}

	while (K--) {
		move_fireball();
		check_fireball();
	}

	// ��� ���
	while (q.size()) {
		tie(r, c, m, s, d) = q.front();
		q.pop();
		res += m;
	}
	cout << res << "\n";
	return 0;
}