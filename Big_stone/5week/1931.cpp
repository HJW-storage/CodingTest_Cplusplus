// https://www.acmicpc.net/problem/1931
// �׸��� ����.. ������ Ȱ���Ͽ� ������ �ظ� ã��. 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
int n = 0, res = 0;
int check_arr[100004];
ll start_t = 0, end_t = 0;
vector<pair<int, int>> time_schedule;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start_t >> end_t;
		// ���� �ð��� �������� ���� �Է� �ް�. 
		// ���߿� sort �Լ��� �ϸ� �⺻������ ù���� pair ������ �����Ѵ�.
		time_schedule.push_back({ end_t, start_t }); 
	}

	sort(time_schedule.begin(), time_schedule.end());
	
	// ���� ����
	ll prev_end_time = -1;
	for (pair<int, int> it : time_schedule) {
		// pair<int ,int> => {end_time, start_time} �� �������� �����. 
		if (prev_end_time <= it.second) {
			
			//�ߺ��ؼ� ȸ�ǰ� �ִ��� �Ѵ� ���ÿ� ����ȴٰ� �����ϴ� ���� �̻������� �̷��� �ؾ� �½��ϴٰ� �����׿�!
			/*
			3
			4 4
			4 4
			1 4
			��� : 3
			*/
			res++;
			prev_end_time = it.first;
		}
	}

	cout << res << "\n";
	return 0;
}