// https://www.acmicpc.net/problem/2170

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// �ش� ������ ���� ���� Ǯ�̴� �迭�� �ϳ� �����ؼ� �׾��� ���� 1�� ǥ���ϴ� ���̳�
// 10�ﰳ�� �迭�� �޸� �ʰ��̹Ƿ� �ٸ� ��� ���.

// ���� ��ġ�� �������� �����ؼ� ���� �׾���� �� ��ġ�� ����.
// �߰��� ����� �κ��� �����. ������ġ�� �״��� ��ġ�� �����ϰ� �� ��ġ�� ����. 
vector<pair<int, int>> pos_v;
int n = 0, start_pos = 0, end_pos = 0, res = 0;
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	int tmp_start = 0, tmp_end = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp_start >> tmp_end;
		pos_v.push_back({ tmp_start, tmp_end });
	}

	// ���� ��ġ�� �������� �������� ����
	sort(pos_v.begin(), pos_v.end());
	start_pos = pos_v[0].first;
	end_pos = pos_v[0].second;
	for (int i = 1; i < n; i++) {
		if (pos_v[i].first <= end_pos) {
			if (end_pos >= pos_v[i].second) continue;
			end_pos = pos_v[i].second; // �� ���� ����
		}
		else if (pos_v[i].first > end_pos) {
			res += end_pos - start_pos;
			// ���۰� �� ����
			start_pos = pos_v[i].first;
			end_pos = pos_v[i].second;
		}
	}
	res += end_pos - start_pos;
	cout << res << "\n";
	return 0;
}