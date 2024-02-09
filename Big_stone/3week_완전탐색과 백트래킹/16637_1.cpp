// https://www.acmicpc.net/problem/16637

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int idx[10] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 };
int n = 0;
string susik;
vector<int> result;
// ���� ����
// �������� ��ȣ�� �� ����� ���� �̾Ƽ� ��ȣ�� �߰��� ���� �����
// ��ȣ�� �Ǿ� �ִ� ������ ��ȣ ���� ����ؼ� ���ο� string ���Ϳ� �����ϱ�.
// ����, ������� ����ϱ�.

// (1) ���� �����ϱ�
void printV(vector<int>& b) {
	for (auto it : b) {
		cout << it << " ";
	}
	cout << "\n";
	return;
}
int oper(int a, char op, int b) {
	if (op == '+') { return a + b; }
	else if (op == '-') { return a - b; }
	else if (op == '*') { return a * b; }
	else { ; }
}
void cal(string& addgaulho) {
	vector<string> final_cal;
	for (int i = 0; i < addgaulho.length(); i++) {
		if (addgaulho[i] == '(') {
			// char -> int �� �ٲٱ�
			int gaulho_cal = oper(addgaulho[i + 1] - '0', addgaulho[i + 2], addgaulho[i + 3] - '0');
			// int -> string�� �ٲٱ�
			final_cal.push_back(to_string(gaulho_cal));
			i += 4;
		}
		else {
			// char -> string ����
			final_cal.push_back(string(1, addgaulho[i]));
		}
	}

	// string ���Ϳ��� ���� ��ȣ�� ���Ǿ� �� ���� �� �ִ�.
	int res_tmp = stoi(final_cal[0]);	// string -> int�� 
	for (int i = 0; i < final_cal.size(); i++) {
		if (final_cal[i] == "+") {
			res_tmp = res_tmp + stoi(final_cal[i + 1]);
			i++;
			continue;
		}
		else if (final_cal[i] == "-") {
			res_tmp = res_tmp - stoi(final_cal[i + 1]);
			i++;
			continue;
		}
		else if (final_cal[i] == "*") {
			res_tmp = res_tmp * stoi(final_cal[i + 1]);
			i++;
			continue;
		}
	}
	result.push_back(res_tmp);
	return;
}
void combi(int start, int n, int r, vector<int>& b) {
	// ���� ���
	if (b.size() == r) {
		//printV(b);
		// ���� ó��
		int prev_it = 1000;
		bool except_flag = false;
		for (int it : b) {
			if (it - prev_it == 1) {
				except_flag = true; // ���� ��Ȳ�� �ɸ�. ����. 
			}
			prev_it = it;	// prev �� ����. 
		}

		if (except_flag == false) {
			// ��ȣ �����ϱ�.
			string tmp = susik;
			int cnt = 0;
			for (int it : b) {
				tmp.insert(idx[it] + cnt, "(");
				cnt++;
				tmp.insert(idx[it] + 3 + cnt, ")");
				cnt++;
			}
			//cout << "��ȣ �߰� : " << tmp << "\n";

			// ����ϱ�
			cal(tmp);
		}
		return;
	}

	for (int i = start + 1; i < n; i++) {
		b.push_back(i);
		combi(i, n, r, b);
		b.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> susik;
	int n_len = n / 2;
	// n >= 5 �̻��� ��
	int res_o = susik[0] - '0';
	for (int i = 0; i < n; i++) {
		if (susik[i] == '+') {
			res_o = res_o + (susik[i + 1] - '0');
			i++;
			continue;
		}
		else if (susik[i] == '-') {
			res_o = res_o - (susik[i + 1] - '0');
			i++;
			continue;
		}
		else if (susik[i] == '*') {
			res_o = res_o * (susik[i + 1] - '0');
			i++;
			continue;
		}
	}
	result.push_back(res_o);	// ��ȣ ���� ���ڷ� �� ����� ���. �ش� ����, n=1�� ���� ok. 

	vector<int> b;
	for (int i = 1; i <= n_len; i++) {
		combi(-1, n_len, i, b);
	}

	// �ִ� ���
	sort(result.begin(), result.end(), greater<int>());
	cout << result[0] << "\n";
	return 0;
}