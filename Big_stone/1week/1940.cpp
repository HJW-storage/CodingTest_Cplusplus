// https://www.acmicpc.net/problem/1940

// (1). combi �Լ� �����ؼ� Ǯ���
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int r = 2;
int n, m;
int res = 0;
vector<int> material_num;

void solve(vector<int>& b) {
	// �ε��� ������ �Ѿ�� ��.
	int cmp_n = 0;
	for (int it : b) {
		cmp_n += material_num[it];
	}
	if (cmp_n == m) {
		res++;
	}
}
void combi(int start, int n, vector<int>& v) {
	if (v.size() == r) {
		solve(v);
		return;
	}
	
	for (int i = start + 1;  i < n; i++) {
		v.push_back(i);
		combi(i, n, v);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++) {
		int in_temp = 0;
		cin >> in_temp;
		material_num.push_back(in_temp);
	}

	vector<int> b;
	combi(-1, n, b);

	cout << res << "\n";

	return 0;
}


// (2) �̴� ���� 3�� ������ ���� for ������ ������ �� ����. for������ �����غ���.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, res;
vector<int> material_num;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		int in_tmp;
		cin >> in_tmp;
		material_num.push_back(in_tmp);
	}

	// ���� ������ �о�� �ִ��� �ð��� ���� �� �ִ� ��츦 ����ó���� ó����. 
	if (m > 200000) {
		cout << 0 << "\n";
		return 0;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = material_num[i] + material_num[j];
			if (sum == m) {
				res++;
			}
		}
	}

	cout << res << "\n";

	return 0;
}