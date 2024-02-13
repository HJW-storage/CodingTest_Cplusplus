// https://www.acmicpc.net/problem/2579

#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;
int cost[304] = { 0, }, dp[304] = { 0, };

int DP() {
	// ���� ���
	dp[0] = 0;
	dp[1] = cost[1];
	dp[2] = cost[1] + cost[2];

	// �޸����̼�, ���� ����
	// n��° ����� 
	// (1). n-3 ��° ��ܿ��� 2ĭ �̵�(n-1) 1ĭ �̵�(n)���� ���� ����
	// (2). n-2 ���� ��ܿ��� 2ĭ �̵�(n)���� ���� ��찡 �ִ�. 
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + cost[i - 1] + cost[i], dp[i - 2] + cost[i]);
	}

	return dp[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	cout << DP() << "\n";

	return 0;
}