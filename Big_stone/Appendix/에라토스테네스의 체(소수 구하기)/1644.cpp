// https://www.acmicpc.net/problem/1644

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n = 0, Eratos[4'000'004] = { 0, }, res = 0;
vector<int> eratos_v;

void consist_Eratos() {
	// �� �ε����� �ش��ϴ� ���� ä���ΰ�, 
	for (int i = 1; i <= n; i++) {
		Eratos[i] = i;
	}

	// �Ҽ��� �ƴѰ��� ����� ���� = 0 ���� �־ ǥ��.
	for (int i = 2; i <= n; i++) {
		if (Eratos[i] == 0) continue;
		for (int j = i; j <= n; j += i) {
			if (i == j) continue;
			if (Eratos[j] == 0) continue;
			Eratos[j] = 0;
		}
	}

	// �Ҽ��� �߷��� ���� ����. 
	for (int i = 2; i <= n; i++) {
		if (Eratos[i] == 0) continue;
		eratos_v.push_back(Eratos[i]);
	}

	return;
}

int solve_wayscnt() {
	int way_cnt = 0;
	int sum = 0;

	// ���ӵ� �Ҽ��� ������ ǥ���ϱ�
	int v_size = eratos_v.size();
	queue<int> q;
	for (int i = 0; i < v_size;) {
		if (sum < n) {
			sum += eratos_v[i];
			q.push(eratos_v[i]);
			i++;
		}
		else if (sum > n) {
			while (sum > n) { // sum <= n ���� ������ �Ѵ�.
				if (q.size()) {
					sum -= q.front();
					q.pop();
				}
			}
		}
		//cout << "sum : " << sum << "\n";

		if (sum == n) {
			//cout << "���� �޼�!! -> sum : " << sum << "\n\n";
			way_cnt++;
			// �� ���� �ݺ������� ���� �� ���ؾ� �ϴϱ� �ѹ� ���ش�. 
			if (q.size()) {
				sum -= q.front();
				q.pop();
			}
		}
	}

	// �߰� ���� (�� ���ǿ��� while ���� �ɸ��� �ʴ´�.)
	if (eratos_v[v_size - 1] == n) way_cnt++;

	// ����ó�� (n == 2) �� ���� ���� �ۼ��� �˰��� way_cnt�� 1�� �� �߰��Ǳ⿡
	// ������ n == 2 �϶��� ����ó���� ������. 
	if (n == 2) way_cnt = 1;
	return way_cnt;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	consist_Eratos();
	//for (int it : eratos_v) cout << it << " ";

	if (n == 1) cout << "0" << "\n";
	else cout << solve_wayscnt() << "\n";

	return 0;
}