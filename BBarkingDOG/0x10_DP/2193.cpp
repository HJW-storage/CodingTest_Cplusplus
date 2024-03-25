// https://www.acmicpc.net/problem/2193

// �ڷ��� int�� �ϸ� Ʋ����. -> ���� 0,1 ��  90�� ������ ���⿡ 2^90���� �ϴ� ��� �ڷ��� �ʰ���.
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll; 
ll n = 0, dp[2][94] = { 0, };

// dp[�ش� ������ ������ ���][idx]
// dp[0][idx] : 0���� ������ ���
// dp[1][idx] : 1���� ������ ���
ll solve_dp() {
	// �ʱ�ȭ
	dp[0][1] = 0; 
	dp[1][1] = 1; 

	// �޸����̼�, ��������
	for(int i=2;i<=n;i++){
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
		dp[1][i] = dp[0][i - 1];
	}
	return (dp[0][n] + dp[1][n]);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cout << solve_dp() << "\n";
	return 0;
}