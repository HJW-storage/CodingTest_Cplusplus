//https://www.acmicpc.net/problem/10988

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string alphabet_str = "";

int main() {
	cin >> alphabet_str;

	// �׳� �ܼ��� temp_str = alphabet_str; �� �ص��ȴ�.
	// ���� ������ ��, temp_str�� �����ؾ��� ��, ���̰� �¾ƾ� �Ѵ�. 
	string temp_str;
	for (char it : alphabet_str) {
		temp_str.push_back(it);
	}

	// ���� ����
	copy(alphabet_str.begin(), alphabet_str.end(), temp_str.begin());

	// �����Ѱ� ������
	reverse(temp_str.begin(), temp_str.end());

	// �˻�
	if (alphabet_str == temp_str) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}

	return 0;
}