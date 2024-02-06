// https://www.acmicpc.net/problem/1202

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, k = 0, boseok_weight = 0, boseok_price = 0, bag_weight = 0;
ll res = 0;
vector<pair<int, int>> boseok;
vector<int> bag;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	// �Է� �ޱ�
	cin >> n >> k;
	// ���� n �ٿ� ���ļ� ���� ���Կ� ������ �Է�
	for (int i = 0; i < n; i++) {
		cin >> boseok_weight >> boseok_price;
		// ���� ���� �������� ���Ŀ� ������ ���̱⿡ {����, ����} ������ ����.
		boseok.push_back({ boseok_weight, boseok_price });
	}
	// ���� k�ٿ� ���ļ� ������ ���� �� �ִ� �ִ� ���԰� �־�����.
	for (int i = 0; i < k; i++) {
		cin >> bag_weight;
		bag.push_back(bag_weight);
	}

	// sort ���� -> O(nlogn) 
	
	// ������ ���Ը� �������� �������� �����̸鼭, ���� ������ ���� ������ �������� �������� �̴�.
	// �׳� sort �Լ� �⺻�� �ᵵ �����ȴ�. 
	sort(boseok.begin(), boseok.end()); 

	// ���� ���� ��� ���Ը� �������� �������� �����Ѵ�.
	sort(bag.begin(), bag.end());

	priority_queue<int> pq;	// �켱���� ť -> ū ������� �������� �ڵ� ���ĵȴ�.

	// ������ ���� ���Կ� ������ �������� ���� ����. 
	int boseok_idx = 0;
	for (int i = 0; i < k; i++) {
		while (boseok_idx < n && boseok[boseok_idx].first <= bag[i]) {
			pq.push(boseok[boseok_idx].second);
			boseok_idx++;
		}
		if (pq.size()) {
			res += pq.top();
			pq.pop();
		}
	}

	cout << res << "\n";

	return 0;
}

/*
1 1
1 65
2
*/
