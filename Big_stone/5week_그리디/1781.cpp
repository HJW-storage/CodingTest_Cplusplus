// https://www.acmicpc.net/problem/1781

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n = 0, deadline = 0, noodle_cnt = 0, res = 0;
vector<pair<int, int>> V;
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		// �Է� : �Ⱓ, ����
		cin >> deadline >> noodle_cnt;
		V.push_back({ deadline, noodle_cnt });
	}

	// �Ⱓ�� �������� �������� ����
	sort(V.begin(), V.end());

	// �ִ밪�� ���Ѵ�. 
	// �켱���� ť�� Ȱ���Ͽ� �ּ�(���� ��)�� �����ϸ� ť���� �ִ븦 ������ �� �ִ� ���� �����.
	priority_queue<int, vector<int>, greater<int>> pq; // ���� ���� �� ���� ����.
	int dl = 1;
	int i = 0;
	while (1) {
		while (i < n && V[i].first <= dl) {
			pq.push(V[i].second);
			i++;
		}
		// ť�� �ִ� ���Ұ� ������� �������� ������ ������� �������� �ּ��� ������ �����Ѵ�.
		if (pq.size() > dl) {
			while (pq.size() != dl) {
				pq.pop(); // ���� ���� ���ܽ�Ų��. 
			}
		}
		if (i >= n) break; // Ż�� ����.
		dl = V[i].first; // ���� ���� ������ update. 
	}
	
	//// �� while���� �Ʒ��� for������ �����ϰ� ó���� �� �ִ�. 
	//// sort ������ �߱⿡ ���� ������ ������ �߰��� �ʿ䰡 ����.  
	//for (int i = 0; i < n; i++) {
	//	pq.push(V[i].second);
	//	if (pq.size() > V[i].first) {
	//		pq.pop();
	//	}
	//}
	
	// �ִ� ���ϱ�.
	while (pq.size()) {
		res += pq.top();
		pq.pop();
	}
	cout << res << "\n";
	return 0;
}