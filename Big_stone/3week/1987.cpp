// https://www.acmicpc.net/problem/1987

#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;
int n = 0, m = 0, result = 1;
char grid[24][24];
int visited[24][24];
map<char, int> mp;
//unordered_map<char, int> mp;

const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };
void go(int row, int col, int dis) {
	result = max(result, dis);
	if (result == n * m || result == 26) return;

	for (int i = 0; i < 4; i++) {
		int next_row = row + dr[i];
		int next_col = col + dc[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			// ó�� ���� ��. 

			// map�� ������ �ϴ��� �ڵ����� 0�� ä������. �ѹ��� �湮���� ���ĺ��� ���.
			if (mp[grid[next_row][next_col]] == 0) {
				mp[grid[next_row][next_col]] = 1; // map �� �߰��ϱ�.
				go(next_row, next_col, dis + 1);

				// erase�� ����� �ð��ʰ��� ����.... why? : erase�� ����ϸ� �Լ��⿡ ���̺귯������ ã�ƿ;��Ѵ�.
				// ���� O(logN)�̶� �Լ��� �������ϱ� �̹������� �� �����ɸ���.
				// mp.erase(grid[next_row][next_col]); // �����ָ� ���´�.

				// map���� key �� : grid[next_row][next_col] ã�ƾ� �ϹǷ� �ð� ���⵵�� O(logN)�̴�.
				// �̰��� erase�� �޸� ���̺귯������ �Լ��� ã�ƿ��°��� �ƴϹǷ� ���� �ð� ���⵵���� �̹��ϰ� ������.
				mp[grid[next_row][next_col]] = 0; // �����ָ� ���´�.

				// ���� ���� ���� map��� unordered_map�� ����ϸ� ����, Ž���� O(1)�� �ð��̴�.
				// �׷���, �־��� ���� O(N)�� �ɸ���. 
				// �ش繮������ unordered_map�����ϴ� �ð��ʰ��� ���µ�,,,, �־��� ��쿡 ��������....
				// �׷���, unordered_map������ erase �Լ��� ���� �ð� ���⵵�� O(logN)�̴�. 

				// -> �����, �ᱹ map�̳� unordered_map �������ϰ� �ǵ� �ڵ����� �⺻�� 0(int), false(bool) ���� �߰��Ǳ⿡
				// erase�� ����� �� ���ٴ� mp[grid[next_row][next_col]] = 0; ���� value ���� �����ؼ� �湮, �̹湮 ó���� ��������.
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	mp[grid[0][0]] = 1; // �ʱ� �湮ó�� 
	go(0, 0, 1);
	cout << result << "\n";

	return 0;
}