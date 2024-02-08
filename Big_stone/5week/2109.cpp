// https://www.acmicpc.net/problem/2109

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n = 0, d = 0, p = 0, res = 0, res1 = 0;
vector<pair<int, int>> schedule;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		schedule.push_back({ d, p });	// �Է� �Ŀ� sort �Լ��� ��¥ ���� ������ ���̱⿡ ��¥�� .first�� �Է¹޴´�.
	}

	// d�� �������� �������� ����
	sort(schedule.begin(), schedule.end());


	// ���� ����
	// �켱���� ť�� �̿��Ѵ�.
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for (int i = 0; i < n; i++) {
		pq.push(schedule[i].second);
		if (pq.size() > schedule[i].first) {
			pq.pop(); // ���� ���� ��������
		}
	}
	while (pq.size()) {
		res += pq.top();
		pq.pop();
	}
	cout << res << "\n";
	return 0;
}
/*
5
20 1
2 1
50 1
30 1
12 1
��� : 50

5
10 1
20 2
30 3
40 4
50 5
��� : 150

7
1 1
2 4
3 4
2 4
1 4
2 4
7 10000
����� : 16
���� ��°� : 15


4
2 1 
4 1
8 2
100 2
����� : 108
���� ��°� : 104
*/