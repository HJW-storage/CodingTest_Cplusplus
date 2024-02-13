// https://www.acmicpc.net/problem/11726

// ������ ��Ģ�� ã���ָ� �ǰŵ��.
// �ѹ��� ����� ��ĭ�� �þ���. �׷� ����� ��ĭ �þ����, ��� �ؾ� �ϴ°��� ���Ͽ� ���� �� ���ô�.
// N��° ����� �������, �켱 N - 1 ��° ��Ͽ��� �� 1�� ŭ ������ �����Ͽ��⿡, N - 1 ��° ��Ͽ� �� �̰Ÿ� �ٿ��ָ� �˴ϴ�.
// �׷� 2ĭ¥���� ��� �ؾ� �ұ�� ? 2ĭ�������� = �̺���� �ٿ��ָ� �˴ϴ�.
// �׷� N ��° ����� ������ ? " N - 1 + N - 2 "�� �ǳ׿�

#include <iostream>
#include <algorithm>
using namespace std;

#define mod_n 10007
int n = 0;
int dp[1004] = { 0, };

int DP() {
	// �������
	dp[1] = 1;
	dp[2] = 2;

	// �޸����̼�, ���� ����
	for (int i = 3; i <= n; i++) {
		// ��ⷯ ���� ��Ģ
		// ���� ���� �������� = �������� ���� ���������� �հ� ����.
		dp[i] = (dp[i - 1] % mod_n + dp[i - 2] % mod_n) % mod_n;
	}
	return dp[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cout << DP() << "\n";
	return 0;
}