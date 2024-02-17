// https://www.acmicpc.net/problem/1929
// "�����佺�׳׽��� ü" �˰��� Ȱ�빮��.

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n = 0, m = 0, Sosu[1'000'004] = { 0, };

// 1�� �Ҽ��� �ƴϴ�!! 
void print_sosu() {
	Sosu[1] = 1; // 1�� �Ҽ��� �ƴ�.

	// for (int i = 2; i*i <= n; i++)
	for (int i = 2; i <= sqrt(n); i++) {
		// �̹� ������ ����� ���� ���� ������ �ǹ��̹Ƿ� ���� ���� ����Ѵ�.
		if (Sosu[i] != 0) continue;
		for (int j = i; j <= n; j += i) {
			// �ڱ� �ڽ��� �Ҽ��̱⿡ ���� ���� ����. 
			if (j == i) continue;
			Sosu[j] = 1; // �Ҽ��� �ƴ��� ǥ��. 
		}
	}

	// ����(�Ҽ�) ���
	for (int k = m; k <= n; k++) {
		if (Sosu[k] == 1) continue;
		cout << k << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> m >> n;
	print_sosu();
	return 0;
}