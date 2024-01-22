//https://www.acmicpc.net/problem/13913

#include <iostream>
#include <algorithm>
#include <queue>

#define max_idx 100004
using namespace std;

int n = 0, k = 0, res_min_sec = 0;
// �湮 �迭�� pair<int, char>�� �ּҰŸ��� �� ���� � �������� �°����� ������ �����.
pair<int, char> visited[max_idx]; // first : �ּ� �Ÿ�, second : ������ � ������� �Դ���.

// ���� ������ a, b, c�� �����ؼ� a�� +1, b�� -1, c�� *2�� ���� �� �����̴ٶ�� ���� ��Ÿ����.
void check_visited(int cur_x, int next_x, int i, queue<int> &q) {
	char prev_cal = ' ';
	if (i == 0) prev_cal = 'a';
	else if (i == 1) prev_cal = 'b';
	else if (i == 2) prev_cal = 'c';

	if (next_x >= 0 && next_x < max_idx) {
		// �ѹ� �湮�ߴ� ���� ���̻� �湮���� �����Ƿ� a, b, c�� ���ļ� ��������ų� �ϴ� ���� ����.
		// �׷��⿡ �ش� a, b, c ������ ���� �������ϸ� �ּ� �Ÿ��� �� ��θ� �� �� �ִ�.
		if (visited[next_x].first == 0) {
			visited[next_x].first = visited[cur_x].first + 1;	// �ּ� �Ÿ�
			visited[next_x].second = prev_cal;	// �ּ� �Ÿ�

			q.push(next_x);
		}
	}
}
void solve_bfs(int x) {
	visited[x] = { 1, 0 }; // �ʱ� �湮ó��
	const int dx[3] = { 1, -1, 99 };	// 99�� *2�� ���̴� �뵵.
	queue<int> q;
	q.push(x);

	bool break_flag = false;
	int cur_x = 0, next_x = 0;
	while (q.size()) {
		cur_x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (i == 2) { next_x = 2 * cur_x; }
			else { next_x = cur_x + dx[i]; }

			check_visited(cur_x, next_x, i, q);
			
			if (next_x == k) {
				res_min_sec = visited[k].first - 1;
				break_flag = true;
				break;
			}
		}
		if (break_flag == true) break;
	}
	return;
}
// ���� ������ a, b, c�� �����ؼ� a�� +1, b�� -1, c�� *2�� ���� �� �����̱⿡
// a�� ���� �ݴ��� -1��,
// b�� ���� �ݴ��� +1��,
// c�� ���� �ݴ��� /2�� ���ش�.
void detect_path(int idx) {
	vector<int> path;
	path.push_back(idx);
	// visited[idx].first != 1 �� �� ó�� ������ ��ġ�� �湮ó���� 1�� �Ǿ��ֱ� ������ 1�� ���� ���̴�.
	while (visited[idx].first != 1) {
		if (visited[idx].second == 'a') idx = idx - 1;
		else if (visited[idx].second == 'b') idx = idx + 1;
		else if (visited[idx].second == 'c') idx = idx / 2;

		path.push_back(idx);
	}

	// �������� ���Ϳ� ���������Ƿ� �������� ����Ѵ�. 
	for (int i = path.size() - 1; i >= 0;i--) {
		cout << path[i] << " ";
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;	// n : ���� , k : ���� ��ġ 
	solve_bfs(n);
	cout << res_min_sec << "\n";
	detect_path(k); // ��� ���. 
	return 0;
}