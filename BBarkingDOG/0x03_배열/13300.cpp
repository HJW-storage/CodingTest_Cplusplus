// https://www.acmicpc.net/problem/13300

// 1. �ʵ��б��� 1~6�г������.
// 2. 2���� �迭�� �г�� ������ �����ؼ� �л����� ī�����Ѵ�.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int stu_arr[2][7] = { 0, };
	int n = 0, k = 0, gender = 0, grade = 0, res = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> gender >> grade;
		stu_arr[gender][grade]++;	// �л��� ī����
		}

	// ��� ����
	//for (int i = 0; i <= 1; i++) { // ����
	//	for (int j = 1; j <= 6; j++) { // �г�
	//		cout << stu_arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	// ���л��� ���л�����, ���л��� ���л����� ���� �����ؾ� �Ѵ�. 
	// ���� �� �濡�� ���� �г��� �л����� �����ؾ� �Ѵ�.
	// Ǯ�� ���� ����
	for (int i = 0; i <= 1; i++) { // ����
		for (int j = 1; j <= 6; j++) { // �г�
			if (stu_arr[i][j] == 0) {
				continue;
			}
			else if (stu_arr[i][j] % k == 0) {
				res += stu_arr[i][j] / k;
			}
			else {
				res += stu_arr[i][j] / k;
				res += 1;  // ���� �л��� �����ϴ� �� �߰��� 1�� �� ����.
			}
		}
	}
	cout << res << "\n";
	return 0;
}