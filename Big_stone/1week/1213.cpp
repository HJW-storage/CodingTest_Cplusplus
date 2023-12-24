// https://www.acmicpc.net/problem/1213

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string eng_name, result, reverse_cpy;
int name_cnt[26] = { 0, };	// ���ĺ��� 26��. 
char ins_char;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> eng_name;
	for (char name : eng_name) {
		name_cnt[name - 65]++;	// A : 65
	}

	// name_cnt[] ������ Ȧ�� �� ���� ���� 1���� �����ؾ��Ѵ�.
	int haulsu_cnt = 0;	// Ȧ�� ���� �ľ��ؼ� �����ϴ� ����.
	int haulsu_idx = 1004; // �ʱ� ���� ������ ū������ ����.
	for (int i = 0; i < 26; i++) {
		if (name_cnt[i] % 2 != 0) {
			haulsu_cnt++;	// Ȧ�� ����.
			haulsu_idx = i;
			if (haulsu_cnt > 1) { break; }	// Ȧ�� ������ 2�̻��̸� ��� ����.
			else { ; }
		}
	}
	
	// ���� ���
	if (haulsu_cnt > 1) {
		cout << "I'm Sorry Hansoo" << "\n";
		return 0;
	}
	else {
		// Ȧ�� ������ �ϳ� �ִ� ��� ���ڿ� �߰��� ����������Ѵ�. 
		if (haulsu_idx <= 25) {
			ins_char = char(haulsu_idx + 65);
			name_cnt[haulsu_idx]--;
		}
		
		// ��� ¦�� ������ ��� ���ݾ� string ����. 
		for (int i = 0; i < 26; i++) {
			if((name_cnt[i] != 0) && (name_cnt[i] % 2 == 0)){
				int half = name_cnt[i] / 2;
				while (half) {
					result += char(i + 65);
					half--;
					name_cnt[i]--;
				}
			}
		}
	}
	
	// reverse_cpy �ʱ�ȭ
	
	reverse_cpy = result; // string ������ ���Կ�����('=')�� �⺻������ ��������� ����ȴ�. 

	//// copy() �Լ� ������� ���� ���縦 ������ �� �ִ�.
	//for (size_t i = 0; i < result.size(); i++) {
	//	reverse_cpy += "a";
	//}
	//copy(result.begin(), result.end(), reverse_cpy.begin());
	
	reverse(reverse_cpy.begin(), reverse_cpy.end());

	if (haulsu_idx <= 25) {
		result += char(ins_char);
	}

	result += reverse_cpy;
	cout << result << "\n";

	return 0;
}