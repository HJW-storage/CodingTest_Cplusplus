// https://www.acmicpc.net/problem/1707

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int K = 0, V = 0, E = 0;
bool flag = true;
int visited[20004]; // �湮ó��, �˻�

void solve_dfs(int u, int cur_color, vector<vector<int>> & linked) {
	visited[u] = cur_color; // �湮ó��
	
	for (int i = 0; i < linked[u].size(); i++) {
		if (visited[linked[u][i]] == -1) {
			//solve_dfs(linked[u][i], cur_color ^= 1, linked);
			// ���� ó�� ���� cur_color ���� ���ؼ� ���� for���� ������ �ش�... 
			// ���� ��û�ߵ�.... ��Ʈ ���� ���ڴٰ� ��ġ�ٰ� .... 
			solve_dfs(linked[u][i], cur_color ^ 1 , linked);
		}
		/*else if (visited[liked[u][i]] == (cur_color ^= 1)) {
			continue;
		}*/
		else if (visited[linked[u][i]] == cur_color) {
			flag = false;
			return;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> K;
	while (K--) {
		cin >> V >> E;
		
		flag = true; // �ʱ�ȭ
		fill(&visited[0], &visited[0] + 20004, -1); // �ʱ�ȭ
		vector<vector<int>> linked(V+1); // ���Ḯ��Ʈ ����, �ʱ�ȭ.
		
		int u = 0, v = 0;
		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			linked[u].push_back(v);
			linked[v].push_back(u);
		}
		for (int i = 1; i <= V; i++) {
			if (visited[i] == -1) {
				solve_dfs(i, 0, linked);
			}
		}
		
		if (flag == true) cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;
}