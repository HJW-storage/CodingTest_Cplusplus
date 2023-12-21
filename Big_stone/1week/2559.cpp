#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n = 0, k = 0;
int num_max = -(1e7 + 1); // ���� ������ �ߺ��� ���� ������ ������ �� �������� ����������Ѵ�. 

// �ִ밪�� ã�� ������ ������ ��� ���� �־��� ��Ȳ���� �� ���� �ּڰ����� �����Ͽ� max()�Լ��� ���� ���ϸ�
// ���� ã�ư���. 

int main() {
	cin >> n >> k;
	vector<int> numv(n+1, 0);	// ���� �Է� ����
	vector<int> sumv(n + 1, 0);	// ������ ���� ����
	vector<int> ksumv(n + 1, 0); // k�� ���� ��¥ �� ���� ����

	for (int i = 1; i <= n; i++) {
		cin >> numv[i];
		sumv[i] = numv[i] + sumv[i - 1];	// ������ ���ϱ�
	}

	for (int i = k; i <= n; i++) {
		ksumv[i] = sumv[i] - sumv[i - k];
		num_max = max(num_max, ksumv[i]);
	}

	cout << num_max << "\n";

	return 0;
}