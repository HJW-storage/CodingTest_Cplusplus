// https://www.acmicpc.net/problem/2309
// ������ �̿��� Ǯ��. ��, �ش� ������ ���� �����⿡ �ð��� �����ο��� ����� �� �־���. 
// algorithm ������Ͽ��� �����ϴ� next_permutation �Լ��� ����Ͽ� Ǯ��. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v_height(9, 0); // 9�� Ű ���� ���� 0���� �ʱ�ȭ

	for (int i = 0; i < 9; i++) {
		cin >> v_height[i];	// Ű �Է�
	}

	// next_permutation ������ ����ϱ� ���ؼ��� �ݵ�� �������� ������ ����Ǿ�� �Ѵ�!!!
	sort(v_height.begin(), v_height.end());

	do {
		int seven_heightSum = 0;
		for (int i = 0; i < 7; i++) {
			seven_heightSum += v_height[i];
		}
		if (seven_heightSum == 100) {
			for (int i = 0; i < 7; i++) {
				cout << v_height[i] << "\n";
			}
			break;
		}
	} while (next_permutation(v_height.begin(), v_height.end()));

	return 0;
}