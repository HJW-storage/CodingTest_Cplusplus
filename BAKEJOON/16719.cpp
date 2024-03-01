// https://www.acmicpc.net/problem/16719
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string str;
int visited[104] = { 0, }, str_len = 0;;
vector<string> res_str;
vector<pair<int, string>> res;

bool check(int s_idx, int e_idx) {
	for (int i = s_idx; i < e_idx; i++) {
		if (visited[i] == 0) return false;
	}
	return true;
}

void go(int s_idx, int e_idx) {
	// test case 3���� �� ����.
	// ���� ������ ���� ���ĺ��� ã��, ���� ��ʹ� ã�� ���ĺ��� �����ʿ��� ����. 
	while (!check(s_idx, e_idx)) {
		int min_idx = 101;
		char min_ch = 'a'; // 97
		
		// ���� ���� ������ ���� ���� ���ĺ� ã��. 
		for (int i = s_idx; i < e_idx; i++) {
			if (visited[i] == 1) continue; // �湮�� ���� �н�.
			if (min_ch > str[i]) {
				min_ch = str[i];
				min_idx = i;
			}
		}

		if (min_ch != 'a') {
			res.push_back({min_idx, string(1, min_ch)});
			sort(res.begin(), res.end()); // ����. (��ó�� �Է¹��� ���ڿ��� idx�� ���� �����߱⿡ �������ش�.)
			string tmp;
			for (pair<int,string> it : res) {
				tmp += it.second;
			}
			visited[min_idx] = 1;	// �湮ó��.
			res_str.push_back(tmp); // res�� �ϼ��� ���ڿ� �߰�.
			go(min_idx, e_idx);	
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> str;
	
	str_len = str.length();
	go(0, str_len); // ZOAC ��� ���� ���ڿ� �����ϱ�. 
	for (string it : res_str) cout << it << "\n"; // ����ϱ�

	return 0;
}
