// https://www.acmicpc.net/problem/10807
#include <iostream>
#include <algorithm>
using namespace std;

int num_cnt[205];

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n = 0, v = 0, tmp = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		if (tmp >= -100 && tmp <= 100) {
			num_cnt[tmp+100]++; // v�� -100 ~ +100 �̹Ƿ� �迭�� 0~200���� �����Ѵ�.
		}
	}
	cin >> v;
	
	cout << num_cnt[v+100] << "\n";

	return 0;
}