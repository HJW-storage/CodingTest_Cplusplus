#include <iostream>
#include <algorithm>

using namespace std;
string ROT13_str;
string ROT13_output;

#define BIG_A 65
#define BIG_Z 90
#define Small_a 97
#define Small_z 122

int main() {
	cin >> ROT13_str;

	// �ƽ�Ű �ڵ� A : 65 ~ Z : 90,	a : 97 ~ z : 122
	for (char it : ROT13_str) {
		// �빮���� ���
		if (65 <= int(it) <= 90) {
			int cmp = int(it) + 13;
			if (cmp > 90) {
				ROT13_output += char(65 + (cmp - 90 - 1));
			}
			else {
				ROT13_output += char(cmp);
			}
		}

		// �ҹ����� ���
		else if (97 <= int(it) <= 122) {
			int cmp = int(it) + 13;
			cout << cmp << "\n";
			if (cmp > 122) {
				ROT13_output += char(97 + (cmp - 122 - 1));
			}
			else {
				ROT13_output += char(cmp);
			}
		}

		// �� �̿��� ���� �׳� ���
		else {
			ROT13_output += it;
		}
	}

	cout << ROT13_output << "\n";

	return 0;
}