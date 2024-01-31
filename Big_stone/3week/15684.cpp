// https://www.acmicpc.net/problem/15684

#include <iostream>
#include <algorithm>
#include <vector>

#define max_n 987654321
using namespace std;

int n, m, h, res = max_n;
int game[31][11] = { 0, };

bool start_game(int start) {
	int cur_pos = start; // ��ٸ� ���ӿ����� ���� ��ȣ. 
	int tmp_depth = 1;
	while (tmp_depth != h + 1) {
		// ��ٸ��� ������ �̵��ϰ� ������ �Ʒ��� ��������. 
		// ��ٸ��� ���޾� ���� ���� ����. <- ���� ����
		if (game[tmp_depth][cur_pos]) cur_pos++;
		else if (game[tmp_depth][cur_pos - 1]) cur_pos--;
		tmp_depth++; // ��ٸ� �Ʒ��� �̵�
	}
	if (cur_pos == start) { return true; }
	else { return false; }
}
bool check() {
	bool tmp = true;
	for (int i = 1; i <= n; i++) {
		tmp = start_game(i);
		if (tmp == false) break;
	}
	return tmp;
}
void go(int here, int cnt) {
	// ���� ���
	if (cnt > 3 || cnt >= res) return;
	if (check()) {
		res = min(res, cnt);
		return;
	}

	for (int i = here; i <= h; i++) {
		for (int j = 1; j <= n - 1; j++) {
			if (game[i][j] || game[i][j + 1] || game[i][j-1]) { continue; }
			// ��ٸ� �׸��� (�湮ó��)
			game[i][j] = 1;
			go(i, cnt + 1);
			// ���� ����
			game[i][j] = 0;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// n : ���μ��� ����, m : ���� �׷����ִ� ���μ��� ����, h : ���μ��� ���� �� �ִ� ���� ����
	cin >> n >> m >> h;
	if (m == 0) {
		cout << "0" << "\n";
		return 0;
	}
	int row = 0, col = 0;
	for (int i = 0; i < m; i++) {
		cin >> row >> col;
		// ��ٸ� ��θ� 1�� ǥ���ؼ� �̾��ش�.
		game[row][col] = 1;
	}

	go(1, 0);
	if (res == max_n) cout << "-1" << "\n";
	else cout << res << "\n";

	return 0;
}