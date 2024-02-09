// https://www.acmicpc.net/problem/1068
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, delete_num;

void solve_leafnode(vector<vector<int>> &vec, int delete_num) {
	if (vec[delete_num].size() == 0) {
		vec[delete_num].push_back(1004); // ���� ��� ������ �ǹ̷� �ڽĳ�带 �߰����ִ� ����� ����Ѵ�.
		// ���� �˻��� vector ũ�Ⱑ 0�� ���� �ڽĳ�� ������ ����ȴ�.
		return;
	}
	else {
		for (auto it : vec[delete_num]) {
			solve_leafnode(vec, it);
		}
	}
	return;
}
int main() {
	cin >> n;
	vector<vector<int>> vec(n);

	for (int i = 0; i < n; i++) {
		int in_tmp;
		cin >> in_tmp;
		if (in_tmp == -1) continue;
		vec[in_tmp].push_back(i);
	}

	cin >> delete_num;
	solve_leafnode(vec, delete_num);

	// ���� ���̽� ó���ϱ� ���� �߰���
	// �Է���  
	// 5
	// -1 0 1 2 3
	// 2 
	// �� �־����� ������ : 1 �̴�. �Ʒ� �κ��� ������ ��� : 0 �̾���.
	// ���� ���ø� �׸����� ���� ǥ���ϸ� �Ʒ�ó�� ���ڷε� Ʈ���̴�.
	// [0]
	//  |
	// [1]
	//  |
	// [2]
	//  |
	// [3]
	//  |
	// [4]
	for (int i = 0; i < n; i++) {
		for (auto it : vec[i]) {
			// ���δ�� pop_back�� �ص� �Ǵ� ������ ���� solve_leafnode���� �̹� ó���� �ٳ��� �ڿ�,
			// pop_back�� �ϸ� vec[i]�� �������� ��� �ϳ��� pop�ǵ� �信 ������ ���� ����. 
			// ��, vec[i]�� 1�� �� ��, �ش� ������� ������� pop ���ָ� �ش� left���� ��� �ִ� ��尡 �Ǹ� 
			// leaf ��尡 �Ǳ⶧���� �ش� ���ǹ��� �߰������. 
			if (it == delete_num) {
				vec[i].pop_back();
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (vec[i].size() == 0) res++;
	}
	cout << res << "\n";
	return 0;
}