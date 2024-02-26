// https://www.acmicpc.net/problem/2011
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define mod_n 1'000'000
string pswd;
int dp[5004];

bool check_correct() {
	// �߸��� ��ȣ���� �˻�
	// (1). ù ������ 0�̸� �ȵȴ�.
	// (2). 0�� �������� 2�� �̻� ������ �ȵȴ�. + 10, 20 �̿��� 30,40,50 ...�� ������ �ȵȴ�.
	if (pswd[0] == '0') return false; // (1)
	char prev_it = pswd[0];
	int str_len = pswd.length();
	for (int i = 1; i < str_len;i++) {
		if(pswd[i] == '0'){	// (2)
			if (!(prev_it == '1' || prev_it == '2')) {
				return false;
			}
		}
		prev_it = pswd[i];
	}
	return true;
}
int solve_dp() {
	int n = pswd.length();

	// �������
	dp[0] = 1;
	string t_str;
	t_str += pswd[0];
	t_str += pswd[1];
	if (stoi(t_str) <= 26) {					// input : 210  -> res : 1 �� ��� ó��.
		if (stoi(t_str) == 10 || stoi(t_str) == 20 || (n >=3 && pswd[2] == '0')) {
			dp[1] = 1;
		}
		else {
			dp[1] = 2;
		}
	}
	else dp[1] = 1;

	// �޸����̼�, ���� ����
	string prev_ch = string(1, pswd[1]);
	for (int i = 2; i < n; i++) {
		prev_ch += pswd[i];
		if (stoi(prev_ch) <= 26) {												// input : 210  -> res : 1 �� ��� ó��.
			if (stoi(prev_ch) < 10 || stoi(prev_ch) == 10 || stoi(prev_ch) == 20 || (i < n-1 && pswd[i+1] == '0')) {
				dp[i] = dp[i - 1] % mod_n;
			}
			else {
				dp[i] = (dp[i - 1] % mod_n + dp[i - 2] % mod_n) % mod_n;
			}
		}
		else {
			dp[i] = dp[i - 1] % mod_n;
		}
		prev_ch.erase(prev_ch.begin());	// �� �� �����.
	}
	return dp[n-1];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> pswd;
	if (check_correct()) cout << solve_dp() << "\n";
	else cout << "0" << "\n";

	return 0;
}

// ������ �ݷ�
//
// 0 ��ü�� ���ĺ����� ��ȯ�� �ȵ˴ϴ�.�׷��� 0�տ� ���� �����Ŀ� ���� ��찡 �ٸ��ϴ�.
//
// 0�տ� �ƹ��͵� �ȿ��� ���(��, �Ǿ��ڸ��� 0�� ���) :
//	05, 035, 017 �̷��� 0�� ��� ���� �ص� 0�� ���ĺ����� ��ȯ�� �� �Ǵϱ� 0�� ��� �ž� �մϴ�
//
//	0 �տ� 0�� ���� ��� :
// 0024, 10025, 17200312 ���� ��� 00�� ��� ���� �ص�(�� : 10025 -- > 10 0, 1 00, 1 00) 0�� ���Ƽ� ������ ���ϴ�.��� 0�� ��µž� �մϴ�.
//
// 0�տ� 1�̳� 2�� ���� ��� :
// 10, 20 �� ���ĺ����� ��ȯ�� �ż� ����� ���� ����� �� �� �ֽ��ϴ�.
//
// ���� : 20114 -- > ����: 3 / 1010 -- > ����: 1 / 111012 -- > ����: 4
//
// 0�տ� 3�̳� �� ū ���ڰ� ���� ��� :
// 302�� ��� ���� �ص� 30 2, 3 02, 3 0 2 ���ĺ����� ��ȯ�� �ȵ˴ϴ�.��� 0�� ���.
//
// �ٸ� ���� : 1131212501112122 -- > ����: 0

//�Է�: 20236
//�� : 2
//
//�Է� : 2727
//�� : 1
//
//�Է� : 210
//�� : 1
// 
//�Է� : 230
//�� : 0
//
//�Է� : 2
//�� : 1
//
//�Է� : 0
//�� : 0
//
//�Է� : 012
//�� : 0
//
//�Է� : 19126
//�� : 6
//
//�Է� : 111111111111111111111111111111
//�� : 346269