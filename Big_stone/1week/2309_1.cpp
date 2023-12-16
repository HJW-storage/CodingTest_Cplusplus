// https://www.acmicpc.net/problem/2309

// �׳� �� �������� Ǯ����. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define person 9
#define set_height 100

int main() {
	vector<int> v_height;

	// 9 �������� Ű�� �Է¹޴´�.
	int sum_nine = 0;
	for (int i = 0; i < person; i++) {
		int in_height;
		cin >> in_height;
		sum_nine += in_height; // 9 ������ Ű�� ���� ���Ѵ�.
		v_height.push_back(in_height);
	}

	// �������� ����
	sort(v_height.begin(), v_height.end());

	bool stop_flag = false;
	// 2�� for���� ���� 2���� Ű�� �����ϸ� 7���� Ű�� ���� 100�� ��츦 ���Ѵ�.
	for (int i = 0; i < person; i++) {
		for (int j = i + 1; j < person; j++) {
			if (i == j) {
				continue; // �������� ����ó��
			}
			int temp_height = sum_nine;	// �ӽ� ������ �����ؼ� ���Ѵ�. 
			temp_height = sum_nine - v_height[i] - v_height[j];
			if (temp_height == set_height) {
				stop_flag = true;
				for (int k = 0; k < person; k++) {
					if (k == i || k == j) {
						continue;
					}
					cout << v_height[k] << "\n";
				}
				break;
			}
		}
		if (stop_flag) {
			break;
		}
	}

	return 0;
}