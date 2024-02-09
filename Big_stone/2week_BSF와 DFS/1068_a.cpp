// https://www.acmicpc.net/problem/1068
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, delete_node, root, temp;
vector<int> adj[54]; // 54���� ���͸� ���ҷ� ���� �迭�� ����

// �������, Ʈ���� root ������ Ž���ϴ°� ����.
int dfs(int here) {
	int ret = 0;
	int child = 0;
	for (int there : adj[here]) {
		if (there == delete_node) continue;
		ret += dfs(there);
		child++; // there�� �̵��� ���� �ڽ� ��尡 �ִٴ� �ǹ��̹Ƿ� ++ ���ش�.
	}
	if (child == 0) return 1; // ���� for���� �������� ���� ���� �ش� ��� ��ü�� �ڽĳ���� �ǹ��̹Ƿ� return 1 ������.
	// ��������� ���� Ž�� ��, ���� ���� �ִ� �ڽĳ���� ������ 1�� ��ȯ�Ǵ� ���̴�.
	return ret;	// ���� ��� ��ȯ.
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == -1) root = i;
		else adj[temp].push_back(i);
	}
	cin >> delete_node;

	// ���ʿ� ������ dfs�� root�϶��� ��Ȯ�� ���� ������� �ʴ´�.
	// ����, ����ó���� ���� ���̴�. 
	if (delete_node == root) {
		cout << "0" << "\n";
		return 0;
	}
	else {
		cout << dfs(root) << "\n";
	}
}