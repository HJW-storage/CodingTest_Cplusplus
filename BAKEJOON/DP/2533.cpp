// https://www.acmicpc.net/problem/2533

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 1'000'004

int n = 0, res = 0, node_cnt = 0;
vector<int> linked[MAX_N];
int visited[MAX_N];
int dp[MAX_N][2];

void solve_dfs(int node) {
	visited[node] = 1; // �湮 ó��

	// �ʱ�ȭ
	dp[node][0] = 0; // ������ �󸮾���Ͱ� �ƴϸ� �� ���� 0
	dp[node][1] = 1; // ������ �󸮾������ ��� �� ���� 1

	for (int i = 0; i < linked[node].size(); i++) {
		int child_node = linked[node][i];
		if (visited[child_node]) continue;
		solve_dfs(child_node);

		dp[node][0] += dp[child_node][1];
		dp[node][1] += min(dp[child_node][1], dp[child_node][0]);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	// ���Ḯ��Ʈ ����.
	int u = 0, v = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		linked[u].push_back(v);
		linked[v].push_back(u);
	}

	// Ʈ���� Ư���� ����. <- ��ȯ�ϴ� ����� Ʈ���� ������, ��� ������ ������ �Ǿ� ������
	// ���� ��带 ��� ������ ��Ƶ� �������. 
	// ��Ʈ�� ���� ��� �����̴�. 
	solve_dfs(1);
	cout << min(dp[1][0], dp[1][1]) << "\n";
	return 0;
}