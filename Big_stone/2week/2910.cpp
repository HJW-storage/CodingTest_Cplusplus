// https://www.acmicpc.net/problem/2910

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<int, int> mp;
map<int, int> mp_first;
vector<pair<int, int>> vec;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {
		return mp_first[a.first] < mp_first[b.first];
	}
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n = 0, c = 0;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int in_tmp;
		cin >> in_tmp;

		// 1���� ������ ���� map
		if (!mp[in_tmp]) {	// mp[in_tmp] <if �������� ���ϱ� ���� ������ �� ���̴�. map�� ������ �ϴ��� �⺻������ �ʱ�ȭ �ȴ�.> int�� ��� 0����
			mp[in_tmp] = 1;
		}
		else {
			mp[in_tmp]++;
		}

		// 2���� ������ ���� map (��Ģ : ���� ���� ���� ���� ��� -> mp_first�� ���� ���°��� value�� �� �������� ����ȴ�.)
		if (mp_first[in_tmp] == 0) {
			mp_first[in_tmp] = i + 1; // +1 �� ���ִ� ���� : i�� 0���� �����ε� ���̽��� 0���� ����ؾ� �ϴ� ��찡 ���� �� �ֱ⿡ +1�� ���ش�.
		}
	}

	// map�� �ִ� ���� vector�� ����.
	for (auto& it : mp) {
		vec.push_back(it);
	}

	// cmp���� ������ �������� ���� ����.
	sort(vec.begin(), vec.end(), cmp);

	// ���
	for (auto& it : vec) {
		for (int i = 0; i < it.second; i++) {
			cout << it.first << " ";
		}
		//cout << " key : " << it.first << " value : " << it.second << "\n";
	}

	
	return 0;
}