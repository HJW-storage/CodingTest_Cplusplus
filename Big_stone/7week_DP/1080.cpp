// https://www.acmicpc.net/problem/1080

#include <iostream>
#include <algorithm>

using namespace std;

int n = 0, m = 0, grid_A[54][54] = { 0, }, grid_B[54][54] = { 0, }, res = 0;

void reverse_matrix3by3(int a, int b) {
	// 3x3 �κ� ��� ���� ������. 
	for (int i = a; i <= a + 2; i++) {
		for (int j = b; j <= b + 2; j++) {
			grid_A[i][j] = 1 - grid_A[i][j];
		}
	}
	return;
}
void solve_greedy() {
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (grid_A[i][j] == grid_B[i][j]) continue;
			reverse_matrix3by3(i, j);
			res++;
		}
	}
	return;
}
bool compare_matrix() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid_A[i][j] != grid_B[i][j]) return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	// ��� A �Է�
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			grid_A[i][j] = tmp[j] - '0';
		}
	}
	// ��� B �Է�
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			grid_B[i][j] = tmp[j] - '0';
		}
	}

	solve_greedy();
	// ��� ���
	// res �ʱⰪ = 0 ���� ����. 
	// ���� ��� A�� B�� ������ true ��ȯ�ϰ� res ����̹Ƿ� 0�� ���. 
	if (compare_matrix()) {
		cout << res << "\n";
	}
	else {
		cout << "-1" << "\n";
	}

	return 0;
}

// ���� ���� 
// ��� ������ ������ 3x3 �����θ� �����Ⱑ ������ ���̴�.

// test-1 (������ ���� ���ϹǷ� a�� b�� �� �� ����. -1 ���.)
/*
	1 1
	1
	0
	answer : -1
*/

// test-2 (�ش� ��쿡�� ������ ������ �ʿ����. a�� b�� �̱⿡ 0 ���. )
/*
	1 1
	1
	1
	answer : 0
*/