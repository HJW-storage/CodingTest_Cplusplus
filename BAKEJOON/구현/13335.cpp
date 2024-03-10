// https://www.acmicpc.net/problem/13335
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <deque>
using namespace std;

// n : Ʈ���� ��, w : �ٸ� ����, L : �ִ� ����
int n = 0, w = 0, L = 0, truck_pass[1004] = { 0, }, truck_cnt = 0, truck_weight = 0, res_time = 0;
queue<pair<int, int>> q; // �ٸ��� ����Ϸ��� ��ٸ��� ���� ��⿭. 
deque<pair<int, int>> DQ; // �ٸ� ���� �ִ� ������.

int main(void) {
	cin >> n >> w >> L;
	int weight = 0;
	for (int i = 0; i < n; i++) {
		cin >> weight;
		q.push({ i, weight }); // {�ε���, Ʈ�� ����}
	}

	int idx = 0, wei = 0;
	while (q.size() != 0) {
		tie(idx, wei) = q.front();

		if ((truck_cnt + 1 <= w) && (truck_weight + wei <= L)) {
			truck_cnt += 1;
			truck_weight += wei;
			q.pop(); // Ʈ�� ��⿭���� �ٸ����� �ø��� �ǹ�.
			DQ.push_back({ idx, wei }); // �ٸ� �� Ʈ������ ���� ����.
		}

		for (pair<int, int> it : DQ) {
			truck_pass[it.first]++; // �ٸ� �� �������� �ð��� ���� ��ĭ�� �����̴� ���� ǥ��
			if (truck_pass[it.first] >= w) {
				DQ.pop_front();
				truck_cnt -= 1;
				truck_weight -= it.second;
			}
		}

		res_time++;
	}

	res_time = res_time + w;

	cout << res_time << "\n";
	return 0;
}