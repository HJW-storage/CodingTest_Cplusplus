// https://www.acmicpc.net/problem/2828

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0, j = 0, result = 0;
	cin >> n >> m;
	cin >> j;	// ����� ����

	// 1, m���� �ε��� ������ ���� ���� �Է¹޴� position�� ó���ϱ� �� �����ϱ� ����
	// �������� �Ÿ��� �ּڰ��� ���϶�� �Ͽ��⿡ ó���� �� �ε����� ����Ͽ� ������ �����ϴ°� ����.
	// ó�� �Ǵ� �� �ε��� �ϳ��� ������ �����ϱ⿡�� ��ƴ�. ������ �Ǳ�� ���ٵ� ����������. 
	int box_firstidx = 1;
	int box_endidx = m;

	for (int i = 0; i < j; i++) {
		int position = 0;
		cin >> position;

		// ���� ����
		if (box_firstidx <= position && box_endidx >= position) {
			continue;	// ���� �������� �ʴ´�.
		}
		else {
			if (position > box_endidx) {
				while (position != box_endidx) {
					// box �ε����� ó���� ���� ���� �̵��ϰ� �ǹǷ� �ݿ����ش�.
					box_endidx++;
					box_firstidx++;
					result++;
				}
			}
			else if (position < box_firstidx) {
				while (position != box_firstidx) {
					// box �ε����� ó���� ���� ���� �̵��ϰ� �ǹǷ� �ݿ����ش�.
					box_firstidx--;
					box_endidx--;
					result++;
				}
			}
			else { ; }
		}
	}

	cout << result << "\n";
	return 0;
}