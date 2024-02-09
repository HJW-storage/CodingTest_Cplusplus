// https://www.acmicpc.net/problem/9935

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string in_str, explosion_str, res;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> in_str;
	cin >> explosion_str;

	int in_len = in_str.length();
	int exp_len = explosion_str.length();
	
	// res ��� ���ڿ��� �Է� ���ڿ��� �ϳ��� ���Ѵ�.
	// ���ڿ��� ���̰� ���� ���ڿ� ���� �̻��� ��, ���κп� ���� ���ڿ��� �ִ��� �˻��Ѵ�.
	// ���� ���ڿ��� ������ erase �Լ��� Ȱ���ؼ� �����.
	for (int i = 0; i < in_len; i++) {
		res += in_str[i];
		int res_len = res.length();
		int tmp_len = exp_len;
		bool erase_flag = true;
		// ���� ���ڿ��� �ִ��� �˻��ϰ�, �ִٸ� ����� ����.
		if (res_len >= exp_len) {
			for (int j = 1; j <= exp_len; j++) {
				res_len--;
				tmp_len--;
				if (res[res_len] == explosion_str[tmp_len]) continue;
				erase_flag = false;
				break;
			}
			if (erase_flag) {
				res.erase(res.length() - exp_len, exp_len);
			}
		}
	}

	// str.substr() �Լ��� ����ϸ� �� �ڵ带 �����ϰ� ���� �� �ִ�.
	/*for (int i = 0; i < in_len; i++) {
		res += in_str[i];
		int res_len = res.length();
		if (res_len >= exp_len) {
			if (res.substr(res_len - exp_len, exp_len) == explosion_str) {
				res.erase(res_len - exp_len, exp_len);
			}
		}
	}*/

	if (res == "") cout << "FRULA" << "\n";
	else cout << res << "\n";

	// find, erase �Լ��� �ð��ʰ��̴�.
	//// �������� 
	//while (in_str.find(explosion_str) != string::npos) {
	//	int start = in_str.find(explosion_str);
	//	in_str.erase(start, exp_len);
	//}
	//if (in_str == "") cout << "FRULA" << "\n";
	//else cout << in_str << "\n";

	return 0;
}