//https://www.acmicpc.net/problem/17071

#include <iostream>
#include <algorithm>
#include <queue>

#define max_idx 500004
using namespace std;

int subin_pos = 0, sister_pos = 0, res_min_sec = 0, turn = 1;
int visited[2][max_idx];	// Ȧ��, ¦���� �ش��ϴ� �湮 �迭 ����.
bool ok = false;

int solve_bfs(int x) {
	visited[0][x] = 1; // �ʱ� �湮ó��
	queue<int> q;
	q.push(x);

	while (q.size()) {
		sister_pos += turn;
		if (sister_pos > 500000) return -1;
		// �����̰� -1, +1�� �����Ƿ� ���ڸ��� �� �� �ִ�. 
		// ����, ���� ���� turn - 2 ��°�� �̸� ���� ��ġ�� �־��ٸ� ���� �� �ִ�.
		// �̰��� ǥ���ϰ��� visited �湮 �迭�� Ȧ��, ¦�� ������ ����.
		if (visited[turn % 2][sister_pos] != 0) {
			ok = true;
			break;
		}

		// bfs�� ���̸� �����ϴ� ��� q.size�� ���� for���� for���� ������.
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int cur_x = q.front();
			q.pop();
			for (int next_x : {cur_x + 1, cur_x - 1, 2 * cur_x}) {
				if (next_x >= 0 && next_x <= 500000) {
					if (visited[turn % 2][next_x] == 0) {
						visited[turn % 2][next_x] = visited[(turn + 1) % 2][cur_x] + 1;
						
						q.push(next_x);
						
						if (next_x == sister_pos) {
							ok = true;
							break;
						}
					}

				}
			}
			if (ok == true) break;
		}
		if (ok == true) break;
		turn++;
	}

	if (ok == true) { return turn; }
	else { return -1; }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> subin_pos >> sister_pos;	// n : ���� , k : ���� ��ġ 
	if (subin_pos == sister_pos) {
		cout << "0" << "\n";
	}
	else {
		int result = solve_bfs(subin_pos);
		cout << result << "\n";
	}
	return 0;
}