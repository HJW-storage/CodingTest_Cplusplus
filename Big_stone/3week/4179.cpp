// https://www.acmicpc.net/problem/4179

// bfs�� ����ϴµ� �����̿� ���� ���ÿ� bfs �ϸ� ���ؾ��Ѵ�. 
// �����ڸ� �ε��� 0�� n,m�� �������� �Ұ� ��ġ�� ������ Ż�� / �ƴϸ� Ż�� �Ұ�.
// ���� ���� �����̰�, �״����� �����̸� �����δ�.
// �����̰� bfs�� ��������, next_row�� next_col�� �����ڸ� �ε��� ���� Ȯ���ؼ� Ż�� / �Ұ� �Ǻ�.

// ���⵵ ����غ���. 

#include <iostream>
#include <algorithm>
#include <vector> 
#include <queue>

using namespace std;
int n = 0, m = 0, cnt = 1;
const int dr[4] = {0, 1, 0, -1};				
const int dc[4] = {1, 0, -1, 0};

vector<vector<char>> grid(1004, vector<char>(1004, '0')); // �޸� �ִ� 1000 X 1000 X 1 = 1,000,000 = 1MB
vector<vector<int>> fire_visited(1004, vector<int>(1004, 0)); // 4MB
vector<vector<int>> visited(1004, vector<int>(1004, 0)); // 4MB

// ť�� ����.
queue<pair<int, int>> fire;	// �޸� �ִ� 1000 X 1000 X 8 = 8,000,000 = 8MB
queue<pair<int, int>> jihun; // 8MB

void fire_bfs(int row, int col) {
	int next_row = 0, next_col = 0;
	fire_visited[row][col] = 1; // �湮ó��
	for (int i = 0; i < 4; i++) {
		next_row = row + dr[i];
		next_col = col + dc[i];
		if(next_row >= 0 && next_row <n && next_col >= 0 && next_col < m){
			// if (grid[next_row][next_col] != '#') ó���� �ش� ���Ǹ� ����ߴ��� �޸� �ʰ�..... 
			// fire_visited �湮ó�� ���� �����ϸ� ť�� �ߺ��Ǵ� ��ǥ�� ��� ���� �޸� �ʰ�.
			if (grid[next_row][next_col] != '#' && fire_visited[next_row][next_col] == 0) {
				grid[next_row][next_col] = 'F';
				fire_visited[next_row][next_col] = 1; // �湮ó��
				fire.push({ next_row, next_col });
			}
		}
	}
}
void jihun_bfs(int row, int col) {
	int next_row = 0, next_col = 0;
	for (int i = 0; i < 4; i++) {
		next_row = row + dr[i];
		next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			if (grid[next_row][next_col] == '.') {
				grid[next_row][next_col] = 'J';
				jihun.push({ next_row, next_col });
				visited[next_row][next_col] = visited[row][col] + 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �Է� �ޱ�
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			grid[i][j] = temp[j];
			if (grid[i][j] == 'F') {
				fire.push({ i, j });
			}
			else if (grid[i][j] == 'J') {
				jihun.push({ i, j });
				visited[i][j] = 1; // �ʱ� ��ġ �湮ó��
			}
			else { ; }
		}
	}

	int fire_size = 0, fire_row = 0, fire_col = 0, jihun_size = 0, jihun_row = 0, jihun_col = 0;
	bool talchul = false;
	while(jihun.size() != 0){
		// �� �̵� ���� �ۼ�
		fire_size = fire.size();
		for (int i = 0; i < fire_size; i++) {
			fire_row = fire.front().first;
			fire_col = fire.front().second;
			fire.pop();	
			fire_bfs(fire_row, fire_col);
		}

		// ������ �̵� ���� �ۼ�
		jihun_size = jihun.size();
		for (int i = 0; i < jihun_size; i++) {
			jihun_row = jihun.front().first;
			jihun_col = jihun.front().second;
			if (jihun_row == 0 || jihun_row == n - 1 || jihun_col == 0 || jihun_col == m - 1) {
				talchul = true;
				break;
			}
			jihun.pop();
			jihun_bfs(jihun_row, jihun_col);
		}

		if (talchul == true) break;
	}

	if (talchul == true) {
		cout << visited[jihun_row][jihun_col] << "\n";
		//cout << cnt << "\n";
	}
	else {
		cout << "IMPOSSIBLE" << "\n";
	}
	return 0;
}