// https://www.acmicpc.net/problem/1202

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

ll n = 0, k = 0, boseok_weight = 0, boseok_price = 0, bag_weight = 0, res = 0;
vector<pair<ll, ll>> boseok;
vector<int> bag;
queue<int> price;
stack<int> bag_price_stk;

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

	// ������ ���� ���Կ� ������ �������� ���� ����. 
	ll bag_idx = 0;
	ll stack_tp = 0;
	for(int i=0;i<n;i++){
		// ������������ Ž���ϸ� ù��° ������ �ִ� ���� ������ ���� ������ �ִ� ���Ը� ������� ���Ѵ�.
		// �̶�, stack �� ����ؼ� ���� ������ ������ ��� ��쿡�� stack�� �ִ´�. 
		// stack �� Ȱ���Ͽ� �ϸ�, ���� ������ ä��� ����, �ι����� ��� ������ ������ �� �� �ִ�.
		if (bag_price_stk.size() == 0) {
			stack_tp = 0;
		}
		else if (bag_price_stk.size() > 0) {
			stack_tp = bag_price_stk.top();
		}

		if (bag_idx == k) break;
		// {����, ����}
		if (boseok[i].first < bag[bag_idx]) {
			// ���Ե� �����ϸ� ������ ���� stack �ֻ��� ���� ��θ� stack�� �߰�. 
			if (stack_tp < boseok[i].second) bag_price_stk.push(boseok[i].second);
		}
		else if(boseok[i].first == bag[bag_idx]) {
			if (boseok[i].second >= stack_tp) {
				res += boseok[i].second;
			}
			else {
				res += stack_tp; // stack �� ���� �ִ� ���� �����ְ� 
				if (bag_price_stk.size()) bag_price_stk.pop(); // �� �� ���ð� �������ֱ�. 
				if(bag_price_stk.size() && bag_price_stk.top() < boseok[i].second) bag_price_stk.push(boseok[i].second);
			}
			bag_idx++;
		}
		else if (boseok[i].first > bag[bag_idx]) {
			res += stack_tp; // stack �� ���� �ִ� ���� �����ְ� 
			if(bag_price_stk.size()) bag_price_stk.pop(); // �� �� ���ð� �������ֱ�. 
			if (bag_price_stk.size() && bag_price_stk.top() < boseok[i].second) bag_price_stk.push(boseok[i].second);
			
			bag_idx++;
		}

	}
	
	if (bag_idx != k) {
		res += stack_tp;
	}
	if (res == 0 && bag_price_stk.size()) {
		res += bag_price_stk.top();
	}
	cout << res << "\n";
	return 0;
}
/*
2 1
6 6
6 6
5

1 1
1 65
2
*/