// https://www.acmicpc.net/problem/14497
// Ǯ�̽ð� 1�ð�. 

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n = 0, m = 0, junan_row = 0, junan_col = 0, dest_row = 0, dest_col = 0;
char grid[304][304];
int visited[304][304];
vector<pair<int, int>> tmp_v;

int solve_bfs(int row, int col) {
	visited[row][col] = 1; // �ʱ� �湮ó��
	const int dr[4] = {0, 1, 0, -1};
	const int dc[4] = {1, 0, -1, 0};
	queue<pair<int, int>> q;
	q.push({row, col});

	int result = 0;
	int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
	bool stop_flag = false;

	// �ܼ��� ���� ����� �Ÿ��� Ž���ϴ°� �ƴϴ�. 
	// �� ���� ģ���� �����߷����ϹǷ� �����¿� '0'�� ���� ť�� ��� ä��鼭 
	// '1'�� ���� ť�� ä���� �����鼭, �߰��� �������� bfs �����ϴ� ��ġ�� �����ϱ� ���� �ӽ� ����(tmp_v)�� �����Ѵ�. 
	// ��, �湮ó���� ��� ���� ��.
	// �׷���, �湮ó���� ���ֱ� ������ ģ������ �� �㿡 '1' �׵θ��� �����鼭 '0'�� �� Ž���Ͽ� ť�� ��⶧���� while(q.size())�� ����ȴ�. 
	while (1) {
		tmp_v.clear(); // �ʱ�ȭ

		// Ż�� ���� ����ؾ��Ѵ�.
		while (q.size()) {
			cur_row = q.front().first;
			cur_col = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				next_row = cur_row + dr[i];
				next_col = cur_col + dc[i];

				// Ż�� ����. ���ڹ� �߰�!!
				if (next_row == (dest_row - 1) && next_col == (dest_col - 1)) {
					stop_flag = true;
					break;
				}

				// ���� ����
				if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
					// '0'�� ���� �湮ó���ϰ� q ť�� ä���
					if (grid[next_row][next_col] == '0' && visited[next_row][next_col] == 0) {
						visited[next_row][next_col] = 1; // �湮ó��
						q.push({next_row, next_col});
					}
					// '1'�� ���� �湮ó���� ���� ��. ť�� ä���� �ʴ´�. 
					else if (grid[next_row][next_col] == '1' && visited[next_row][next_col] == 0) {
						visited[next_row][next_col] = 1; // �湮ó��
						tmp_v.push_back({ next_row, next_col }); // ������ bfs ������ ��ġ�� �����ϱ� ���� �ӽ� ���Ϳ� ä���.
					}
				}
			}
			if (stop_flag == true) break; // Ż��
		}
		if (stop_flag == true) break; // Ż��

		// ���� Ž�� �Ϸ��� ��, ť�� ��� �ִ� ����. �����¿�� �� �� �ִ� 0�� �� ���ٿ� ����.
		// ���Ϳ� ����� ��ǥ�� ť�� �ְ�, grid ��ǥ '0'���� �ٲ��ֱ�. 
		for (pair<int, int> it : tmp_v) {
			q.push({ it.first, it.second }); // ���Ϳ� ����� ��ǥ�� ť�� �ְ�
			grid[it.first][it.second] = '0'; // grid ��ǥ '0'���� �ٲ��ֱ�.
		}
		result++;
	}
	return result + 1;	// ������ result++ ���� Ż�������Ƿ� +1�� ���ش�. 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ��ĭ ���� �Էµ����� �� �Է� �ޱ�
	cin >> n >> m;
	cin >> junan_row >> junan_col >> dest_row >> dest_col;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			grid[i][j] = temp[j];
		}
	}
	
	// �ֳ��̿� ���ڹ� ��ġ�� 1,1 �� ���������� ��ǥ�̹Ƿ� 
	// grid�� ���߱� ���� -1�� ������. 
	int result_cnt = solve_bfs(junan_row - 1, junan_col - 1);
	cout << result_cnt << "\n";

	return 0;
}