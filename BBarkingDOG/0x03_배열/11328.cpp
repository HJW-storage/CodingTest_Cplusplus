// https://www.acmicpc.net/problem/11328

// �� ó�� ������ ��� ����Ǽ��� ����. but, �ִ���� 1000 -> 1000! �ð��ʰ�.
// ���ڵ��� ī�����Ͽ� ��������. 

#include <iostream>
#include <algorithm>

using namespace std;

int first_alpha[26];	// �ҹ��� ���ĺ� a~z : 26��
int second_alpha[26];	// �ҹ��� ���ĺ� a~z : 26��
int test_n = 0;
string first_str, second_str;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> test_n;	// �׽�Ʈ ���̽� ����
	for (int i = 0; i < test_n; i++) {
		bool check_flag = true;
		// �׽�Ʈ ���̽��� �����ϴ� ���̹Ƿ� �ʱ�ȭ ������ �ʿ��ϴ�.
		first_str = "";	// �ʱ�ȭ
		second_str = ""; // �ʱ�ȭ
		fill(&first_alpha[0], &first_alpha[0] + 26, 0); // �ʱ�ȭ
		fill(&second_alpha[0], &second_alpha[0] + 26, 0); // �ʱ�ȭ

		cin >> first_str >> second_str;
		// ���ĺ� ���� ī����
		for (char it : first_str) { first_alpha[it - 'a']++; }
		for (char it : second_str) { second_alpha[it - 'a']++; }

		// ù���� str ��� �ι��� str�� �Ǵ���, �� ī������ �迭�� ������ ���� ���Ѵ�. 
		// ������ ī���� ���� ���ٸ� �����Ѵ�.
		// �߰���, 
		for (int i = 0; i < 26; i++) {
			if (first_alpha[i] == second_alpha[i]) { continue; }
			else { check_flag = false; }
		}

		// ��� ���
		if (check_flag == true) { cout << "Possible" << "\n"; }
		else { cout << "Impossible" << "\n"; }
	}
	return 0;
}