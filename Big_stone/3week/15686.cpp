// https://www.acmicpc.net/problem/15686

// �ش� �ڵ�� �ð��ʰ��� ����. 
// �ų��� �ڵ� ���غ��� ä���ϴ� �ð��ʰ��� ���� �˰����� �ٽ� ­��. 
// �� �ð� �ʰ����� ���� ����غ��� ����غ���.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m, temp;
int chicken_street = 1000000;	// �ּڰ��� ���ؾ��ϹǷ� �ʱⰪ�� ū������ ���Ѵ�.
const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

vector<vector<int>> grid(54, vector<int>(54, 0));
vector<vector<int>> visited(54, vector<int>(54, 0));
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int bfs(int row, int col) {
	// �׽�Ʈ ���̽����� �˻��ؾ��ϱ⿡ �湮ó�� ���� �ʱ�ȭ �����־�� �Ѵ�.
	fill(visited.begin(), visited.end(), vector<int>(54, 0));
	visited[row][col] = 1;	// �湮ó��
	queue<pair<int, int>> q;
	q.push({ row, col });
	while (q.size()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + dr[i];
			int next_col = cur_col + dc[i];
			if (next_row >= 1 && next_row <= n && next_col >= 1 && next_col <= n) {
				// ġŲ�� 2�� ���̸� �Ÿ� ��ȯ�ϰ� ����
				if (grid[next_row][next_col] == 2) {
					return visited[cur_row][cur_col]; 
				}

				// �湮 �˻縸 ���ָ� �ȴ�.
				if (visited[next_row][next_col] == 0) {
					visited[next_row][next_col] = visited[cur_row][cur_col] + 1;	// �ִܰŸ�
					q.push({ next_row, next_col });
				}
			}
		}
	}
}
// nCr ���ձ��ϱ� -> �ε����� �������� ���� ��. 
// �ε����� �̾ƾ� �ߺ��Ǵ� ���� �־����� ��� ������ �����ϴ�.
void combi(int start, int chicken_housecnt, vector<int>& b) {
	if (b.size() == m) {
		int dis = 0;
		// �ʱ�ȭ �߿��ϴ�. ��ȭ��Ų �� �������� �ٽ� ��ȭ��Ű�� ������.
		for (int it : b) {
			grid[chicken[it].first][chicken[it].second] = 2;	// ġŲ�� ǥ��
		}

		// bfs ���� �����Ѵ�. 
		for (pair<int, int> it : house) {
			dis += bfs(it.first, it.second);
		}

		// �ּ� ġ�� �Ÿ��� ���ϴ� ���̹Ƿ� �� ���� ���� ���Ͽ� ����.
		chicken_street = min(chicken_street, dis);

		for (int it : b) {
			grid[chicken[it].first][chicken[it].second] = 0;	// ���� �����ϰ� ������
		}
		return;
	}

	for (int i = start + 1; i < chicken_housecnt; i++) {
		b.push_back(i);
		combi(i, chicken_housecnt, b);
		b.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	// ���� ���� �Է� �ޱ�
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			// ġŲ�� �ε��� ������ ���Ϳ� ��� grid���� ǥ������ �ʴ´�. 
			// ���� ������ �̰� ���� ġŲ������ �ٲٴ� ����� �� ���Ѱ� ���Ƽ� �̷��� ����.
			if (temp == 2) {
				chicken.push_back({ i, j });	// ġŲ�� {row, col} �߰�
				continue;
			}

			if (temp == 1) house.push_back({ i, j });	// ������ {row, col} �߰�
			grid[i][j] = temp;
		}
	}

	int chicken_housecnt = chicken.size();
	vector<int> b;
	combi(-1, chicken_housecnt, b);

	cout << chicken_street << "\n";
	return 0;
}