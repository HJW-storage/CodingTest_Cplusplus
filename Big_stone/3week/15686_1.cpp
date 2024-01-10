// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n = 0, m = 0, temp = 0, res = 1000000;
vector<pair<int, int>> house_idx;
vector<pair<int, int>> chicken_idx;

int measure_mindis(int row1, int col1, vector<int>& b) {
	int mindis = 100000;
	for (int chicken_it : b) {
		int row2 = chicken_idx[chicken_it].first;
		int col2 = chicken_idx[chicken_it].second;
		mindis = min(mindis, abs(row2 - row1) + abs(col2 - col1));	// ���� �ּҰŸ��� ��ȯ.
		if (mindis == 1) return 1;	// ��Ʈ��ŷ. �ּ� �Ÿ��� 1�̹Ƿ� 1�� ���Դٸ� Ż��.
	}
	return mindis;
}

// ���� ����
void combi(int start, int chicken_n, int r, vector<int>& b) {
	if (b.size() == r) {
		// ���� ����
		// �� �ϳ��� �������� ġŲ������ �Ÿ� �� �ּ� �Ÿ��� ���Ѵ�.
		int dis = 0;
		for (pair<int, int> house_it : house_idx) {
			dis += measure_mindis(house_it.first, house_it.second, b);
		}

		// �ּ� ���� ���ؾ��ϱ⿡ ���� ���� ���� �����Ѵ�. 
		res = min(res, dis);
		return;
	}

	for (int i = start + 1; i < chicken_n; i++) {
		b.push_back(i);
		combi(i, chicken_n, r, b);
		b.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	// ��ǥ ��� ���Ϸ��� 1���� ����.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			if (temp == 2) {
				chicken_idx.push_back({ i, j });
			}
			else if (temp == 1) {
				house_idx.push_back({ i, j });
			}
			else { ; }
		}
	}

	int chicken_n = chicken_idx.size();
	vector<int> v;
	combi(-1, chicken_n, m, v);
	cout << res << "\n";
	return 0;
}