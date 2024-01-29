// https://www.acmicpc.net/problem/1189

// 1. dfs�� ���� Ž��
// 2. ���ǿ� ���� ����(�Ѽ��� ��)���� ���ݱ����� �Ÿ��� k�� �ƴ϶�� ���� ���ϰ� ��ȸ�ϰ� �Ѵ�.
// 3. ����, k�� �Ÿ��� ���� ����� ���� ���ٸ� 0�� ����ϰ� �Ѵ�.

#include <iostream>
#include <algorithm>

using namespace std;
int n = 0, m = 0, k = 0, res = 0, dis = 1; // �ʱ� ������ ���� �Ÿ� 1�� ����ϹǷ� �ʱⰪ�� 1�� �Ѵ�..
char way[10][10];
int visited[10][10];
const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };

void solve_dfs(int row, int col) {
	visited[row][col] = 1; // �湮ó��

	// ��� ����
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "���� dis : " << dis << " , ���� res : " << res << "\n";*/

	for (int i = 0; i < 4; i++) {
		int next_row = row + dr[i];
		int next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			if (way[next_row][next_col] != 'T' && visited[next_row][next_col] == 0) {
				if (next_row == 0 && next_col == m - 1) {	// ������. �Ÿ� k���� �˻�
					if (dis + 1 != k) {	// �Ÿ� K���� �� ª�� �ð����� �����ϴ� ���� ���� ���
						continue;
					}
					else if(dis + 1 == k){	// ���� �������� ��� ī���� +1 ���ְ� dfs �������� ����.
						res++; // ����� +1.
						continue;
					}
				}
				else {
					if (dis + 1 >= k) {	// �� ���� ������ �Ÿ� k�� �̹� �Ǿ� ���� �ʰ��� ���¸� �����ϴ� ���.
						continue;
					}
				}
				dis++;
				solve_dfs(next_row, next_col);
				dis--; // ����
				visited[next_row][next_col] = 0; // ���� 
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> way[i][j];
		}
	}
	solve_dfs(n - 1, 0);

	cout << res << "\n";
	return 0;
}