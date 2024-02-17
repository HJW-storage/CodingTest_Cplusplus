// https://www.acmicpc.net/problem/2960
// "�����佺�׳׽��� ü" 

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n = 0, k = 0, Eratos[1004] = { 0, };

int solve_eratos() {
	int cnt = 1, res = 0;
	for (int i = 2; i <= n; i++) {
		if (Eratos[i]) continue; // ������ ������ ����� ����
		for (int j = i; j <= n; j += i) {
			if (Eratos[j]) continue;
			if (cnt == k) res = j;
			Eratos[j] = cnt++; // �Ҽ��� �ƴϸ� 1�� ä���.
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	cout << solve_eratos() << "\n";
	return 0;
}