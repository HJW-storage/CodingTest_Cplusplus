// https://www.acmicpc.net/problem/9375

// �������� ��������� Ǯ���ؾ� ���� ����. 
// ���� : a, b  -> a, b, ������ (2+1 ����)
// ���� : c, d  -> c, d, ������	(2+1 ����)
// ���� : e, f, g	-> e, f, g, ������	(3+1 ����)
// -> ����� ���� = ((2+1) * (2+1) * (3+1)) - 1   (��� ���Դ� ���� ����. ������� ���) 
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

typedef long long ll;

using namespace std;
int test = 0, n = 0;
string cloth_name, cloth_kind;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> n;
		map<string, int> cloth; // �׽�Ʈ ���̽����� map�� �ʱ��� �Ǿ�� �Է�.
		for (int j = 0; j < n; j++) {
			cin >> cloth_name >> cloth_kind;
			if (cloth[cloth_kind]) {
				cloth[cloth_kind]++;
			}
			else {
				cloth[cloth_kind] = 1;
			}
		}

		ll result_case = 1;
		for (auto pair : cloth) {
			result_case *= (ll(pair.second) + 1);
		}
		
		result_case = result_case - 1; // ��������� 1�� ���ش�.
		cout << result_case << "\n";
	}

	return 0;
}