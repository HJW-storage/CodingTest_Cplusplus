// https://www.acmicpc.net/problem/14620
// Ǯ�̽ð� : 1�ð� 20�� (���� ���ǿ��� ��� ���԰� �߸� �����ؼ� �ð� ��Ƹ���...) 
// 1. ����Ž������ ���� -> ���� �ִ� combi(64,3)
// 2. ���� ���ǿ��� ���� �״� ������ ����
// 3. res ���Ϳ� ����� �����ϰ� sort()�����ؼ� �ּұ��ϱ�

// �� Ǯ�� �����غ���, �������� ��ſ� �湮ó���� �ؼ� �湮�� ���� �ִ°��� �湮�Ϸ��� �ϸ�
// ���� �����̱⿡ ���ܽ�Ű�� �� ���� ������ ������ �� �Ͱ���. 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n = 0;
int cost[11][11];
vector<int> res;
// (1,1) ~ (n-2, n-2) ������ idx ���� ����. <- ���տ��� ���� 0 ~ (n-2*n-2) -1 �ε����� ����.
vector<pair<int, int>> grid_idx;
const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };

bool check_except(int a_row, int a_col, int b_row, int b_col) {
	// �����ؾ��ϴ� ��� -> �� 3���� ��찡 �ִ�.
	// ���� ����, ���� ���̰� 2���� ���� ���
	// ���� ����, ���� ���̰� 2���� ���� ��� 
	// ��� ���� ���̰� ��� 1�� ���
	if ( (a_col == b_col && abs(a_row - b_row) <= 2) 
		|| (a_row == b_row && abs(a_col - b_col) <= 2)
		|| (abs(a_row - b_row) == 1 && abs(a_col - b_col) == 1)
		){
		return false;
	}
	return true;
}
bool except_combi(vector<int> &v) {
	// ũ��� 3���� �����̹Ƿ�
	int first_row = grid_idx[v[0]].first;  int first_col = grid_idx[v[0]].second;
	int second_row = grid_idx[v[1]].first;  int second_col = grid_idx[v[1]].second;
	int third_row = grid_idx[v[2]].first;  int third_col = grid_idx[v[2]].second;
	
	bool first_flag = true, second_flag = true, third_flag = true;
	// �ϳ��� false �̸� false�� ��ȯ�Ѵ�. 
	first_flag = check_except(first_row, first_col, second_row, second_col);
	second_flag = check_except(second_row, second_col, third_row, third_col);
	third_flag = check_except(third_row, third_col, first_row, first_col);

	if (first_flag == false || second_flag == false || third_flag == false) {
		return false;
	}
	return true;
}
void combi(int start, int n, int r, vector<int> &v) {
	if (v.size() == r) {
		// ���� ����
		// ���� �״� ������ ���ܽ�Ų��. 
		if (except_combi(v)) { // true �� ��츸 ���. 
			int tmp_cost = 0;
			for (int i = 0; i < r; i++) {
				int cur_row = grid_idx[v[i]].first;
				int cur_col = grid_idx[v[i]].second;
				tmp_cost += cost[cur_row][cur_col];
				for (int i = 0; i < 4; i++) {
					int next_row = cur_row + dr[i];
					int next_col = cur_col + dc[i];
					// �ε��� ����� ��찡 ���⿡ ���� �˻���ص� �ȴ�.
					tmp_cost += cost[next_row][next_col];
				}
			}
			res.push_back(tmp_cost);
		}
		return;
	}

	for (int i = start + 1; i < n; i++) {
		v.push_back(i);
		combi(i, n, r, v);
		v.pop_back();
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
			if ((i >= 1 && i <= n - 2) && (j >= 1 && j <= n - 2)) {
				grid_idx.push_back({i, j});
			}
		}
	}

	int combi_n = (n - 2) * (n - 2);
	vector<int> b;
	combi(-1, combi_n, 3, b);
	sort(res.begin(), res.end());
	cout << res[0] << "\n";

	return 0;
}
