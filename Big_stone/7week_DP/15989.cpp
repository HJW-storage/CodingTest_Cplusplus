// https://www.acmicpc.net/problem/15989
#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

ll n = 0, t = 0, res = 0;
// ����Ž�� �ð��ʰ�... DP�� �̿�����. 
//void solve(ll here, ll sum) {
//	// ���� ���
//	if (sum == n) {
//		res++;
//		return;
//	}
//	else if (sum > n) {
//		return;
//	}
//
//	// ����
//	// ���� ������� ������ ������� �ʱ⿡, ��� ��쿡 1,2,3���� ���� �ʴ´�.
//	// �ߺ��� �����ؾ� �Ѵ�.
//	if (here == 0) {	// �ʱ� ó�� ���� 0�� 1,2,3���� �� �ѷ��ش�.
//		solve(1, sum + 1);
//		solve(2, sum + 2);
//		solve(3, sum + 3);
//	}
//	else if (here == 1) {
//		solve(1, sum + 1);
//		solve(2, sum + 2);
//		solve(3, sum + 3);
//	}
//	else if (here == 2) {
//		solve(2, sum + 2);
//		solve(3, sum + 3);
//	}
//	else if (here == 3) {
//		solve(3, sum + 3);
//	}
//	return;
//}

ll dp[10004] = { 0, };
void DP() {
	// �������
	dp[0] = 1;

	// �޸����̼�
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 10000; j++) {
			if(j-i >= 0) dp[j] += dp[j - i];
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	DP(); // DP�� ���� �޸����̼� ����. 

	for (ll i = 0; i < t; i++) {
		cin >> n;
		// ����Ž�� ------------------
		//res = 0; // �ʱ�ȭ
		//solve(0, 0);
		//cout << "��� : " << res << "\n";
		// ����Ž�� ------------------

		// DP()
		cout << dp[n] << "\n";
		//cout << "��� : " << dp[n] << "\n";
	}

	return 0;
}