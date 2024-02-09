// https://www.acmicpc.net/problem/9935

// stack�� Ȱ���� Ǯ��. 
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;
string in_str, explosion_str;
stack<char> stk;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> in_str;
	cin >> explosion_str;

	int in_len = in_str.length();
	int exp_len = explosion_str.length();

	// stack�� Ȱ��
	// stack�� top�� ���� ���ڿ��� �� ���ڶ� ���ٸ� ���� ���ڿ� ���� ��ŭ stack���� ���� ���ϰ�
	// �´ٸ� �����ϰ� �ƴ϶�� �ٽ� stack�� �־��ش�.
	// (����) ������ LIFO �����̱⿡ reverse �Լ��� ������ Ȱ���� ����Ѵ�.
	for (int i = 0; i < in_len; i++) {
		stk.push(in_str[i]);
		if (stk.size() >= exp_len && stk.top() == explosion_str[exp_len - 1]) {
			// ���� ���ڿ��� ������ �˻��ϱ�
			string tmp_str = "";
			for (int j = 1; j <= exp_len; j++) {
				tmp_str += stk.top();
				stk.pop();
			}
			// ���ÿ��� �� ���̹Ƿ� ������ ������ �ֱ⿡ reverse�� �ٽ� ������д�.
			reverse(tmp_str.begin(), tmp_str.end());
			if (tmp_str == explosion_str) { ; }
			else {
				// ���� ���ڿ��� �ƴϱ⿡ ���ÿ��� ���� ���ڿ� �ٽ� �־��ش�.
				for (char it : tmp_str) {
					stk.push(it);
				}
			}
		}
	}

	if (stk.size() == 0) cout << "FRULA";
	else {
		string res = "";
		while (stk.size()) {
			res += stk.top();
			stk.pop();
		}
		// ���ÿ��� �� ���̹Ƿ� ������ ������ �ֱ⿡ reverse�� �ٽ� ������д�.
		reverse(res.begin(), res.end());
		cout << res << "\n";
	}
	return 0;
}