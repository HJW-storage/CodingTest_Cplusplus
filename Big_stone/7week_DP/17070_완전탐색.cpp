// https://www.acmicpc.net/problem/17070

// ���� Ž������ ����. 
// �ִ� �ð� ���⵵ 3^16 ~= 5,000,000 �̹Ƿ� ����Ž�� ����. 
#include <iostream>
#include <algorithm>

using namespace std;

int n = 0, grid[20][20] = { 0, }, res = 0;

// 0 : ����, 2 : ����   /    1 : �밢��
bool check(int row, int col, int dir) {
	if (dir == 0 || dir == 2) {
		// ���� �ƴ϶��
		if (grid[row][col] == 0) return true;
	}
	else if (dir == 1) {
		if (grid[row][col] == 0 && grid[row - 1][col] == 0 && grid[row][col - 1] == 0) return true;
	}
	return false;
}

void go(int row, int col, int dir) {
	// Ż�� ����
	if (row == n && col == n) {
		res++;
		return;
	}
	if (row > n || col > n) return;

	// ���� ����
	if (dir == 0) { // ���� ���⿡�� �� �� �ִ� ����� �� : 2����
		if (check(row, col + 1, 0)) go(row, col + 1, 0);
		if (check(row + 1, col + 1, 1)) go(row + 1, col + 1, 1);
	}
	else if (dir == 2) { // ���� ���⿡�� �� �� �ִ� ����� �� : 2����
		if (check(row + 1, col, 2)) go(row + 1, col, 2);
		if (check(row + 1, col + 1, 1)) go(row + 1, col + 1, 1);
	}
	else if (dir == 1) { // �밢�� ���⿡�� �� �� �ִ� ����� �� : 3����
		if (check(row, col + 1, 0)) go(row, col + 1, 0);
		if (check(row + 1, col, 2)) go(row + 1, col, 2);
		if (check(row + 1, col + 1, 1)) go(row + 1, col + 1, 1);
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}
	go(1, 2, 0);
	cout << res << "\n";
	return 0;
}