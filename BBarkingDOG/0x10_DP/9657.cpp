// https://www.acmicpc.net/problem/9657

// ����Ž�� -> O(3^250) �ð��ʰ�
// dp�� Ǯ��.

#include <iostream>
#include <algorithm>
using namespace std;

#define SangGeun 0
#define Changyoung 1


int n = 0, dp[1004] = { 0, };
void solve_dp() {
	// �� ���(���, â��)�̰� ������ �Ϻ� ���� = ������ �̱�� ������� �����Ѵ�.
	// ����, ������ �������� �߿��ϰ� �ۿ��Ѵ�.
	// -> ����, ����(���)�̰� �ѹ��̶� �̱�� ��찡 ������ ����̰� �̱�ɷ� �����Ѵ�.

	// dp[i]�� �Ǵ� ���� dp[i-1], dp[i-3], dp[i-4] ���� ���� ���
	// dp[] �迭�� �����ϴ� ���� ���� �̰����, ����̿� â���� �߿��� ���� �̱����� ǥ��

	// �ʱ�ȭ
	fill(&dp[0], &dp[0] + 1004, -1);

	// �������
	dp[1] = SangGeun;
	dp[2] = Changyoung;
	dp[3] = SangGeun;
	dp[4] = SangGeun;

	// �޸����̼�, ���� ����
	for (int i = 5; i <= n; i++) {
		int sum = dp[i - 1] + dp[i - 3] + dp[i - 4];
		// ���� dp �迭���� â���̿��� ���� ����� �ᱹ ����̰� ������ �����̸� �������� ���̹Ƿ�
		// â���̿��� ���� ��찡 �Ѱ��� ������ sum > 0 �̱⿡ �ش� dp �迭���� ����̰� �̱� ���̱⿡ ����� �����Ѵ�.
		if (sum > 0) {
			dp[i] = SangGeun;
		}
		else {
			dp[i] = Changyoung;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	solve_dp();
	if (dp[n] == SangGeun) cout << "SK" << "\n";
	else if (dp[n] == Changyoung) cout << "CY" << "\n";
	return 0;
}