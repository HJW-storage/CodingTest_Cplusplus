#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int name_cnt[200] = { 0, }; // �빮�� A : 65 ~ Z : 65 + 25
string eng_name, result;
char mid;
int flag = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> eng_name;
	for (char name : eng_name) {
		name_cnt[name]++;
	}

	for (int i = 'Z'; i >= 'A'; i--) {
		if(name_cnt[i]){
			// Ȧ���̸� : �� Ȧ���� 2�� �̻��̸� ����. 
			if (name_cnt[i] & 1) {
				mid = char(i);
				flag++;
				name_cnt[i]--;
			}
			if (flag > 1) {
				break;	// �ش� break �� if ~ else ���ǹ��� Ż���ϴ� ���̴�. 
			}
			// ¦���� ��,
			for(int j = 0; j < name_cnt[i]; j += 2){
				// �յڷ� ���̱�
				result = result + char(i);
				result = char(i) + result;
			}
		}
	}

	if (flag > 1) cout << "I'm Sorry Hansoo" << "\n";
	else if (flag == 1) {
		result.insert(result.begin() + result.size() / 2, mid);
		cout << result << "\n";
	}
	else {
		cout << result << "\n";
	}

	return 0;
}