// https://www.acmicpc.net/problem/9934

// 1. �湮ó��
// 2. ���� Ž��
// 3. ť

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int k = 0, node_n = 0;
queue<int> node_q, tmp_q;
int visited[1050];	// �ִ� k = 10�� ��, 2^10 = 1024 
int node_arr[1050];
vector<int> res[11];

int multi_n(int a, int b) {
	int tmp_m = 1;
	for (int i = 1; i <= b; i++) {
		tmp_m *= a;
	}
	return tmp_m;
}
void Qclear(queue<int> &q) {
	queue<int> empty;
	swap(q, empty);
}
void solve(int start_idx) {
	int step = start_idx;
	int depth = 2;

	while(depth != k+1){
		step = step - step / 2;

		while (node_q.size()) {
			int cur_idx = node_q.front();
			//cout << "cur_idx : " << cur_idx << "\n";
			node_q.pop();

			int next_idx_left = cur_idx - step;
			int next_idx_right = cur_idx + step;
			for (int it : {next_idx_left, next_idx_right}) {
				if (it >= 0 && it < node_n) {
					if (visited[it] == 0) {
						visited[it] = 1; // �湮ó��
						res[depth].push_back(node_arr[it]);	// Ʈ�� ����. 
						tmp_q.push(it);
					}
				}
			}

			// 2���� ��츦 for������ �ϳ��� ������ ���� ���ʰ� ����. 
			//if (next_idx_left >= 0 && next_idx_left < node_n) {
			//	if (visited[next_idx_left] == 0) {
			//		visited[next_idx_left] = 1; // �湮ó��
			//		res[depth].push_back(node_arr[next_idx_left]);	// Ʈ�� ����. 
			//		//cout << node_arr[next_idx_left] << " �߰�_left\n";
			//		tmp_q.push(next_idx_left);
			//	}
			//}
			//if (next_idx_right >= 0 && next_idx_right < node_n) {
			//	if (visited[next_idx_right] == 0) {
			//		visited[next_idx_right] = 1; // �湮ó��
			//		res[depth].push_back(node_arr[next_idx_right]);	// Ʈ�� ����. 
			//		//cout << node_arr[next_idx_right] << " �߰�_right\n";
			//		tmp_q.push(next_idx_right);
			//	}
			//}
		}
		node_q = tmp_q;
		Qclear(tmp_q); // tmp_q �ʱ�ȭ. 
		depth++;
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	node_n = multi_n(2, k) - 1;
	//cout << "node_n : " << node_n << "\n";
	for (int i = 0; i < node_n; i++) {
		cin >> node_arr[i];
	}
	
	int start = node_n / 2;	// ��Ʈ ��� ����.
	node_q.push(start);
	visited[start] = 1; // ���� ��Ʈ ��� �湮ó��
	res[1].push_back(node_arr[start]);	// Ʈ�� ����. 

	solve(start);

	for (int i = 1; i <= k; i++) {
		for (int it : res[i]) {
			cout << it << " ";
		}
		cout << "\n";
	}

	return 0;
}